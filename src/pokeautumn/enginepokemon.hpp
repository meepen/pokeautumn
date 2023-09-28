#pragma once

#include <array>
#include <memory>

#include "pokemon/data/stattype.hpp"
#include "pokemon/data/type.hpp"

namespace pokeautumn {
  class EngineMove;

  class EnginePokemon {
  public:
    virtual ~EnginePokemon() = default;
  public:
    // This returns the value processed by the engine BEFORE status effects are applied.
    virtual unsigned GetBaseStatValue(StatType stat) const = 0;
    // This returns the value processed by the engine AFTER status effects are applied.
    // This is also the current HP value.
    virtual unsigned GetStatValue(StatType stat) const = 0;
    virtual const std::array<const EngineMove *, 4> GetMoves() const = 0;
    virtual std::array<Type, 2> GetTypes() const = 0;

  public:
    virtual void SetHealth(unsigned health) = 0;
    unsigned GetHealth() { return GetStatValue(StatType::HP); }
    unsigned GetMaxHealth() { return GetBaseStatValue(StatType::HP); }

  public: // Events
    virtual void OnDamageTaken(unsigned damage) {
      if (damage > GetHealth()) {
        SetHealth(0);
      } else {
        SetHealth(GetHealth() - damage);
      }
    }
    virtual void OnSentOut(std::shared_ptr<EnginePokemon> previous, const EngineMove *move) { }
    virtual void OnStatStageChange(StatType stat, int amount) { }

  public:
    virtual bool IsImmuneTo(const EngineMove &move) const = 0;
    virtual unsigned CalculateDamage(const EngineMove &move, const EnginePokemon &target) const = 0;
  };
}