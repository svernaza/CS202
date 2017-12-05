#ifndef INTMATRIX_H_
#define INTMATRIX_H_

#include <iostream>
template <class T>
class IntMatrix {

 friend std::ostream& operator<< < >(std::ostream& os, const IntMatrix<T>& im);

 public:
  IntMatrix(size_t cols, size_t rows, int value=0);
  IntMatrix(const IntMatrix& other);
  ~IntMatrix();

  IntMatrix<T>& operator=(const IntMatrix<T>& rhs);

  const IntMatrix<T> operator+(const IntMatrix<T>& rhs) const;

  IntMatrix<T> Transpose() const;

  void Serialize(std::ostream& os) const;

 private:
  size_t m_cols;
  size_t m_rows;
  T **m_matrix;
};

#endif //INTMATRIX_H_
