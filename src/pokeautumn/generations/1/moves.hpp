#pragma once

#include <map>

#include "pokemon/data/move.hpp"
#include "pokeautumn/enginemove.hpp"

namespace pokeautumn::Generation1 {
  extern std::map<pokeautumn::Move, MoveData> moveData;
  extern std::map<pokeautumn::Move, const EngineMove *> moveList;
}
