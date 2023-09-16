#include "pokemonstats.hpp"

#include <map>

using namespace pokeautumn;
using namespace pokeautumn::Generation1;

const std::map<const Species, const SpeciesData> Generation1::pokemonData {
  {
    Species::BULBASAUR,
    {
      .baseStats = {
        .hp = 45,
        .attack = 49,
        .defense = 49,
        .speed = 45,
        .special = 65,
      },
      .types = { Type::GRASS, Type::NONE },
    }
  },
  {
    Species::IVYSAUR,
    {
      .baseStats = {
        .hp = 60,
        .attack = 62,
        .defense = 63,
        .speed = 60,
        .special = 80,
      },
      .types = { Type::GRASS, Type::NONE },
    }
  },
  {
    Species::VENUSAUR,
    {
      .baseStats = {
        .hp = 80,
        .attack = 82,
        .defense = 83,
        .speed = 80,
        .special = 100,
      },
      .types = { Type::GRASS, Type::NONE },
    }
  },
  {
    Species::CHARMANDER,
    {
      .baseStats = {
        .hp = 39,
        .attack = 52,
        .defense = 43,
        .speed = 65,
        .special = 50,
      },
      .types = { Type::FIRE, Type::NONE },
    }
  },
  {
    Species::CHARMELEON,
    {
      .baseStats = {
        .hp = 58,
        .attack = 64,
        .defense = 58,
        .speed = 80,
        .special = 65,
      },
      .types = { Type::FIRE, Type::NONE },
    }
  },
  {
    Species::CHARIZARD,
    {
      .baseStats = {
        .hp = 78,
        .attack = 84,
        .defense = 78,
        .speed = 100,
        .special = 85,
      },
      .types = { Type::FIRE, Type::NONE },
    }
  },
  {
    Species::SQUIRTLE,
    {
      .baseStats = {
        .hp = 44,
        .attack = 48,
        .defense = 65,
        .speed = 43,
        .special = 50,
      },
      .types = { Type::WATER, Type::NONE },
    }
  },
  {
    Species::WARTORTLE,
    {
      .baseStats = {
        .hp = 59,
        .attack = 63,
        .defense = 80,
        .speed = 58,
        .special = 65,
      },
      .types = { Type::WATER, Type::NONE },
    },
  },
  {
    Species::BLASTOISE,
    {
      .baseStats = {
        .hp = 79,
        .attack = 83,
        .defense = 100,
        .speed = 78,
        .special = 85,
      },
      .types = { Type::WATER, Type::NONE },
    }
  },
};