#pragma once

//��������ȥ��
template <typename T>
int List<T>::uniquify() {
  if (_size < 2) {
    return 0;
  }
  int oldSize = _size;
  ListNodePosi<T> p = first();
  ListNodePosi<T> q;
  //���ڽڵ�����Ƚ���һ���ԣ���ͬɾ����һ���ڵ�
  while (trailer != (q = p->succ)) {
    if (p->data != q->data) {
      p = q;
    } else {
      remove(q);
    }
  }
  return oldSize - _size;
} // o(n)