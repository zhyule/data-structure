#pragma once

// 删除p节点，返回保存的数据
template <typename T>
T List<T>::remove(ListNodePosi<T> p) {
  T e = p->data;
  //pred -> o -> succ => pred -> succ
  p->pred->succ = p->succ;
  p->succ->pred = p->pred;
  delete p; // p指向了new出来的ListNode对象
  _size--;
  return e;
}