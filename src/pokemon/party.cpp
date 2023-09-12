#include "party.hpp"
#include "pokeautumn/debug.hpp"

// namespace pokeautumn {
// #ifndef POKEAUTUMN_NODEBUG
//   std::string Party::dump(unsigned indent) const {
//     std::string result = "[";
//     for (const auto &pokemon : pokemon) {
//       result += "\n" + debug::tab(indent + 1);
//       if (pokemon) {
//         result += pokemon->dump(indent + 1);
//       } else {
//         result += "<empty>";
//       }
//     }
//     return result + "\n" + debug::tab(indent) + "]";
//   }
// #endif
// }