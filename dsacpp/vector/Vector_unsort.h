#pragma once

//等概率随机置乱区间[lo, hi)
template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi) {
  T* V = _elem + lo; //将子向量_elemp[lo, hi)视作另一向量[0, hi - lo)
  for (Rank i = hi - lo; i > 0; i--) {  // 自后向前
    swap(V[i - 1], V[rand() % i]); //将V[i - 1]与V[0, i)中某一元素随机交换
  } 
}