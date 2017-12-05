#include <iostream>

#include "DynamicMatrix.h"

using namespace std;

int main(){

  ///////////////////////////
  /////  DynamicMatrix  /////
  ///////////////////////////
  size_t rows = 0, cols = 0;
  int val_dm1 = 1, val_dm2 = 2;
  cout << "Input the columns and then the rows of the DynamicMatrix object:" << endl;
  cin >> cols >> rows;
  cout << "Input the initializing value for 1st DynamicMatrix elements:" << endl;
  cin >> val_dm1;
  cout << "Input the initializing value for 2nd DynamicMatrix elements:" << endl;
  cin >> val_dm2;

  DynamicMatrix dynamic_matrix_1(cols, rows, val_dm1);
  DynamicMatrix dynamic_matrix_2(cols, rows, val_dm2);
  cout << endl << "Dynamic Matrix object 1:" << endl << dynamic_matrix_1 << endl;
  cout << endl << "Dynamic Matrix object 2:" << endl << dynamic_matrix_2 << endl;

  DynamicMatrix dynamic_matrix_1_cpy( dynamic_matrix_1 );
  cout << endl << "Dynamic Matrix object 1 Copy:" << endl << dynamic_matrix_1_cpy << endl;

  DynamicMatrix dynamic_matrix_2_assign(0,0); 
  dynamic_matrix_2_assign = dynamic_matrix_2;
  cout << endl << "Dynamic Matrix object 2 Assign:" << endl << dynamic_matrix_2_assign << endl;

  return 0;
}
