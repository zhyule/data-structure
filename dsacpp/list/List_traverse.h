#pragma once

template <typename T>
void List<T>::traverse(void (*visit)(T&)) {
  for (ListNodePosi<T> p = header->succ; p != trailer; p = p->succ) {
    visit(
        p->data);  // 对列表中保存的类型遍历执行visit，visit是接受T类型的引用作为参数，返回void的函数指针
  }
}

template <typename T> template <typename VST>
void List<T>::traverse(VST& visit) {
  for (ListNodePosi<T> p = header->succ; p != trailer; p = p->succ) {
    visit(
        p->data);  // visit应该是重载了()操作符的对象，list经过了泛化，故而visit也可以接受多种元素类型
  }
}