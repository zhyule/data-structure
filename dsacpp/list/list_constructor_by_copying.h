#pragma once

template <typename T>
List<T>::List(List<T> const& L) {
  copyNodes(L.first(), L._size);
}

// assert: r + n <= L._size
template <typename T>
List<T>::List(List<T> const& L, Rank r, int n) {
  ListNodePosi<T> p = L.first();
  while (0 < r--) {
    p = p->succ;
  }
  copyNodes(p, n);
}

//assert: p合法，后面至少有n-1个节点
template <typename T>
List<T>::List(ListNodePosi<T> p, int n) {
  copyNodes(p, n);
}