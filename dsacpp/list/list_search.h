#pragma once

//�����б�ڵ�p��������trailer����n����ǰ���У��ҵ�������e�������
//��find����Ҳ������ᵥ���ķ���NULL
template <typename T>
ListNodePosi<T> List<T>::search(T const& e, int n, ListNodePosi<T> p) const {
  // assert: 0 <= n <= rank(p) < _size
  /*DSA*/ printf("search for");
  print(e);
  printf(":\n");
  do {
    p = p->pred;
    n--;                                                                                               
  } while ((-1 < n) && (e < p->data));
  /*DSA*/ printf("\n");
  return p;
}