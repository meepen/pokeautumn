#include <iostream>

#include "pokeautumn/engine.hpp"

#include "pokemon/pokemon.hpp"
#include "pokemon/party.hpp"
#include "pokemon/data/move.hpp"

using namespace pokeautumn;

static void dump_stats(std::shared_ptr<EnginePokemon> &pokemon) {
  std::cout << "HP: " << pokemon->GetStatValue(StatType::HP) << std::endl;
  std::cout << "Attack: " << pokemon->GetStatValue(StatType::ATTACK) << std::endl;
  std::cout << "Defense: " << pokemon->GetStatValue(StatType::DEFENSE) << std::endl;
  std::cout << "Speed: " << pokemon->GetStatValue(StatType::SPEED) << std::endl;
  std::cout << "Special Attack: " << pokemon->GetStatValue(StatType::SPECIAL_ATTACK) << std::endl;
  std::cout << "Special Defense: " << pokemon->GetStatValue(StatType::SPECIAL_DEFENSE) << std::endl;
}

static void dump_battle(std::unique_ptr<EngineBattle> &battle) {
  std::cout << "Battle: " << std::endl;
  for (auto &party : battle->GetParties()) {
    std::cout << "Party: " << std::endl;
    for (auto &pokemon : *party) {
      std::cout << "Pokemon: " << std::endl;
      dump_stats(pokemon);
    }
  }
}

int main(int argc, char* argv[]) {
  auto engine = Engine::ForGeneration(Generation::GEN1);

  std::shared_ptr<EngineParty> party1 = std::move(
    engine->CreateParty({
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
    })
  );

  std::shared_ptr<EngineParty> party2 = std::move(
    engine->CreateParty({
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
    })
  );

  std::cout << "CREATED PARTIES WOO!" << std::endl;
  std::cout << "Bulbasaur stats: " << std::endl;
  dump_stats(party1->at(0));

  std::cout << "Charmander stats: " << std::endl;
  dump_stats(party2->at(0));

  // Let's start a battle...
  auto battle = engine->CreateBattle(BattleType::SINGLES, { party1, party2 });

  std::cout << "BATTLE CREATED WOO!" << std::endl;

  dump_battle(battle);

  return 0;
}