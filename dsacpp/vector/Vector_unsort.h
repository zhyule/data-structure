#pragma once

//�ȸ��������������[lo, hi)
template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi) {
  T* V = _elem + lo; //��������_elemp[lo, hi)����
  for (Rank i = hi - lo; i > 0; i--) {  // �Ժ���ǰ
    swap(V[i - 1], V[rand() % i]); //��V
  }
}