#pragma once

#include <functional>
#include <vector>

/**
 * @brief Template function to apply a mapping operation to a vector of pointers
 * to objects.
 *
 * The function accepts a vector of pointers to objects and a function object
 * that defines the mapping operation to be applied to each object. It returns a
 * new vector containing the results of applying the mapping operation to each
 * object.
 *
 * The mapping operation is defined by a function object that takes a pointer to
 * an object of type T and returns a value of type V. The returned vector will
 * contain the results of applying this function to each element in the input
 * vector.
 *
 * @tparam T Type of the objects pointed to in the vector.
 * @tparam F Function object type that defines the mapping operation.
 *
 * @param vec A reference to the vector of pointers to objects.
 * @param fn A function object that defines the mapping operation.
 * @return A new vector containing the results of the mapping operation.
 */

template <typename T, typename F>
auto map(std::vector<T*>& vec, F&& fn) -> std::vector<decltype(fn(vec[0]))> {
  using R = decltype(fn(vec[0]));

  std::vector<R> vec_mapped;

  vec_mapped.reserve(vec.size());  // to avoid reallocations

  for (T* obj : vec) {
    vec_mapped.push_back(fn(obj));
  }

  return vec_mapped;
}
