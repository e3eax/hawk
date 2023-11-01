#pragma once

#include <vector>

namespace hawk {

/**
 * @brief Sorts a vector of elements using the merge sort algorithm.
 *
 * This function sorts a vector of elements in ascending order using the
 * merge sort algorithm. The merge sort algorithm is a comparison sort that
 * uses a divide and conquer strategy to efficiently sort the elements of
 * the vector.
 *
 * @tparam T Type of the elements in the vector.
 * @param v The vector to be sorted.
 */
template <typename T>
void merge_sort(std::vector<T>& v) {
  if (v.size() <= 1) return;

  std::vector<T> tmp(v.size());

  merge_sort_r(v, tmp, 0, v.size() - 1);
}

/**
 * @brief Helper function for the merge sort algorithm.
 *
 * This function is a recursive helper function for the merge sort algorithm.
 * It takes a vector, a temporary vector, a left index, and a right index,
 * and sorts the elements of the vector between the left and right indices
 * using the merge sort algorithm.
 *
 * @tparam T Type of the elements in the vector.
 * @param v The vector to be sorted.
 * @param tmp A temporary vector used for merging.
 * @param l The left index of the range to be sorted.
 * @param r The right index of the range to be sorted.
 */
template <typename T>
void merge_sort_r(std::vector<T>& v, std::vector<T>& tmp, int l, int r) {
  if (l >= r) return;

  int m = l + (r - l) / 2;

  merge_sort_r(v, tmp, l, m);

  merge_sort_r(v, tmp, m + 1, r);

  merge(v, tmp, l, m, r);
}

/**
 * @brief Merge function for the merge sort algorithm.
 *
 * This function takes a vector, a temporary vector, a left index, a middle
 * index, and a right index, and merges the elements of the vector between
 * the left and right indices. The elements between the left and middle
 * indices are assumed to be sorted, and the elements between the middle
 * and right indices are also assumed to be sorted. The function merges
 * these two sorted ranges into a single sorted range.
 *
 * @tparam T Type of the elements in the vector.
 * @param v The vector to be merged.
 * @param tmp A temporary vector used for merging.
 * @param l The left index of the range to be merged.
 * @param m The middle index of the range to be merged.
 * @param r The right index of the range to be merged.
 */
template <typename T>
void merge(std::vector<T>& v, std::vector<T>& tmp, int l, int m, int r) {
  int i = l;
  int k = l;
  int j = m + 1;

  while (i <= m && j <= r) {
    if (v[i] < v[j])
      tmp[k++] = v[i++];
    else
      tmp[k++] = v[j++];
  }

  while (i <= m) {
    tmp[k++] = v[i++];
  }

  while (j <= r) {
    tmp[k++] = v[j++];
  }

  std::copy(tmp.begin() + l, tmp.begin() + r + 1, v.begin() + l);
}
}  // namespace hawk
