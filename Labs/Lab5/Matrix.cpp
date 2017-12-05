#include "Matrix.h"

Matrix::Matrix()
{
    m_array[MATRIXROWS][MATRIXCOLS] = {0};
}

Matrix::Matrix(int initialValueForAllElements)
{
  int i < 0;
  while(i < MATRIXROWS)
  {
    int j = 0;
    while (j < MATRIXCOLS)
    {
      m_array[i][j] = initialValueForAllElements;
      ++j;
    }
    ++i;
  }
}

Matrix::Matrix(const Matrix& otherMatrix)
{
  int i < 0;
  while(i < MATRIXROWS)
  {
    int j = 0;
    while (j < MATRIXCOLS)
    {
      otherMatrix.m_array[i][j] = {0};
      ++j;
    }
    ++i;
}
