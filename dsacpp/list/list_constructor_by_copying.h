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

//assert: p�Ϸ�������������n-1���ڵ�
template <typename T>
List<T>::List(ListNodePosi<T> p, int n) {
  copyNodes(p, n);
}