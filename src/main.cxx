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

  auto party1 = engine->CreateParty({
    {
      .species = Species::BULBASAUR,
      .level = 5,
      .ivs = {
        .defense = 15,
      },
      .moves = {
        Move::MOVE_TACKLE,
      },
    },
  });
  auto party2 = engine->CreateParty({
    {
      .species = Species::CHARMANDER,
      .level = 5,
      .ivs = {
        .attack = 15,
      },
      .moves = {
        Move::MOVE_SCRATCH,
      },
    },
  });

  std::cout << "CREATED PARTIES WOO!" << std::endl;
  std::cout << "Bulbasaur stats: " << std::endl;
  dump_stats(party1[0]);

  std::cout << "Charmander stats: " << std::endl;
  dump_stats(party2[0]);

  return 0;
}