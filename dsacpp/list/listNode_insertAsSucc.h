#pragma once

template <typename T>
ListNodePosi<T> ListNode<T>::insertAsSucc(T const& e) {
	ListNodePosi<T> x = new ListNode(e, this, succ); // �����½ڵ�
	succ->pred = x; // e -> succ
	succ = x; // this -> e
	return x; // �����µĽڵ�λ��
}