/*
  Sam Vernaza
  CS202
  Project_3
*/
/*
  The purpose of this program is to simulate different car rental companies
  inventory list as well as get an estimate for the cost of a rental from them.
  This program will be implemented using structs and and arrays, while utilizing
  the advanced features of pointers. As with project 2, this program will read
  and write using an external file and will take an already composed file as
  input from the user. This file will have the following: rental agency,
  car inventory list. The program will take this information and store data
  into a struct and use a class interface for gathering vehicle information.
  This acts as the primary source of heirarchy, thus other functions related to
  program functionality are here.
*/

#ifndef CAR_INVENTORY_H
#define CAR_INVENTORY_H

#include "ext_func.h"

using namespace std;

class Car {
  public:
    Car();
    bool SetCar(ifstream &fileIn);

    /*
    bool setYear();
    bool getYear();

    bool setMake();
    bool getModel();

    bool setModel();
    bool getModel();

    bool setPrice();
    bool getPrice();

    bool setAvailable();
    bool getAvailable();
    */
  private:
    int * m_year;
    char * m_model;
    char * m_make;
    int m_price;
    bool m_available;
};

#endif
