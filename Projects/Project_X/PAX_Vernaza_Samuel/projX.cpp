/*
  Sam Vernaza
  CS202
  Project_X
*/
#include <iostream>

#include "SmartPtr.h"

using namespace std;


int main(){

  cout << endl << "Testing SmartPtr Dflt-ctor" << endl;
  SmartPtr sp1;  // Default-ctor
  cout << "Default-ctor worked!" << endl;
  sp1->SetIntVal(1);
  sp1->SetDoubleVal(0.25);
  cout << "Dereference Smart Pointer 1: " << *sp1 << endl;

  cout << endl << "Testing SmartPtr Copy-ctor" << endl;
  SmartPtr sp2 = sp1;  // Copy-initalization (Copy-ctor)
  cout << "Copy Initilization worked" << endl;
  //cout << "Dereference Smart Pointer 1 Post Assignment:" << *sp1 << endl;
  //cout << "Dereference Smart Pointer 2 Post Assignment: " << *sp2 << endl;
  sp2->SetIntVal(2);
  sp2->SetDoubleVal(0.5);
  cout << "Dereference Smart Pointer 1 Post SetIntVal: " << *sp1 << endl;
  cout << "Dereference Smart Pointer 2 Post SetIntVal: " << *sp2 << endl;

  cout << endl << "Testing SmartPtr Assignment Operator" << endl;
  SmartPtr sp3;
  cout << "Default Ctor SmartPtr sp3 worked!" << endl;
  sp3 = sp1;  // Assignment operator
  cout <<"Assignment Operator Works!" << endl;
  sp3->SetIntVal(4);
  sp3->SetDoubleVal(0.0);
  cout << "Dereference Smart Pointer 1: " << *sp1 << endl;
  cout << "Dereference Smart Pointer 2: " << *sp2 << endl;
  cout << "Dereference Smart Pointer 3: " << *sp3 << endl;

  cout << endl << "Testing SmartPtr Parametrized ctor with NULLdata" << endl;
  SmartPtr spNull( NULL ); // NULL-data initialization
  cout << "SmartPtr NULL Parameterized-ctor Works!" << endl;

  cout << endl << "Testing SmartPtr Copy ctor with NULL data SmartPtr" << endl;
  SmartPtr spNull_cpy( spNull ); // NULL-data copy constructor
  cout << "SmartPtr Copy-ctor spNull_cpy worked" << endl;

  cout << endl << "Testing SmartPtr Assignment with NULLdata SmartPtr" << endl;
  SmartPtr spNull_assign;
  spNull_assign = spNull; // NULL-data assign
  cout << endl << "End-of-Scope, Destructors called in reverse order of ";
  cout << "SmartPtr creation\n (spNull_assign, spNull_cpy, spNull, ";
  cout << "sp3, sp2, sp1): " << endl;
  return 0;
}
