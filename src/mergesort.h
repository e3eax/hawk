#pragma once

#include <vector>

template <typename T>
void merge_sort(std::vector<T>& v) {
  if (v.size() <= 1) return;

  std::vector<T> tmp(v.size());

  merge_sort_r(v, tmp, 0, v.size() - 1);
}

template <typename T>
void merge_sort_r(std::vector<T>& v, std::vector<T>& tmp, int l, int r) {
  if (l >= r) return;

  int m = l + (r - l) / 2;

  merge_sort_r(v, tmp, l, m);

  merge_sort_r(v, tmp, m + 1, r);

  merge(v, tmp, l, m, r);
}

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