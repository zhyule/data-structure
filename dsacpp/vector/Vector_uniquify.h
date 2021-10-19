#pragma once

//删除有序向量中重复元素（高效版）
template <typename T>
int Vector<T>::uniquify() {
  Rank i = 0, j = 0;
  //挑出不同的元素，直接截除多余元素
  while (++j < _size) {
    if (_elem[i] != _elem[j]) {
      _elem[i++] = _elem[j];
    }
  }
  _size = ++i;
  shrink();
  return j - i;
}
