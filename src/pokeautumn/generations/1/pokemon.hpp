#pragma once

#include "pokeautumn/enginepokemon.hpp"
#include "pokemonstats.hpp"

#include "pokemon/data/stattype.hpp"
#include "pokemon/data/species.hpp"
#include "pokemon/pokemon.hpp"

namespace pokeautumn::Generation1 {
  class Generation1Pokemon : public EnginePokemon {
  public:
    Generation1Pokemon(Pokemon pokemon);

  public:
    unsigned GetBaseStatValue(StatType stat) const override;
    unsigned GetStatValue(StatType stat) override;
    std::array<Type, 2> GetTypes() const override;

    void SetHealth(unsigned health) override;

  private:
    Pokemon pokemon;
    const SpeciesData *speciesData;
    unsigned currentHealth;
  };
}