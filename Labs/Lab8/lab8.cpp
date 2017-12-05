#include <iostream>

#include "DynamicMatrix.h"

using namespace std;

int main(){
  
  int rows = 0, cols = 0;
  cout << "Please input the rows and then the columns of the DynamicMatrix object:" << endl;
  cin >> rows >> cols;

  DynamicMatrix dynamic_matrix(rows, cols);
  
  cout << endl << "Dynamic Matrix of " << rows << " rows and " << cols << " cols:" << endl;
  cout << dynamic_matrix << endl;

  return 0;
}
