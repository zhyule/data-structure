#pragma once

//无序列表去重
template <typename T>
int List<T>::deduplicate() {
  int oldSize = _size;
  ListNodePosi<T> p = first();
  //寻找已去重的列表中是否有与当前节点相同的，是则删除当前节点
  for (Rank r = 0; p != trailer; p = p->succ) {
    if (ListNodePosi<T> q = find(p->data, r, p)) {
      remove(q);
    } else {
      r++;
    }
  }
  return oldSize - _size;
}