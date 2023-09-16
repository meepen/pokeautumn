#pragma once

#include "pokeautumn/enginemove.hpp"
#include "pokeautumn/battlefield.hpp"
#include "pokeautumn/enginepokemon.hpp"

namespace pokeautumn::Generation1::Moves {
  static MoveData noneMoveData = {
    .power = 0,
    .accuracy = 0,
    .pp = 0,
    .type = Type::NONE,
    .category = MoveCategory::STATUS,
  };

  class NoneMove : public EngineMove {
  public:
    virtual bool Apply(EnginePokemon &user, EnginePokemon &target, BattleField &battleField) const override { return false; }
  public:
    virtual MoveData GetMoveData() const override { return noneMoveData; }
  };

  static NoneMove noneMove;
}