#pragma once

//列表归并排序：起始位置p的n个元素
template <typename T>
void List<T>::mergeSort(ListNodePosi<T>& p,
                        int n) {  // valid(p) && rank(p) + n <= size
  /*DSA*/                         // printf("\tMERGEsort [%3d]\n", n);
  if (n < 2) {
    return;
  }
  // 1, 2, 3, 4, 5
  int m = n >> 1;  // 取中点
  ListNodePosi<T> q = p;
  for (int i = 0; i < m; i++) {
    q = q->succ;  //寻找中点后的子列表的起点
  }
  //递归函数如何执行
  mergeSort(p, m);                   //中点前的子列表
  mergeSort(q, n - m);               //中点后的子列表
  p = merge(p, m, *this, q, n - m);  //归并子列表
}  // 排序后，p依然指向指向归并后区间的（新）起点