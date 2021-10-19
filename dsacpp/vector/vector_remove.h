#pragma once

//删除向量中秩为r的元素
template <typename T>
T Vector<T>::remove(Rank r) { //assert: 0 <= r < _size
  T e = _elem[r]; //备份
  remove(r, r + 1); //删除[r, r + 1)区间的元素
  return e; //返回被删除的元素
}