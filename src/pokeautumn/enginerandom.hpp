#pragma once

namespace pokeautumn {
  /* https://www.dragonflycave.com/mechanics/gen-i-rng */
  class EngineRandom {
  public:
    virtual unsigned RandomNumber(unsigned max) const = 0;
    virtual bool MoveHits(unsigned accuracy) const = 0;
  };
}