#pragma once

#include <algorithm>
#include <cstdlib>
#include <vector>

namespace hawk {

template <typename T>
void quicksort(std::vector<T>& v) {
  if (v.size() <= 1) return;

  quicksort_r(v, 0, v.size() - 1);
}

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