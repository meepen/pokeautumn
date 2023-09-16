#pragma once

#include "data/type.hpp"

namespace pokeautumn {
  class Move {
  public:
    virtual ~Move() = default;
    virtual Type GetType() const { return MoveType; }

  private:
    Type MoveType = Type::NORMAL;
  };
}