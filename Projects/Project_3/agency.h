/*
  Sam Vernaza
  CS202
  Project_3
*/
#include "carInventory.h"

#define AGENCY_MAX = 3;
#define CAR_MAX = 5;

struct Agency {
  //Agency();
  bool SetAgency(char *fileName, Car *rentalCar_ptr, Agency *agencyPtr);
  char name[25];
  int zipcode[5];
  Car rentalCar[5];
};
