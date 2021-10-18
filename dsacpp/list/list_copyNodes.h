#pragma once

template <typename T>
void List<T>::copyNodes(ListNodePosi<T> p, int n ) {
  init(); //������β�ڱ�����ʼ��
  while (n--) {
    insertAsLast(p->data);
    p = p->succ;
  }
}