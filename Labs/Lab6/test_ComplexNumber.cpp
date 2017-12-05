#include <iostream>

#include "ComplexNumber.h"

using namespace std;

int main(){
  
  ComplexNumber cn_Default;
  cout << "cn_Default:\t" << cn_Default << endl;
  cout << "cn_Count: " << ComplexNumber::GetCount() << endl;

  ComplexNumber cn_A(1, 2);
  ComplexNumber cn_B(3, 4);
  cout << "cn_A:\t" << cn_A << endl;
  cout << "cn_B:\t" << cn_B << endl;
  cout << "cn_Count: " << ComplexNumber::GetCount() << endl;

  ComplexNumber cn_C(cn_Default);
  cout << "cn_C (cn_Default):\t" << cn_C << endl;
  cout << "cn_Count: " << ComplexNumber::GetCount() << endl;

  cn_C = cn_A + cn_B;
  cout << "cn_C (=cn_A+cn_B):\t" << cn_C << endl;
  cout << "cn_Count: " << ComplexNumber::GetCount() << endl;

  return 0;
}

