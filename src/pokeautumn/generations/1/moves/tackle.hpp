#pragma once

#include "pokeautumn/generations/1/moves.hpp"
#include "pokeautumn/enginemove.hpp"
#include "pokeautumn/battlefield.hpp"
#include "pokeautumn/enginepokemon.hpp"

namespace pokeautumn::Generation1::Moves {
  static MoveData tackleMoveData = {
    .power = 40,
    .accuracy = 100,
    .pp = 35,
    .type = Type::NORMAL,
    .category = MoveCategory::PHYSICAL,
  };

  class Tackle : public EngineMove {
  public:
    virtual bool Apply(EnginePokemon &user, EnginePokemon &target, BattleField &battleField) const override { return false; }

  public:
    virtual MoveData GetMoveData() const override { return tackleMoveData; }
  };

  static Tackle tackleMove;
}
