#pragma once

template <typename T> // 循秩访问，时间复杂度r
T& List<T>::operator[](Rank r) const { // assert: 0 <= r < size
  ListNodePosi<T> p = first();
  //循环r次
  while (0 < r--) {
    p = p->succ; // 从首节点出发，后数r个，秩是0就不数
  }
  return p->data; // 返回目标节点中的元素
}