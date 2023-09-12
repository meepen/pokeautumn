#pragma once

#include "stattype.hpp"

namespace pokeautumn {
  enum class Nature : unsigned {
    /*             -ATK     -DEF     -SP ATK   -SP DEF   -SPEED */
    /* + ATK */    HARDY,   LONELY,  ADAMANT,  NAUGHTY,  BRAVE,
    /* + DEF */    BOLD,    DOCILE,  IMPISH,   LAX,      RELAXED,
    /* + SP ATK */ MODEST,  MILD,    BASHFUL,  RASH,     QUIET,
    /* + SP DEF */ CALM,    GENTLE,  CAREFUL,  QUIRKY,   SASSY,
    /* + SPEED */  TIMID,   HASTY,   JOLLY,    NAIVE,    SERIOUS,
    COUNT,
  };

  struct NatureEffect {
    StatType increased;
    StatType decreased;
  };

  NatureEffect GetNatureEffect(Nature nature);
}
