#pragma once

#include <map>
#include <array>
#include <utility>

#include "pokemon/data/type.hpp"

namespace pokeautumn::Generation1 {
  struct TypeEffectiveness {
    int numerator = 1;
    int denominator = 1;

    TypeEffectiveness operator+(const TypeEffectiveness &other) const {
      return {
        numerator * other.numerator,
        denominator * other.denominator,
      };
    }

    template <typename T>
    T operator*(const T &value) const {
      return value * numerator / denominator;
    }
  };

  // returns numerator, denominator
  extern const TypeEffectiveness GetTypeEffectiveness(const Type attackType, const std::array<Type, 2> targetType);
  // returns numerator, denominator
  extern const TypeEffectiveness GetTypeEffectiveness(const Type attackType, const Type targetType);
}
