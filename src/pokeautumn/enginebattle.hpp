#pragma once

#include <map>
#include <vector>
#include <memory>
#include "pokemon/data/move.hpp"


namespace pokeautumn {
  class EngineParty;
  class EnginePokemon;
  class EngineBattle;

  enum class BattleType {
    SINGLES,
    DOUBLES_1V1,
    DOUBLES_1V2,
    DOUBLES_2V2,
    TRIPLES_1V1,
    TRIPLES_1V3,
    TRIPLES_3V3,
  };

  class BattleEventListener {
    friend class EngineBattle;
  protected:
    virtual void SetBattleField(std::shared_ptr<EngineBattle> battleField) = 0;

  public: // Events
    // Called when a turn starts and moves are to be selected
    virtual void OnTurnStart() = 0;
    // Called once all moves have been selected and the turn is about to process
    virtual void OnMovePhase() = 0;
    // Called when a turn ends and the next turn is about to start
    virtual void OnTurnEnd() = 0;
    // Called when a pokemon is switched in
    virtual void OnSwitchIn(unsigned slot) = 0;
    // Called when a pokemon is switched out
    virtual void OnSwitchOut(unsigned slot) = 0;
    // Called when a pokemon faints
    virtual void OnFaint(unsigned slot) = 0;
  };

  struct BattleFieldMove {
    Move move;
    unsigned target;
  };

  class EngineBattle {
  public:
    EngineBattle(std::vector<std::shared_ptr<EngineParty>> parties) : parties(parties) {}

  public:
    virtual const std::vector<std::shared_ptr<EngineParty>> GetParties() const {
      return parties;
    }
    virtual std::map<unsigned, std::shared_ptr<EnginePokemon>> GetActivePokemon() const {
      return activePokemon;
    }

  public: // State Management
    virtual void SetActivePokemon(unsigned slot, std::shared_ptr<EnginePokemon> pokemon) {
      activePokemon[slot] = pokemon;
    }
    virtual std::shared_ptr<EnginePokemon> GetActivePokemon(unsigned slot) const {
      return activePokemon.at(slot);
    }
    virtual unsigned GetSlot(std::shared_ptr<EnginePokemon> pokemon) const {
      for (auto &pair : activePokemon) {
        if (pair.second == pokemon) {
          return pair.first;
        }
      }
      return -1;
    }
    virtual unsigned GetSlot(EnginePokemon &pokemon) const {
      for (auto &pair : activePokemon) {
        if (pair.second.get() == &pokemon) {
          return pair.first;
        }
      }
      return -1;
    }
    virtual unsigned GetTeam(unsigned slot) const {
      // Generally there's two teams, so this is a good default
      return slot * 2 / (parties.size() + 1);
    }

  public: // Turn Management
    unsigned GetTurn() const { return turn; }
    virtual bool SetMove(unsigned slot, BattleFieldMove move) { moves[slot] = move; return true; }
    virtual bool HasMoveReady(unsigned slot) const { return moves.find(slot) != moves.end(); }
    virtual BattleFieldMove GetMove(unsigned slot) const { return moves.at(slot); }

  public: // Pokemon Management
    virtual void OnFaint(EnginePokemon &pokemon) {
      auto slot = GetSlot(pokemon);
      for (auto &listener : listeners) {
        listener->OnFaint(slot);
      }
    }

  protected:
    unsigned turn = 0;
    std::map<unsigned, BattleFieldMove> moves;
    std::vector<std::shared_ptr<BattleEventListener>> listeners;

    std::vector<std::shared_ptr<EngineParty>> parties;
    std::map<unsigned, std::shared_ptr<EnginePokemon>> activePokemon;
  };
}
