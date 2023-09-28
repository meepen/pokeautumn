#pragma once

#include "pokeautumn/enginebattle.hpp"

namespace pokeautumn::Generation1 {
  class Battle : public EngineBattle {
  public:
    Battle(std::vector<std::shared_ptr<EngineParty>> parties);

  };
}
