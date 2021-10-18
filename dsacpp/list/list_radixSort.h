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
//思考：某趟分拣后若前缀、后缀没有变化，是否可以随即结束算法？
//待改进：提前找出最大元素并估算出最高有效位，从而节省无用的分拣
//待改进：为避免remove()、insertB()的低效率，实现List::moveB(t,p)接口，将节点p移动至t之前
