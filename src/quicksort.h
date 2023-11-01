#pragma once

#include <algorithm>
#include <cstdlib>
#include <vector>

namespace hawk {

/**
 * @brief Sorts a vector of elements using the quicksort algorithm.
 *
 * This function sorts a vector of elements in ascending order using the
 * quicksort algorithm. The quicksort algorithm is a comparison sort that
 * uses a divide and conquer strategy to efficiently sort the elements of
 * the vector.
 *
 * @tparam T Type of the elements in the vector.
 * @param v The vector to be sorted.
 */
template <typename T>
void quicksort(std::vector<T>& v) {
  if (v.size() <= 1) return;

  quicksort_r(v, 0, v.size() - 1);
}

/**
 * @brief Helper function for the quicksort algorithm.
 *
 * This function is a recursive helper function for the quicksort algorithm.
 * It takes a vector, a start index, and an end index, and sorts the elements
 * of the vector between the start and end indices using the quicksort
 * algorithm.
 *
 * @tparam T Type of the elements in the vector.
 * @param v The vector to be sorted.
 * @param s The start index of the range to be sorted.
 * @param e The end index of the range to be sorted.
 */
template <typename T>
void quicksort_r(std::vector<T>& v, int s, int e) {
  while (s < e) {
    int p = partition(v, s, e);

    if (s - p < e - p) {
      quicksort_r(v, s, p - 1);
      s = p + 1;
    } else {
      quicksort_r(v, p + 1, e);
      e = p - 1;
    }
  }
}

/**
 * @brief Partition function for the quicksort algorithm.
 *
 * This function takes a vector, a start index, and an end index, and
 * partitions the elements of the vector between the start and end indices
 * around a randomly selected pivot element. The pivot element is placed
 * in its correct position in the sorted array, and the elements that are
 * less than or equal to the pivot are placed to the left of the pivot, and
 * the elements that are greater than the pivot are placed to the right of
 * the pivot.
 *
 * @tparam T Type of the elements in the vector.
 * @param v The vector to be partitioned.
 * @param s The start index of the range to be partitioned.
 * @param e The end index of the range to be partitioned.
 * @return The index of the pivot element in the partitioned vector.
 */
template <typename T>
int partition(std::vector<T>& v, int s, int e) {
  int pivot_idx = s + rand() % (e - s + 1);

  if (pivot_idx != e) std::swap(v[pivot_idx], v[e]);

  int i = s;
  int pv = v[e];

  for (int j = s; j < e; j++) {
    if (v[j] <= pv) {
      std::swap(v[i], v[j]);
      i++;
    }
  }

  std::swap(v[i], v[e]);

  return i;
}

}  // namespace hawk
