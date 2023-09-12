#pragma once

#include <memory>

#include "enginepokemon.hpp"

namespace pokeautumn {
  using EngineParty = std::vector<std::unique_ptr<EnginePokemon>>;
}
