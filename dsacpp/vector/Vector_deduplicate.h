#pragma once

//删除无序向量中重复元素
template <typename T>
int Vector<T>::deduplicate() {
  int oldSize = _size; //记录原规模
  //[0, ..., i -1, i, ..., _size - 1], _elem[i]在[0, i-1]段内有重复值就删除，否则下一个
  Rank i = 1;
  while (i < _size) {
    if (find(_elem[i], 0, i) < 0) {
      i++;
    } else {
      remove(i);
    }
  }
  return oldSize - _size; //返回被删除元素的总数
}