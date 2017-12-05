/*
  Sam Vernaza
  CS202
  Project_4
*/

#include <iostream>
#include "Agency.h"

void greeting();

int main()
{
  char fileName[MAX_CHAR_SIZE];

  Agency RentACar;

  //greet the user
  greeting();
  cout << "Enter the company file to read from (include .txt)" << endl;
  cin >> fileName;
  cin.ignore(100, '\n');

  cout << "Testing ReadAllData function" << endl;
  RentACar.ReadAllData(fileName);
  cout << "Works!" << endl;
  return 0;
}

void greeting()
{
  cout << "Hello, welcome to the Rent-A-Car program." << endl;
  cout << "Our goal is to rent you the car of your dreams." << endl;
  cout << "Let's get started!" << endl;
  cout << endl << endl;
}
