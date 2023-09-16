#pragma once

#include "pokemon/data/move.hpp"
#include "pokemon/data/type.hpp"

namespace pokeautumn {
  class BattleField;
  class EnginePokemon;

  class EngineMove {
  public:
    virtual bool Apply(EnginePokemon &user, EnginePokemon &target, BattleField &battleField) const = 0;

  public:
    virtual Type MoveType() const { return GetMoveData().type; }
    virtual unsigned Power() const { return GetMoveData().power; }
    virtual unsigned Accuracy() const { return GetMoveData().accuracy; }
    virtual unsigned PP() const { return GetMoveData().pp; }
    virtual MoveCategory Category() const { return GetMoveData().category; }
    virtual bool IsPhysical() const { return Category() == MoveCategory::PHYSICAL; }
    virtual bool IsSpecial() const { return Category() == MoveCategory::SPECIAL; }
    virtual bool IsStatus() const { return Category() == MoveCategory::STATUS; }
    virtual bool IsDamaging() const { return IsPhysical() || IsSpecial(); }

  public:
    virtual MoveData GetMoveData() const = 0;
  };
}
