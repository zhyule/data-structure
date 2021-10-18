#pragma once

//������������[lo, hi)��ʼ��
template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {
  _elem = new T[_capacity = 2 * (hi - lo)];
  for (_size = 0; lo < hi; _size++, lo++) {
    _elem[_size] = A[lo]; // ��A[lo, hi)���Ƶ�_elem[0, hi - lo)
  }
} // O(hi - lo)