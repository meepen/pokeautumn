#pragma once 

#include <map>
#include <pokemon/data/species.hpp>

namespace pokeautumn::Generation1 {
  struct PokemonBaseStats {
    unsigned hp : 8;
    unsigned attack : 8;
    unsigned defense : 8;
    unsigned speed : 8;
    unsigned special : 8;
  };

  extern const std::map<const Species, const PokemonBaseStats> pokemonData;
}
