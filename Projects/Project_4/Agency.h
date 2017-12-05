/*
  Sam Vernaza
  CS202
  Project_4
*/

/*
  The purpose of this program is to enhance the functionalities of C++ by
  utilizing object-oriented programming.
*/
#ifndef AGENCY_H
#define AGENCY_H

#include <fstream>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include "Car.h"


using namespace std;

class Agency {
  public:
    Agency();
    bool ReadAllData(const char * fileName);
    char * GetName();
    bool SetName(const char * srcAgency);
    bool SetZip(const int srcZip);
    void PrintAllData();
    void PrintAvailableCars(Car& allCars);

  private:
      char * m_name;
      int m_zip;
      Car m_inventory[5];
};

#endif
