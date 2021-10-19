#pragma once

//删除无序向量中重复元素（繁琐版）
template <typename T>
int Vector<T>::deduplicate() {
  int oldSize = _size;
  int i = -1;
  //[0, ..., i, j, ..., _size - 1], _elem[i]在[i + 1, _size - 1]段内依次删除重复元素
  while (++i < _size - 1) {
    int j = i + 1; //assert: _elem[0, i]中不含重复元素
    while (j < _size) {
      if (_elem[i] == _elem[j]) {
        remove(j);
      } else {
        j++;
      }
    }
  }
  return oldSize - _size;  //返回被删除元素的总数
}