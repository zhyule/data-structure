#pragma once

using Rank = int; // 秩
template <typename T> struct ListNode;
template <typename T> using ListNodePosi = ListNode<T>*; // 节点的地址才是唯一的
template <typename T> struct ListNode {
	T data; // 数值
	ListNodePosi<T> pred; // 前一个
	ListNodePosi<T> succ; // 后一个
	ListNode() {}
	ListNode(T e, ListNodePosi<T> p = NULL, ListNodePosi<T> s = NULL) :
		data(e), pred(p), succ(s) {} // 默认构造器
	ListNodePosi<T> insertAsPred(T const& e); //紧随当前节点前插入新节点
	ListNodePosi<T> insertAsSucc(T const& e); //紧随当前节点后插入新节点
};

#include "listNode_implementation.h"