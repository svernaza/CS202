#include <iostream>

#include "DynamicMatrix.h"

DynamicMatrix::DynamicMatrix(int rows, int cols)
  : m_rows(rows),
    m_cols(cols)
{
  m_matrix = new int *[rows];
  int i = 0;
  while (i < rows)
  {
    m_matrix[i] = new int [cols];
    ++i;
  }
  /* your code here */
}

DynamicMatrix::~DynamicMatrix()
{
  int i = 0;
  while (i < m_rows)
  {
    delete [] m_matrix[i];
    ++i;
  }
  delete [] m_matrix;
  /* your code here */
}

std::ostream& operator<<(std::ostream& os, const DynamicMatrix& dm){
  for (int j=0; j<dm.m_rows; ++j){
    for (int i=0; i<dm.m_cols; ++i){
      os << dm.m_matrix[j][i] << " ";
    }
    os << std::endl;
  }
  return os;
}
