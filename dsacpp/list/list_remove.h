#pragma once

// ɾ��p�ڵ㣬���ر��������
template <typename T>
T List<T>::remove(ListNodePosi<T> p) {
  T e = p->data;
  //pred -> o -> succ => pred -> succ
  p->pred->succ = p->succ;
  p->succ->pred = p->pred;
  delete p; // pָ����new������ListNode����
  _size--;
  return e;
}