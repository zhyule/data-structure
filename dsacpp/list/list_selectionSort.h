#pragma once

//列表选择排序，起始位置p的n个元素(冒泡)
template <typename T>
void List<T>::selectionSort(ListNodePosi<T> p,
                            int n) {  // valid(p) && rank(p) + n <= size
  /*DSA*/                             // printf ( "SelectionSort ...\n" );
  ListNodePosi<T> header = p->pred, tail = p;
  for (int i = 0; i < n; i++) {
    tail = tail->succ;  // 找到尾节点
  }
  while (1 < n) {  //待排区间至少有2个才能找最大
    ListNodePosi<T> max = selectMax(header->succ, n);
    insert(remove(max),
           tail);  //[0, x-1]区间中找出最大值，移动到区间尾端，待排区间缩小一
    /*DSA*/        // swap(tail->pred->data, selectMax(header->succ, n)->data);
    tail = tail->pred;
    n--;
  }
}