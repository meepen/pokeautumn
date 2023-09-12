#pragma once

#ifndef POKEAUTUMN_NODEBUG
#include <string>

namespace pokeautumn::debug {
  static std::string tab(unsigned indent) {
    return std::string(indent, '\t');
  }
}

#endif