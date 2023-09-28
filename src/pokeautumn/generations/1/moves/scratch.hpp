#pragma once

#include "pokeautumn/generations/1/moves.hpp"
#include "pokeautumn/enginemove.hpp"
#include "pokeautumn/enginebattle.hpp"
#include "pokeautumn/enginepokemon.hpp"

namespace pokeautumn::Generation1::Moves {
  static MoveData scratchMoveData = {
    .power = 40,
    .accuracy = 100,
    .pp = 35,
    .type = Type::NORMAL,
    .category = MoveCategory::PHYSICAL,
    .move = Move::MOVE_SCRATCH,
  };

  class Scratch : public EngineMove {
  public:
    virtual MoveData GetMoveData() const override { return scratchMoveData; }
  };

  static Scratch scratchMove;
}
