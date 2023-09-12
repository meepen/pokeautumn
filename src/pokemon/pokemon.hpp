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
      unsigned int attack : 4;
      unsigned int defense : 4;
      unsigned int speed : 4;
      unsigned int special_attack : 4;
      unsigned int hp : 4;
      unsigned int special_defense : 4;
    } ivs;

    /* in generation 1, effort values can go up to 65535 (uint16_max) */
    struct effort_values {
      unsigned int hp : 16;
      unsigned int attack : 16;
      unsigned int defense : 16;
      unsigned int speed : 16;
      unsigned int special_attack : 16;
      unsigned int special_defense : 16;
    } evs;

    Move moves[4] = {
      Move::MOVE_NONE,
      Move::MOVE_NONE,
      Move::MOVE_NONE,
      Move::MOVE_NONE
    };
  };
}
