#pragma once

typedef unsigned int U;

template <typename T>

void List<T>::radixSort(ListNodePosi<T> p,
                        int n) {  // valid(p) && rank(p) + n <= size
  ListNodePosi<T> head = p->pred;
  ListNodePosi<T> tail = p;
  for (int i = 0; i < n; i++) {
    tail = tail->succ;
  }
  for (U radixBit = 0x1; radixBit && (p = head); radixBit <<= 1) {
    for (int i = 0; i < n; i++) {
      radixBit& U(p->succ->data) ? insert(remove(p->succ), tail) : p = p->succ;
    }
  }
}
//˼����ĳ�˷ּ����ǰ׺����׺û�б仯���Ƿ�����漴�����㷨��
//���Ľ�����ǰ�ҳ����Ԫ�ز�����������Чλ���Ӷ���ʡ���õķּ�
//���Ľ���Ϊ����remove()��insertB()�ĵ�Ч�ʣ�ʵ��List::moveB(t,p)�ӿڣ����ڵ�p�ƶ���t֮ǰ
