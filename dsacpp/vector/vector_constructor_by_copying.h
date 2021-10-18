#pragma once

//利用数组区间[lo, hi)初始化
template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {
  _elem = new T[_capacity = 2 * (hi - lo)];
  for (_size = 0; lo < hi; _size++, lo++) {
    _elem[_size] = A[lo]; // 将A[lo, hi)复制到_elem[0, hi - lo)
  }
} // O(hi - lo)