#pragma once

#include "pokemon/data/move.hpp"
#include "pokemon/data/type.hpp"

namespace pokeautumn {
  class EngineBattle;
  class EnginePokemon;

  class EngineMove {
  public:
    virtual bool Apply(EnginePokemon &user, EnginePokemon &target, EngineBattle &battleField) const;
    bool ApplyDamage(EnginePokemon &user, EnginePokemon &target, EngineBattle &field) const;
    bool ApplyStatus(EnginePokemon &user, EnginePokemon &target, EngineBattle &field) const;

  public:
    virtual Type GetType() const { return GetMoveData().type; }
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
    Move GetMove() { return GetMoveData().move; }
  };
}
