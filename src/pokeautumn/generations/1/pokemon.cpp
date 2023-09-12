#include "pokemon.hpp"
#include "pokemon/pokemon.hpp"
#include <cmath>

using namespace pokeautumn;
using namespace pokeautumn::Generation1;

Generation1Pokemon::Generation1Pokemon(Pokemon pokemon) : pokemon(pokemon) {
  baseStats = &Generation1::pokemonData.at(pokemon.species);
  currentHealth = GetBaseStatValue(StatType::HP);
}

// https://www.smogon.com/ingame/guides/rby_gsc_stats
unsigned Generation1Pokemon::GetBaseStatValue(StatType stat) const {
  /* 
  STAT = int(((baseStat + individualValue)*2+StatPoint)*Level/100)+baseStatValue

  where baseStatValue = Level + 10 for HP
  baseStatValue = 5 for any other stat.

  And statPoint = int((SQRT(baseStatExperience-1)+1)/4)
  */
  unsigned baseStatValue;
  switch (stat) {
    case StatType::HP:
      baseStatValue = pokemon.level + 10;
      break;
    default:
      baseStatValue = 5;
      break;
  }

  unsigned baseStatExperience, individualValue, baseStat;
  switch (stat) {
    case StatType::HP:
      baseStatExperience = pokemon.evs.hp;
      individualValue = 
        (pokemon.ivs.attack & 1) * 8 +
        (pokemon.ivs.defense & 1) * 4 +
        (pokemon.ivs.speed & 1) * 2 +
        (pokemon.ivs.special_attack & 1);
      baseStat = baseStats->hp;
      
      break;
    case StatType::ATTACK:
      baseStatExperience = pokemon.evs.attack;
      individualValue = pokemon.ivs.attack;
      baseStat = baseStats->attack;
      break;
    case StatType::DEFENSE:
      baseStatExperience = pokemon.evs.defense;
      individualValue = pokemon.ivs.defense;
      baseStat = baseStats->defense;
      break;
    case StatType::SPEED:
      baseStatExperience = pokemon.evs.speed;
      individualValue = pokemon.ivs.speed;
      baseStat = baseStats->speed;
      break;
    case StatType::SPECIAL_ATTACK:
    case StatType::SPECIAL_DEFENSE:
      baseStatExperience = pokemon.evs.special_attack;
      individualValue = pokemon.ivs.special_attack;
      baseStat = baseStats->special;
      break;
  }

  unsigned statPoint = (std::sqrt(baseStatExperience == 0 ? 0 : baseStatExperience - 1) + 1) / 4;
  return (((baseStat + individualValue) * 2 + statPoint) * pokemon.level / 100) + baseStatValue;
}

unsigned Generation1Pokemon::GetStatValue(StatType stat) {
  // TODO: in gen 1, badges affect stats (?!)
  switch (stat) {
    case StatType::HP:
      return currentHealth;
    default:
      return GetBaseStatValue(stat);
  }
}

void Generation1Pokemon::SetHealth(unsigned health) {
  currentHealth = health;
}
