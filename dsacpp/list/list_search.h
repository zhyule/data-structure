#pragma once

//有序列表节点p（可能是trailer）的n个真前期中，找到不大于e的最后者
//与find相比找不到不会单纯的返回NULL
template <typename T>
ListNodePosi<T> List<T>::search(T const& e, int n, ListNodePosi<T> p) const {
  // assert: 0 <= n <= rank(p) < _size
  /*DSA*/ printf("search for");
  print(e);
  printf(":\n");
  do {
    p = p->pred;
    n--;                                                                                               
  } while ((-1 < n) && (e < p->data));
  /*DSA*/ printf("\n");
  return p;
}