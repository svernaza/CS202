#ifndef DYNAMICMATRIX_H_
#define DYNAMICMATRIX_H_

#include <iostream>

class DynamicMatrix {
 public:
  DynamicMatrix(int rows, int cols);
  
  ~DynamicMatrix();

  friend std::ostream& operator<<(std::ostream& os, const DynamicMatrix& dm);
  
 private:
  int m_rows;
  int m_cols;
  int **m_matrix;
};

#endif //DYNAMICMATRIX_H_
