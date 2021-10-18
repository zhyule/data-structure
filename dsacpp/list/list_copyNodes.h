#pragma once

template <typename T>
void List<T>::copyNodes(ListNodePosi<T> p, int n ) {
  init(); //创建首尾哨兵并初始化
  while (n--) {
    insertAsLast(p->data);
    p = p->succ;
  }
}