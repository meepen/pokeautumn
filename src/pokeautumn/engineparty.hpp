#pragma once

#include <vector>
#include <memory>

#include "enginepokemon.hpp"

namespace pokeautumn {
  class EngineParty : public std::vector<std::shared_ptr<EnginePokemon>> {};
}
