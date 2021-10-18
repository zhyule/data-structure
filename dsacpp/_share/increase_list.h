#pragma once

/*DSA*/
#include "list/list.h"

//统一递增列表中的各元素
template <typename T>
void increase(List<T>& L) {
  L.traverse(Increase<T>());
}