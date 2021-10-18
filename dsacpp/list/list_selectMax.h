#pragma once

template <typename T>
ListNodePosi<T> List<T>::selectMax(ListNodePosi<T> p, int n) {
  ListNodePosi<T> max = p;
  for (ListNodePosi<T> cur = p; 1 < n; n--) {  // [p - n + 1, p]
    if (!lt((cur = cur->succ)->data, max)) {
      max = cur;
    }
  }
  return max;
}
