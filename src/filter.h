#pragma once

#include <functional>
#include <vector>

namespace hawk {
/*
 * @brief Template function to apply a filtering operation to a vector of
 * objects.
 *
 * The function accepts a vector of objects and a function object that defines
 * the filtering operation to be applied to each object. It returns a new vector
 * containing pointers to the objects in the input vector that satisfy the
 * filter.
 *
 * @tparam T Type of the objects in the vector.
 *
 * @param v A reference to the vector of objects.
 * @param f A function object that defines the filtering operation.
 * @return A new vector containing pointers to the objects that satisfy the
 * filter.
 */

template <typename T, typename F>
std::vector<T*> filter(std::vector<T*>& vec, F fn) {
  std::vector<T*> vec_filtered;

  for (T* obj : vec) {
    if (fn(obj)) vec_filtered.push_back(obj);
  }

  return vec_filtered;
}
}  // namespace hawk