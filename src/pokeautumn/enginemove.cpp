#include "enginemove.hpp"
#include "enginepokemon.hpp"
#include "enginebattle.hpp"

using namespace pokeautumn;

bool EngineMove::Apply(EnginePokemon &user, EnginePokemon &target, EngineBattle &field) const {
  auto moveData = GetMoveData();
  switch (moveData.category) {
    case MoveCategory::PHYSICAL:
    case MoveCategory::SPECIAL:
      return ApplyDamage(user, target, field);
    case MoveCategory::STATUS:
      return ApplyStatus(user, target, field);
    default:
      return false;
  }
}

bool EngineMove::ApplyDamage(EnginePokemon &user, EnginePokemon &target, EngineBattle &battle) const {
  if (target.IsImmuneTo(*this)) {
    return false;
  }

  auto damage = user.CalculateDamage(*this, target);
  target.OnDamageTaken(damage);

  if (target.GetHealth() == 0) {
    battle.OnFaint(target);
  }

  return true;
}

bool EngineMove::ApplyStatus(EnginePokemon &user, EnginePokemon &target, EngineBattle &battle) const {
  if (target.IsImmuneTo(*this)) {
    return false;
  }

  // TODO: Implement status effects
  return false;
}