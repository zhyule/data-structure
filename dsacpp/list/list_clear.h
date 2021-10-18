#pragma once

template <typename T>
int List<T>::clear() {
  int oldSize = _size;
  while (0 < _size) {
    remove(header->succ);  // 反复删除首节点，_size也会逐步减少
  }
  return oldSize;
}