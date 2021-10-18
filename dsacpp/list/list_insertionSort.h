#pragma once

//�б����������ʼλ��p��n��Ԫ��
template <typename T>
void List<T>::insertionSort(ListNodePosi<T> p,
                            int n) {  // valid(p) && rank(p) + n <= size
  for (int r = 0; r < n; r++) {
    insert(search(p->data, r, p),
           p->data);  // [0, r]�������ҵ�������data�Ľڵ㣬�������
    p = p->succ;
    remove(p->pred);
  }  // n�ε�����ÿ��o(r + 1)
}