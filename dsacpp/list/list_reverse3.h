#pragma once

//前后倒置
template <typename T>
void List<T>::reverse() {
  if (_size < 2) {
    return;
  }
  ListNodePosi<T> p;
  ListNodePosi<T> q;
  //依次颠倒各节点的前驱指针
  for (p = header, q = p->succ; p != trailer; p = q, q = p->succ) {
    p->pred = q;
  }
  trailer->pred = NULL;
  //依次颠倒各节点的后继指针
  for (p = header, q = p->pred; p != trailer; p = q, q = p->pred) {
    q->succ = p;
  }
  header->succ = NULL;
  swap(header, trailer);
}