#pragma once

template <typename T>
void List<T>::traverse(void (*visit)(T&)) {
  for (ListNodePosi<T> p = header->succ; p != trailer; p = p->succ) {
    visit(
        p->data);  // ���б��б�������ͱ���ִ��visit��visit�ǽ���T���͵�������Ϊ����������void�ĺ���ָ��
  }
}

template <typename T> template <typename VST>
void List<T>::traverse(VST& visit) {
  for (ListNodePosi<T> p = header->succ; p != trailer; p = p->succ) {
    visit(
        p->data);  // visitӦ����������()�������Ķ���list�����˷������ʶ�visitҲ���Խ��ܶ���Ԫ������
  }
}