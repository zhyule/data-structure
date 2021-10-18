#pragma once

//�б�ѡ��������ʼλ��p��n��Ԫ��(ð��)
template <typename T>
void List<T>::selectionSort(ListNodePosi<T> p,
                            int n) {  // valid(p) && rank(p) + n <= size
  /*DSA*/                             // printf ( "SelectionSort ...\n" );
  ListNodePosi<T> header = p->pred, tail = p;
  for (int i = 0; i < n; i++) {
    tail = tail->succ;  // �ҵ�β�ڵ�
  }
  while (1 < n) {  //��������������2�����������
    ListNodePosi<T> max = selectMax(header->succ, n);
    insert(remove(max),
           tail);  //[0, x-1]�������ҳ����ֵ���ƶ�������β�ˣ�����������Сһ
    /*DSA*/        // swap(tail->pred->data, selectMax(header->succ, n)->data);
    tail = tail->pred;
    n--;
  }
}