#pragma once

#include <array>

#include "pokemon/data/stattype.hpp"
#include "pokemon/data/type.hpp"

namespace pokeautumn {
  class EnginePokemon {
  public:
    virtual ~EnginePokemon() = default;
  public:
    // This returns the value processed by the engine BEFORE status effects are applied.
    virtual unsigned GetBaseStatValue(StatType stat) const = 0;
    // This returns the value processed by the engine AFTER status effects are applied.
    // This is also the current HP value.
    virtual unsigned GetStatValue(StatType stat) = 0;
    virtual std::array<Type, 2> GetTypes() const = 0;

    virtual void SetHealth(unsigned health) = 0;
    unsigned GetHealth() { return GetStatValue(StatType::HP); }
    unsigned GetMaxHealth() { return GetBaseStatValue(StatType::HP); }
  };
}