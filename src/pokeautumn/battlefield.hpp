#pragma once

#include <map>
#include <vector>
#include <memory>


namespace pokeautumn {
  class EngineParty;
  class EnginePokemon;
  class BattleField;

  class BattleFieldEventListener {
    friend class BattleField;
  protected:
    virtual void SetBattleField(std::shared_ptr<BattleField> battleField) = 0;

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

  class BattleField {
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
    virtual unsigned GetTeam(unsigned slot) const {
      // Generally there's two teams, so this is a good default
      return slot * 2 / parties.size();
    }

  public: // Turn Management
    unsigned GetTurn() const { return turn; }
    virtual bool SetMove(unsigned slot, BattleFieldMove move) { moves[slot] = move; return true; }
    virtual bool HasMoveReady(unsigned slot) const { return moves.find(slot) != moves.end(); }
    virtual BattleFieldMove GetMove(unsigned slot) const { return moves.at(slot); }

  protected:
    unsigned turn = 0;
    std::map<unsigned, BattleFieldMove> moves;
    std::vector<std::shared_ptr<BattleFieldEventListener>> listeners;

    std::vector<std::shared_ptr<EngineParty>> parties;
    std::map<unsigned, std::shared_ptr<EnginePokemon>> activePokemon;
  };
}
