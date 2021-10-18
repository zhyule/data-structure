#pragma once

template <typename T>
Rank Vector<T>::insert(Rank r, T const& e) {  // assert: 0 <= r <= size
  expand();                                   // 扩容给插入元素腾空间
  for (int i = _size; i > r; i--) {           // 从后往前
    _elem[i] = _elem[i - 1];
  }
  _elem[r] = e;  // 插入新元素
  _size++;       // 更新容量
  return r;      // 返回秩
}