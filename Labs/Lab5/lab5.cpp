#include <iostream>

#include "Matrix.h"

using namespace std;

int main(){
  
  Matrix matrix;
  
  cout<<"Enter elements of 3x3 matrix :"<<endl;
  matrix.Input();

  cout<<"Matrix :"<<endl;
  matrix.Output();

  Matrix transposeMatrix = matrix.Transpose();
  cout<<"Matrix Transpose :"<<endl;
  transposeMatrix.Output();
  
  cout<<"The matrix is"<< (matrix==transposeMatrix?" ":" not ") << "symmetric"<<endl;
  
  Matrix diagonalMatrix = matrix.Diagonal();
  cout<<"Diagonal-elements Matrix :"<<endl;
  diagonalMatrix.Output();
  
  Matrix transposeDiagonalMatrix = diagonalMatrix.Transpose();
  cout<<"Transpose of diagonal-elements matrix :"<<endl;
  transposeDiagonalMatrix.Output();

  cout<<"The Diagonal Elements matrix is"<< (diagonalMatrix==transposeDiagonalMatrix?" ":" not ") <<"symmetric"<<endl;	
	
  return 0;
}
