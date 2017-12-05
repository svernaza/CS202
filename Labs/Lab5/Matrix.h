#ifndef MATRIX_H_
#define MATRIX_H_

const int MATRIXROWS = 3;
const int MATRIXCOLS = 3;

class Matrix {
 public:
  Matrix();
  Matrix(int initialValueForAllElements);
  Matrix(const Matrix& otherMatrix);
  
  Matrix Transpose();
  Matrix Diagonal();
  
  /* 
  * you might also want to implement this to return a Matrix&
  */
  void operator=(const Matrix& otherMatrix);
  
  bool operator==(const Matrix& otherMatrix) const;
  void SetElement(int rowPosition, int colPosition, int valueToSet);

  /* 
  * for extra credit, comment-out void Output(); here and its call in the main source file,
  * and implement the output function as an operator<< overload
  */
  void Output();
  
  /* 
  * for extra credit, comment-out void Input(); and its call in the main source file,
  * and implement the input function as an operator>> overload
  */
  void Input();
  
 private:
  int m_array[MATRIXROWS][MATRIXCOLS];
};

#endif //MATRIX_H_
