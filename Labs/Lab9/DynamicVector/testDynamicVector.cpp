#include <iostream>

#include "DynamicVector.h"

using namespace std;

int main(){

  ///////////////////////////
  /////  DynamicVector  /////
  ///////////////////////////
  size_t size = 0;
  int val_dv1 = 1, val_dv2 = 2;
  cout << "Input the size of the DynamicVector objects:" << endl;
  cin >> size;
  cout << "Input the initializing value for 1st DynamicVector elements:" << endl;
  cin >> val_dv1;
  cout << "Input the initializing value for 2nd DynamicVector elements:" << endl;
  cin >> val_dv2;

  DynamicVector dynamic_vector_1(size, val_dv1);
  DynamicVector dynamic_vector_2(size, val_dv2);
  cout << endl << "Dynamic Vector object 1:" << endl << dynamic_vector_1 << endl;
  cout << endl << "Dynamic Vector object 2:" << endl << dynamic_vector_2 << endl;

  DynamicVector dynamic_vector_3(0);
  cout << endl << "Uninitialized Dynamic Vector object 3:" << endl << dynamic_vector_3 << endl;

  dynamic_vector_3 = dynamic_vector_1+dynamic_vector_2;
  cout << endl << "Dynamic Vector object 3 = Dynamic Vector object 1 + Dynamic Vector object 2" << endl << dynamic_vector_3 << endl;

  DynamicVector dynamic_vector_3_expanded = dynamic_vector_3.Expanded();
  cout << endl << "Expanded (to twice the original size) Dynamic Vector object 3" << endl << dynamic_vector_3_expanded << endl;

  return 0;
}
