#pragma once

#include "pokemon/data/movetype.hpp"
#include "pokemon/data/type.hpp"

namespace pokeautumn {
  struct EngineMoveData {
    unsigned power;
    unsigned accuracy;
    unsigned pp;
    MoveType moveType;
    Type type;
  };

  class BattleField;
  class EnginePokemon;

  class EngineMove {
  public:
    virtual EngineMoveData GetMoveData() const = 0;
    virtual bool Apply(BattleField &field, EnginePokemon &user, EnginePokemon *target = nullptr) = 0;
  };
}
