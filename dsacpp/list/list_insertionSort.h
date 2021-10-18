#pragma once

//列表插入排序，起始位置p的n个元素
template <typename T>
void List<T>::insertionSort(ListNodePosi<T> p,
                            int n) {  // valid(p) && rank(p) + n <= size
  for (int r = 0; r < n; r++) {
    insert(search(p->data, r, p),
           p->data);  // [0, r]区间内找到不大于data的节点，插入其后
    p = p->succ;
    remove(p->pred);
  }  // n次迭代，每次o(r + 1)
}