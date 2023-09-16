#pragma once

#include "data/stattype.hpp"
#include "data/move.hpp"
#include "data/species.hpp"

namespace pokeautumn {
  struct Pokemon {
    Species species = Species::MISSINGNO;
    unsigned int level = 0;
    bool is_shiny = false;

    struct individual_values {
      unsigned attack : 4;
      unsigned defense : 4;
      unsigned speed : 4;
      union {
        unsigned special_attack : 4;
        unsigned special : 4;
      };
      unsigned hp : 4;
      unsigned special_defense : 4;
    } ivs;

    /* in generation 1, effort values can go up to 65535 (uint16_max) */
    struct effort_values {
      unsigned hp : 16;
      unsigned attack : 16;
      unsigned defense : 16;
      unsigned speed : 16;
      union {
        unsigned special_attack : 16;
        unsigned special : 16;
      };
      unsigned special_defense : 16;
    } evs;

    Move moves[4] = {
      Move::MOVE_NONE,
      Move::MOVE_NONE,
      Move::MOVE_NONE,
      Move::MOVE_NONE
    };
  };
}
