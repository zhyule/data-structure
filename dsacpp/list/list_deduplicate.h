#pragma once

//�����б�ȥ��
template <typename T>
int List<T>::deduplicate() {
  int oldSize = _size;
  ListNodePosi<T> p = first();
  //Ѱ����ȥ�ص��б����Ƿ����뵱ǰ�ڵ���ͬ�ģ�����ɾ����ǰ�ڵ�
  for (Rank r = 0; p != trailer; p = p->succ) {
    if (ListNodePosi<T> q = find(p->data, r, p)) {
      remove(q);
    } else {
      r++;
    }
  }
  return oldSize - _size;
}