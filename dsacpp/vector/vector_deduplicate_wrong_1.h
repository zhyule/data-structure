#pragma once

template <typename T>
int Vector<T>::deduplicate() {
  int oldSize = _size;
  for (Rank i = 1; i < _size; i++) {
    Rank j = find(_elem[i], 0, i);
    std::cout << "查找结果：" << i << _elem[i] << j << "\n" << std::endl;
    if (0 <= j) {
      remove(j ); //删除后仍然进行了索引加一，导致元素访问错位
    }
  }
  return oldSize - _size;
}