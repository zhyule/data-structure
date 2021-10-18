#pragma once

//无序向量顺序查找：返回最后一个元素e的位置；失败返回lo - 1
template <typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const {
  //lo < hi-- : if (lo < hi) hi -= 1; 
  while ((lo < hi--) && (e != _elem[hi]))
    ;
  return hi; 
}