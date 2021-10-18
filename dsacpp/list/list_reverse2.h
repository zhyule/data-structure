#pragma once

//«∞∫Ûµπ÷√
template <typename T>
void List<T>::reverse() {
  if (_size < 2) {
    return;
  }
  //null -> header -> 0 -> 1 -> 2 -> 3 -> 4 -> trailer -> null
  //0 <--> header -> null [0] -> 1 -> 2 -> 3 -> 4 -> trailer -> null
  //1 <--> 0 -> header-> null [1] -> 2 -> 3 -> 4 -> trailer -> null ...
  for (ListNodePosi<T> p = header; p; p = p->pred) {
    swap(p->pred, p->succ); //tmp = p->pred; p->pred = p->succ; p->succ = tmp;
  }
  swap(header, trailer);
}