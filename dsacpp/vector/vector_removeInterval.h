#pragma once

//删除区间[lo, hi)
template <typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
  if (lo == hi) {
    return 0;
  }
  while (hi < _size) {  //区间[hi, _size)
    _elem[lo++] = _elem[hi++];
  }
  _size = lo;      //更新规模
  //shrink();        //必要时缩容
  return hi - lo;  //返回被删除的元素的数目
}