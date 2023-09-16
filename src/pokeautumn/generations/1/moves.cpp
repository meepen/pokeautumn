#include "pokeautumn/generations/1/moves.hpp"

#include "moves/none.hpp"
#include "moves/tackle.hpp"
#include "moves/scratch.hpp"

using namespace pokeautumn;
using namespace pokeautumn::Generation1;

std::map<Move, MoveData> Generation1::moveData = {
  { Move::MOVE_NONE, Moves::noneMoveData },
  { Move::MOVE_TACKLE, Moves::tackleMoveData },
  { Move::MOVE_SCRATCH, Moves::scratchMoveData },
};

std::map<Move, const EngineMove *> Generation1::moveList = {
  { Move::MOVE_NONE, &Moves::noneMove },
  { Move::MOVE_TACKLE, &Moves::tackleMove },
  { Move::MOVE_SCRATCH, &Moves::scratchMove },
};
