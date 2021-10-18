#pragma once

//ǰ����
template <typename T>
void List<T>::reverse() {
  if (_size < 2) {
    return;
  }
  ListNodePosi<T> p;
  ListNodePosi<T> q;
  //���εߵ����ڵ��ǰ��ָ��
  for (p = header, q = p->succ; p != trailer; p = q, q = p->succ) {
    p->pred = q;
  }
  trailer->pred = NULL;
  //���εߵ����ڵ�ĺ��ָ��
  for (p = header, q = p->pred; p != trailer; p = q, q = p->pred) {
    q->succ = p;
  }
  header->succ = NULL;
  swap(header, trailer);
}