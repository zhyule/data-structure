#pragma once

template <typename T> // ѭ�ȷ��ʣ�ʱ�临�Ӷ�r
T& List<T>::operator[](Rank r) const { // assert: 0 <= r < size
  ListNodePosi<T> p = first();
  //ѭ��r��
  while (0 < r--) {
    p = p->succ; // ���׽ڵ����������r��������0�Ͳ���
  }
  return p->data; // ����Ŀ��ڵ��е�Ԫ��
}