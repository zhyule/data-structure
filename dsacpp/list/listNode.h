#pragma once

using Rank = int; // ��
template <typename T> struct ListNode;
template <typename T> using ListNodePosi = ListNode<T>*; // �ڵ�ĵ�ַ����Ψһ��
template <typename T> struct ListNode {
	T data; // ��ֵ
	ListNodePosi<T> pred; // ǰһ��
	ListNodePosi<T> succ; // ��һ��
	ListNode() {}
	ListNode(T e, ListNodePosi<T> p = NULL, ListNodePosi<T> s = NULL) :
		data(e), pred(p), succ(s) {} // Ĭ�Ϲ�����
	ListNodePosi<T> insertAsPred(T const& e); //���浱ǰ�ڵ�ǰ�����½ڵ�
	ListNodePosi<T> insertAsSucc(T const& e); //���浱ǰ�ڵ������½ڵ�
};

#include "listNode_implementation.h"