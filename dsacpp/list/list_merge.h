#pragma once

//�����б�鲢����ǰ�б�p��n��Ԫ�غ��б�Lq��m��Ԫ�ع鲢
// p1  q1      p1   q1
// |   |       |
// p0  q0  =>  p0
//        /    |
//  (p0 > q0)  q0
template <typename T>
// n���0һ����pn-1 < qx, p�����β�ڵ㣬��Ҫ��q�Լ��������β���β�ڵ�֮ǰ
ListNodePosi<T> List<T>::merge(ListNodePosi<T> p, int n, List<T>& L,
                                ListNodePosi<T> q, int m) {
  // assert: this.valid(p) && rank(p) + n <= size && this.sorted(p, n)
  //         L.valid(q) && rank(q) + m <= L._size && L.sorted(q, m)
  ListNodePosi<T> pp = p->pred;  //��¼�׽ڵ�
  //ȷ�����б���n����L�б���m����ǰ���¾Ͳ�����磬ΪʲôҪ������ж���
  while ((0 < m) &&
         (q != p)) {  // q��δ���磨����mergeSort()�У�p����δ���磩֮ǰ
    if ((0 < n) && (p->data <= q->data)) {
      p = p->succ;
      n--;
    } else {
      insert(L.remove((q = q->succ)->pred),
             p);  //ֱ��remove(p)��p���λ�þͶ�ʧ��
      m--;
    }
  }
  return pp->succ;  //�����׽ڵ�
}