#pragma once

//无序列表节点p（可能是trailer）的n个真前期中，找到等于e的最后者
template <typename T>
ListNodePosi<T> List<T>::find(T const& e, int n, ListNodePosi<T> p) const {
  //如何防止n越界，如何获取当前节点p的秩
  while (0 < n--) {                  // assert: 0 <= n <= rank(p) <_size
    if (e == (p = p->pred)->data) {  //从右往左，不包括p点，最后一个
      return p;
    }
  }
  return NULL;  // 未查找到
}