#pragma once

//有序数列去重
template <typename T>
int List<T>::uniquify() {
  if (_size < 2) {
    return 0;
  }
  int oldSize = _size;
  ListNodePosi<T> p = first();
  ListNodePosi<T> q;
  //紧邻节点相异比较下一个对，相同删除后一个节点
  while (trailer != (q = p->succ)) {
    if (p->data != q->data) {
      p = q;
    } else {
      remove(q);
    }
  }
  return oldSize - _size;
} // o(n)