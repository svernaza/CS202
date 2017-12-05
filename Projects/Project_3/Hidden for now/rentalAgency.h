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

#ifndef RENTAL_AGENCY_H
#define RENTAL_AGENCY_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

//my .h files
//#include "func_list.h"
#include "carInventory.h"

using namespace std;

#define AGENCY_MAX = 3;

/*
  rentalAgency ADT:
    This ADT will implement the following:
      Get the name of the rental agency, get the zipcode of the rental office,
      and get the inventory at this location (that is where it accesses the
      the car class.
*/
struct rentalAgency {
  void setAgency(char *fileName);
  //bool getAgency(rentalAgency &agency, char *agencyName);
  void setName(char *name);
  void setZip();
  //bool getZip(rentalAgency &agency, int zipcode);
  void setInventory();
  //bool getInventory(rentalAgency &agency);
  rentalCar inventory[5];
  private:
    char *name;
    int zipcode;
};

//declare the rentalAgency ADT, implementation details are hidden from the user
//rentalAgency rentalAgency_ptr[AGENCY_MAX];

//prototypes
char *myStrCpy(char *destination, const char *source);
void getName(char name[]);

#endif
