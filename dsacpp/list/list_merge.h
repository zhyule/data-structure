#pragma once

//有序列表归并：当前列表p起n个元素和列表Lq起m个元素归并
// p1  q1      p1   q1
// |   |       |
// p0  q0  =>  p0
//        /    |
//  (p0 > q0)  q0
template <typename T>
// n变成0一定是pn-1 < qx, p变成了尾节点，需要将q以及后续依次插入尾节点之前
ListNodePosi<T> List<T>::merge(ListNodePosi<T> p, int n, List<T>& L,
                                ListNodePosi<T> q, int m) {
  // assert: this.valid(p) && rank(p) + n <= size && this.sorted(p, n)
  //         L.valid(q) && rank(q) + m <= L._size && L.sorted(q, m)
  ListNodePosi<T> pp = p->pred;  //记录首节点
  //确保本列表处理n个，L列表处理m个在前提下就不会出界，为什么要加这个判断呢
  while ((0 < m) &&
         (q != p)) {  // q尚未出界（或在mergeSort()中，p亦尚未出界）之前
    if ((0 < n) && (p->data <= q->data)) {
      p = p->succ;
      n--;
    } else {
      insert(L.remove((q = q->succ)->pred),
             p);  //直接remove(p)，p点的位置就丢失了
      m--;
    }
  }
  return pp->succ;  //更新首节点
}