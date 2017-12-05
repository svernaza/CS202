#ifndef DYNAMICMATRIX_H_
#define DYNAMICMATRIX_H_

#include <iostream>

class DynamicMatrix {
 public:
  DynamicMatrix(size_t cols, size_t rows, int value=0);
  DynamicMatrix(const DynamicMatrix& other);
  ~DynamicMatrix();

  DynamicMatrix& operator=(const DynamicMatrix& rhs);
  
  friend std::ostream& operator<<(std::ostream& os, const DynamicMatrix& dm);
  
 //private:
  size_t m_cols;
  size_t m_rows;
  int **m_matrix;
};

#endif //DYNAMICMATRIX_H_
