#pragma once

/*DSA*/
#include "list/list.h"

//ͳһ�����б��еĸ�Ԫ��
template <typename T>
void increase(List<T>& L) {
  L.traverse(Increase<T>());
}