#include "nature.hpp"
#include <stdexcept>

using namespace pokeautumn;

static const NatureEffect natureEffects[] = {
  /* HARDY */   { StatType::ATTACK, StatType::ATTACK },
  /* LONELY */  { StatType::ATTACK, StatType::DEFENSE },
  /* ADAMANT */ { StatType::ATTACK, StatType::SPECIAL_ATTACK },
  /* NAUGHTY */ { StatType::ATTACK, StatType::SPECIAL_DEFENSE },
  /* BRAVE */   { StatType::ATTACK, StatType::SPEED },

  /* BOLD */    { StatType::DEFENSE, StatType::ATTACK },
  /* DOCILE */  { StatType::DEFENSE, StatType::DEFENSE },
  /* IMPISH */  { StatType::DEFENSE, StatType::SPECIAL_ATTACK },
  /* LAX */     { StatType::DEFENSE, StatType::SPECIAL_DEFENSE },
  /* RELAXED */ { StatType::DEFENSE, StatType::SPEED },

  /* MODEST */  { StatType::SPECIAL_ATTACK, StatType::ATTACK },
  /* MILD */    { StatType::SPECIAL_ATTACK, StatType::DEFENSE },
  /* BASHFUL */ { StatType::SPECIAL_ATTACK, StatType::SPECIAL_ATTACK },
  /* RASH */    { StatType::SPECIAL_ATTACK, StatType::SPECIAL_DEFENSE },
  /* QUIET */   { StatType::SPECIAL_ATTACK, StatType::SPEED },

  /* CALM */    { StatType::SPECIAL_DEFENSE, StatType::ATTACK },
  /* GENTLE */  { StatType::SPECIAL_DEFENSE, StatType::DEFENSE },
  /* CAREFUL */ { StatType::SPECIAL_DEFENSE, StatType::SPECIAL_ATTACK },
  /* QUIRKY */  { StatType::SPECIAL_DEFENSE, StatType::SPECIAL_DEFENSE },
  /* SASSY */   { StatType::SPECIAL_DEFENSE, StatType::SPEED },

  /* TIMID */   { StatType::SPEED, StatType::ATTACK },
  /* HASTY */   { StatType::SPEED, StatType::DEFENSE },
  /* JOLLY */   { StatType::SPEED, StatType::SPECIAL_ATTACK },
  /* NAIVE */   { StatType::SPEED, StatType::SPECIAL_DEFENSE },
  /* SERIOUS */ { StatType::SPEED, StatType::SPEED },
};

NatureEffect pokeautumn::GetNatureEffect(Nature nature) {
  if (nature >= Nature::COUNT) {
    throw std::runtime_error("Invalid nature");
  }

  return natureEffects[static_cast<int>(nature)];
}