#include "pokemonstats.hpp"

#include <map>

using namespace pokeautumn;
using namespace pokeautumn::Generation1;

const std::map<const Species, const PokemonBaseStats> Generation1::pokemonData {
  std::make_pair<Species, PokemonBaseStats>(
    Species::BULBASAUR,
    {
      .hp = 45,
      .attack = 49,
      .defense = 49,
      .speed = 45,
      .special = 65,
    }
  ),
  std::make_pair<Species, PokemonBaseStats>(
    Species::IVYSAUR,
    {
      .hp = 60,
      .attack = 62,
      .defense = 63,
      .speed = 60,
      .special = 80,
    }
  ),
  std::make_pair<Species, PokemonBaseStats>(
    Species::VENUSAUR,
    {
      .hp = 80,
      .attack = 82,
      .defense = 83,
      .speed = 80,
      .special = 100,
    }
  ),
  std::make_pair<Species, PokemonBaseStats>(
    Species::CHARMANDER,
    {
      .hp = 39,
      .attack = 52,
      .defense = 43,
      .speed = 65,
      .special = 50,
    }
  ),
  std::make_pair<Species, PokemonBaseStats>(
    Species::CHARMELEON,
    {
      .hp = 58,
      .attack = 64,
      .defense = 58,
      .speed = 80,
      .special = 65,
    }
  ),
  std::make_pair<Species, PokemonBaseStats>(
    Species::CHARIZARD,
    {
      .hp = 78,
      .attack = 84,
      .defense = 78,
      .speed = 100,
      .special = 85,
    }
  ),
  std::make_pair<Species, PokemonBaseStats>(
    Species::SQUIRTLE,
    {
      .hp = 44,
      .attack = 48,
      .defense = 65,
      .speed = 43,
      .special = 50,
    }
  ),
  std::make_pair<Species, PokemonBaseStats>(
    Species::WARTORTLE,
    {
      .hp = 59,
      .attack = 63,
      .defense = 80,
      .speed = 58,
      .special = 65,
    }
  ),
  std::make_pair<Species, PokemonBaseStats>(
    Species::BLASTOISE,
    {
      .hp = 79,
      .attack = 83,
      .defense = 100,
      .speed = 78,
      .special = 85,
    }
  ),
};