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
    unsigned GetStatValue(StatType stat) const override;
    const std::array<const EngineMove *, 4> GetMoves() const override { return moves; }
    std::array<Type, 2> GetTypes() const override;

    void SetHealth(unsigned health) override;

    unsigned CalculateDamage(const EngineMove &move, const EnginePokemon &target) const;
    bool IsImmuneTo(const EngineMove &move) const override;

  public: // Events
    void OnSentOut(std::shared_ptr<EnginePokemon> previous, const EngineMove *move) override;

  private:
    Pokemon pokemon;
    const SpeciesData *speciesData;
    unsigned currentHealth;
    std::array<const EngineMove *, 4> moves;
    std::array<int, static_cast<unsigned>(StatType::GEN1_COUNT)> statStages = { 0 };
  };
}