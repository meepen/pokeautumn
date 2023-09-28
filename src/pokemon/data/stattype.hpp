#pragma once

namespace pokeautumn {
  enum class StatType : unsigned {
    HP,
    ATTACK,
    DEFENSE,
    SPEED,
    SPECIAL_ATTACK,
    // Only used in gen1
    SPECIAL = SPECIAL_ATTACK,
    GEN1_COUNT = SPECIAL + 1,
    SPECIAL_DEFENSE,
    COUNT,
  };
}