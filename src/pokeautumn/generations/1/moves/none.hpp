#pragma once

#include "pokeautumn/enginemove.hpp"
#include "pokeautumn/enginebattle.hpp"
#include "pokeautumn/enginepokemon.hpp"

namespace pokeautumn::Generation1::Moves {
  static MoveData noneMoveData = {
    .power = 0,
    .accuracy = 0,
    .pp = 0,
    .type = Type::NONE,
    .category = MoveCategory::STATUS,
    .move = Move::MOVE_NONE,
  };

  class NoneMove : public EngineMove {
  public:
    virtual MoveData GetMoveData() const override { return noneMoveData; }
  };

  static NoneMove noneMove;
}