#include <iostream>

#include "DynamicMatrix.h"

DynamicMatrix::DynamicMatrix(size_t cols, size_t rows, int value)
  : m_cols(cols),
    m_rows(rows)
{
  if (m_cols && m_rows){  //allocate only when it makes sense
    m_matrix = new(std::nothrow) int* [m_rows];
    if (m_matrix){
      for (size_t i=0; i<m_rows; ++i){
        m_matrix[i] = new(std::nothrow) int [m_cols];
        if (m_matrix[i]){
          for (size_t k=0; k<m_cols; ++k){  //only assign values to the row we have just allocated (no [j][i] over [m_rows][m_cols], because some rows have not been allocated yet)
            m_matrix[i][k] = value;
          }
        }
        else{  //row allocation failed, cleanup everything (could retry too)
          for (; i>=0; --i){
            delete [] m_matrix[i];
	  }
          delete [] m_matrix;
          m_rows = 0;
          m_cols = 0;
          break;
        }
      }
    }
    else{
      m_rows = 0;
      m_cols = 0;
      m_matrix = NULL;
    }
  }
  else{
    m_matrix = NULL;
  }
}

DynamicMatrix::~DynamicMatrix()
{
  for (size_t i=0; i<m_rows; ++i){
    delete [] m_matrix[i];
  }
  delete [] m_matrix;
}

std::ostream& operator<<(std::ostream& os, const DynamicMatrix& dm){
  for (size_t j=0; j<dm.m_rows; ++j){
    os << "[";
    for (size_t i=0; i<dm.m_cols; ++i){
      os << " " << dm.m_matrix[j][i];
    }
    os << " ]";
    os << std::endl;
  }
  return os;
}


DynamicMatrix::DynamicMatrix(const DynamicMatrix& other)
  : m_cols(other.m_cols),
    m_rows(other.m_rows)
{
    while(*m_matrix)
      delete [] *m_matrix++;
     m_rows = 0; m_cols = 0;
      if (other.m_cols && other.m_rows){  //allocate only when it makes sense
        m_matrix = new(std::nothrow) int* [other.m_rows];
        if (m_matrix){
          for (size_t i=0; i< other.m_rows; ++i){
            m_matrix[i] = new(std::nothrow) int [other.m_cols];
            if (m_matrix[i]){
              for (size_t k=0; k<other.m_cols; ++k){  //only assign values to the row we have just allocated (no [j][i] over [m_rows][m_cols], because some rows have not been allocated yet)
                m_matrix[i][k] = other.m_matrix[i][k];
              }
            }
            else{  //row allocation failed, cleanup everything (could retry too)
              for (; i>=0; --i){
                delete [] m_matrix[i];
    	  }
              delete [] m_matrix;
              m_rows = 0;
              m_cols = 0;
              break;
            }
          }
        }
        else{
          m_rows = 0;
          m_cols = 0;
          m_matrix = NULL;
        }
      }
      else{
        m_matrix = NULL;
      }
}

DynamicMatrix& DynamicMatrix::operator=(const DynamicMatrix& rhs)
{
  if(this != &rhs)
  {
    if(rhs.m_cols && rhs.m_rows)
    {
      int i = 0;
      while ( i < m_rows)
      {
        delete [] m_matrix[i++];
      }
      delete [] m_matrix;
    }
    //allocates memory
    m_matrix = new(std::nothrow) int*[rhs.m_rows];

    m_rows = rhs.m_rows;
    m_cols = rhs.m_cols;
    for(size_t i = 0; i < rhs.m_rows; ++i)
    {
      m_matrix[i] = new int[rhs.m_cols];
    }
      int k = 0;
      while(m_matrix[k++])
      {
        for(size_t j = 0; j < rhs.m_cols; ++j)
        m_matrix[k][j] = rhs.m_matrix[k][j];
      }
    return *this;
  }
  else
    return *this;
