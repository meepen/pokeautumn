#include <cmath>

#include "pokemon.hpp"
#include "pokemon/pokemon.hpp"
#include "moves.hpp"
#include "types.hpp"

using namespace pokeautumn;
using namespace pokeautumn::Generation1;

Generation1Pokemon::Generation1Pokemon(Pokemon pokemon) : pokemon(pokemon) {
  speciesData = &Generation1::pokemonData.at(pokemon.species);
  currentHealth = GetBaseStatValue(StatType::HP);
  moves = {
    Generation1::moveList.at(pokemon.moves[0]),
    Generation1::moveList.at(pokemon.moves[1]),
    Generation1::moveList.at(pokemon.moves[2]),
    Generation1::moveList.at(pokemon.moves[3])
  };
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
      baseStat = speciesData->baseStats.hp;
      
      break;
    case StatType::ATTACK:
      baseStatExperience = pokemon.evs.attack;
      individualValue = pokemon.ivs.attack;
      baseStat = speciesData->baseStats.attack;
      break;
    case StatType::DEFENSE:
      baseStatExperience = pokemon.evs.defense;
      individualValue = pokemon.ivs.defense;
      baseStat = speciesData->baseStats.defense;
      break;
    case StatType::SPEED:
      baseStatExperience = pokemon.evs.speed;
      individualValue = pokemon.ivs.speed;
      baseStat = speciesData->baseStats.speed;
      break;
    case StatType::SPECIAL_ATTACK:
    case StatType::SPECIAL_DEFENSE:
      baseStatExperience = pokemon.evs.special_attack;
      individualValue = pokemon.ivs.special_attack;
      baseStat = speciesData->baseStats.special_attack;
      break;
  }

  unsigned statPoint = (std::sqrt(baseStatExperience == 0 ? 0 : baseStatExperience - 1) + 1) / 4;
  return (((baseStat + individualValue) * 2 + statPoint) * pokemon.level / 100) + baseStatValue;
}

unsigned Generation1Pokemon::GetStatValue(StatType stat) const {
  switch (stat) {
    case StatType::HP:
      return currentHealth;
    case StatType::SPECIAL_DEFENSE:
      stat = StatType::SPECIAL;
    default:
      return GetBaseStatValue(stat)
        * (2 + std::max(0, statStages[static_cast<unsigned>(stat)]))
        / (2 + std::max(0, -statStages[static_cast<unsigned>(stat)]));
  }
}

void Generation1Pokemon::SetHealth(unsigned health) {
  currentHealth = health;
}

std::array<Type, 2> Generation1Pokemon::GetTypes() const {
  return speciesData->types;
}

unsigned Generation1Pokemon::CalculateDamage(const EngineMove &move, const EnginePokemon &target) const {
  // https://bulbapedia.bulbagarden.net/wiki/Damage
  // Damage = ((2 * level * critical / 5 + 2) * power * attack / defense / 50 + 2) * STAB * Type1 * Type2 * random / 255
  // STAB = 1.5 if move type is the same as the pokemon's type
  // Type1 and Type2 are the effectiveness of the move against the pokemon's types
  // critical = 2 if critical hit, 1 otherwise
  // random = random number between 217 and 255 inclusive
  // attack = attack stat if physical move, special stat if special move
  // defense = defense stat if physical move, special stat if special move
  // power = move power
  // level = pokemon user's level

  auto attack = move.IsPhysical()
    ? GetStatValue(StatType::ATTACK)
    : GetStatValue(StatType::SPECIAL);
  auto defense = move.IsPhysical()
    ? target.GetStatValue(StatType::DEFENSE)
    : target.GetStatValue(StatType::SPECIAL);
  auto power = move.Power();
  auto level = pokemon.level;
  
  // TODO: critical (1.5 if move is critical)
  unsigned critical = 1;

  auto damage = ((2 * level * critical / 5 + 2) * power * attack / defense / 50 + 2);

  if (move.GetType() == GetTypes()[0] || move.GetType() == GetTypes()[1]) {
    damage = damage * 3 / 2;
  }

  damage = GetTypeEffectiveness(move.GetType(), target.GetTypes()) * damage;

  // TODO: random
  unsigned random = 255; // 217-255
  damage = damage * random / 255;
  
  return damage;
}

void Generation1Pokemon::OnSentOut(std::shared_ptr<EnginePokemon> previous, const EngineMove *move) {
  // if (move == nullptr || move->GetMove() != Move::MOVE_BATON_PASS) {
  for (auto &statStage : statStages) {
    statStage = 0;
  }
  // }
}

bool Generation1Pokemon::IsImmuneTo(const EngineMove &move) const {
  return GetTypeEffectiveness(move.GetType(), GetTypes()).numerator == 0;
}
