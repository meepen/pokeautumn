#include "types.hpp"

using namespace pokeautumn;
using namespace pokeautumn::Generation1;

// indexed with attack type, then target type
std::map<const Type, std::map<const Type, const TypeEffectiveness>> typeMap = {
  {
    Type::NORMAL,
    {
      { Type::ROCK, { 1, 2 } },
      { Type::GHOST, { 0, 2 } },
    },
  },
  {
    Type::FIRE,
    {
      { Type::FIRE, { 1, 2 } },
      { Type::WATER, { 1, 2 } },
      { Type::GRASS, { 2, 1 } },
      { Type::ICE, { 2, 1 } },
      { Type::BUG, { 2, 1 } },
      { Type::ROCK, { 1, 2 } },
      { Type::DRAGON, { 1, 2 } },
    },
  },
  {
    Type::WATER,
    {
      { Type::FIRE, { 2, 1 } },
      { Type::WATER, { 1, 2 } },
      { Type::GRASS, { 1, 2 } },
      { Type::GROUND, { 2, 1 } },
      { Type::ROCK, { 2, 1 } },
      { Type::DRAGON, { 1, 2 } },
    },
  },
  {
    Type::ELECTRIC,
    {
      { Type::WATER, { 2, 1 } },
      { Type::ELECTRIC, { 1, 2 } },
      { Type::GRASS, { 1, 2 } },
      { Type::GROUND, { 0, 2 } },
      { Type::FLYING, { 2, 1 } },
      { Type::DRAGON, { 1, 2 } },
    },
  },
  {
    Type::GRASS,
    {
      { Type::FIRE, { 1, 2 } },
      { Type::WATER, { 2, 1 } },
      { Type::GRASS, { 1, 2 } },
      { Type::POISON, { 1, 2 } },
      { Type::GROUND, { 2, 1 } },
      { Type::FLYING, { 1, 2 } },
      { Type::BUG, { 1, 2 } },
      { Type::ROCK, { 2, 1 } },
      { Type::DRAGON, { 1, 2 } },
    },
  },
  {
    Type::ICE,
    {
      { Type::WATER, { 1, 2 } },
      { Type::GRASS, { 1, 2 } },
      { Type::ICE, { 1, 2 } },
      { Type::GROUND, { 2, 1 } },
      { Type::FLYING, { 2, 1 } },
      { Type::DRAGON, { 1, 2 } },
    },
  },
  {
    Type::FIGHTING,
    {
      { Type::NORMAL, { 2, 1 } },
      { Type::ICE, { 2, 1 } },
      { Type::POISON, { 1, 2 } },
      { Type::FLYING, { 1, 2 } },
      { Type::PSYCHIC, { 1, 2 } },
      { Type::BUG, { 1, 2 } },
      { Type::ROCK, { 2, 1 } },
      { Type::GHOST, { 0, 2 } },
    },
  },
  {
    Type::POISON,
    {
      { Type::GRASS, { 2, 1 } },
      { Type::POISON, { 1, 2 } },
      { Type::GROUND, { 1, 2 } },
      { Type::ROCK, { 1, 2 } },
      { Type::GHOST, { 1, 2 } },
    },
  },
  {
    Type::GROUND,
    {
      { Type::FIRE, { 2, 1 } },
      { Type::ELECTRIC, { 2, 1 } },
      { Type::GRASS, { 1, 2 } },
      { Type::POISON, { 2, 1 } },
      { Type::FLYING, { 0, 2 } },
      { Type::BUG, { 1, 2 } },
      { Type::ROCK, { 2, 1 } },
    },
  },
  {
    Type::FLYING,
    {
      { Type::ELECTRIC, { 1, 2 } },
      { Type::GRASS, { 2, 1 } },
      { Type::FIGHTING, { 2, 1 } },
      { Type::BUG, { 2, 1 } },
      { Type::ROCK, { 1, 2 } },
    },
  },
  {
    Type::PSYCHIC,
    {
      { Type::FIGHTING, { 2, 1 } },
      { Type::POISON, { 2, 1 } },
      { Type::PSYCHIC, { 1, 2 } },
    },
  },
  {
    Type::BUG,
    {
      { Type::FIRE, { 1, 2 } },
      { Type::GRASS, { 2, 1 } },
      { Type::FIGHTING, { 1, 2 } },
      { Type::POISON, { 1, 2 } },
      { Type::FLYING, { 1, 2 } },
      { Type::PSYCHIC, { 2, 1 } },
    },
  },
  {
    Type::ROCK,
    {
      { Type::FIRE, { 2, 1 } },
      { Type::ICE, { 2, 1 } },
      { Type::FIGHTING, { 1, 2 } },
      { Type::GROUND, { 1, 2 } },
      { Type::FLYING, { 2, 1 } },
      { Type::BUG, { 2, 1 } },
    },
  },
  {
    Type::GHOST,
    {
      { Type::NORMAL, { 0, 2 } },
      { Type::PSYCHIC, { 2, 1 } },
      { Type::GHOST, { 2, 1 } },
    },
  },
  {
    Type::DRAGON,
    {
      { Type::DRAGON, { 2, 1 } },
    },
  },
};

const TypeEffectiveness Generation1::GetTypeEffectiveness(const Type attackType, const Type targetType) {
  return typeMap[attackType][targetType];
}

const TypeEffectiveness Generation1::GetTypeEffectiveness(const Type attackType, const std::array<Type, 2> targetType) {
  return GetTypeEffectiveness(attackType, targetType[0]) + GetTypeEffectiveness(attackType, targetType[1]);
}