#pragma once

//«∞∫Ûµπ÷√
template <typename T>
void List<T>::reverse() {
  ListNodePosi<T> p = header;
  ListNodePosi<T> q = trailer;
  //[0], 1, 2, 3, [4] -> 4, [1], 2, [3], 0 -> 4, 3, 2, 1, 0
  for (int i = 0; i < _size; i += 2) {
    swap((p = p->succ)->data, (q = q->pred)->data);
  }
}