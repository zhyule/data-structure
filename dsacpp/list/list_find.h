#pragma once

//�����б�ڵ�p��������trailer����n����ǰ���У��ҵ�����e�������
template <typename T>
ListNodePosi<T> List<T>::find(T const& e, int n, ListNodePosi<T> p) const {
  //��η�ֹnԽ�磬��λ�ȡ��ǰ�ڵ�p����
  while (0 < n--) {                  // assert: 0 <= n <= rank(p) <_size
    if (e == (p = p->pred)->data) {  //�������󣬲�����p�㣬���һ��
      return p;
    }
  }
  return NULL;  // δ���ҵ�
}