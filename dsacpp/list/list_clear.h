#pragma once

template <typename T>
int List<T>::clear() {
  int oldSize = _size;
  while (0 < _size) {
    remove(header->succ);  // ����ɾ���׽ڵ㣬_sizeҲ���𲽼���
  }
  return oldSize;
}