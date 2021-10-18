#pragma once

//�б�鲢������ʼλ��p��n��Ԫ��
template <typename T>
void List<T>::mergeSort(ListNodePosi<T>& p,
                        int n) {  // valid(p) && rank(p) + n <= size
  /*DSA*/                         // printf("\tMERGEsort [%3d]\n", n);
  if (n < 2) {
    return;
  }
  // 1, 2, 3, 4, 5
  int m = n >> 1;  // ȡ�е�
  ListNodePosi<T> q = p;
  for (int i = 0; i < m; i++) {
    q = q->succ;  //Ѱ���е������б�����
  }
  //�ݹ麯�����ִ��
  mergeSort(p, m);                   //�е�ǰ�����б�
  mergeSort(q, n - m);               //�е������б�
  p = merge(p, m, *this, q, n - m);  //�鲢���б�
}  // �����p��Ȼָ��ָ��鲢������ģ��£����