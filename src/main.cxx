#include <iostream>

#include "pokeautumn/engine.hpp"

#include "pokemon/pokemon.hpp"
#include "pokemon/party.hpp"
#include "pokemon/data/move.hpp"

using namespace pokeautumn;

static void dump_stats(std::unique_ptr<EnginePokemon> &pokemon) {
  std::cout << "HP: " << pokemon->GetStatValue(StatType::HP) << std::endl;
  std::cout << "Attack: " << pokemon->GetStatValue(StatType::ATTACK) << std::endl;
  std::cout << "Defense: " << pokemon->GetStatValue(StatType::DEFENSE) << std::endl;
  std::cout << "Speed: " << pokemon->GetStatValue(StatType::SPEED) << std::endl;
  std::cout << "Special Attack: " << pokemon->GetStatValue(StatType::SPECIAL_ATTACK) << std::endl;
  std::cout << "Special Defense: " << pokemon->GetStatValue(StatType::SPECIAL_DEFENSE) << std::endl;
}

int main(int argc, char* argv[]) {
  auto engine = Engine::ForGeneration(Generation::GEN1);

  Pokemon bulbasaurData = {
    .species = Species::BULBASAUR,
    .level = 99,
    .ivs = {
      .defense = 15,
    },
    .moves = {
      Move::MOVE_TACKLE,
    },
  };

  Pokemon charmanderData = {
    .species = Species::CHARMANDER,
    .level = 5,
    .ivs = {
      .attack = 15,
    },
    .moves = {
      Move::MOVE_SCRATCH,
    },
  };

  auto party1 = engine->CreateParty({bulbasaurData});
  auto party2 = engine->CreateParty({charmanderData});

  std::cout << "CREATED PARTIES WOO!" << std::endl;

  std::cout << "Bulbasaur stats: " << std::endl;
  dump_stats(party1[0]);

  std::cout << "Charmander stats: " << std::endl;
  dump_stats(party2[0]);

  return 0;
}