/*
  Sam Vernaza
  CS202
  Project_3
*/

#include "ext_func.h"

class Car
{
  public:
    Car();
    SetCar(ifstream &readFile);

  private:
    int * m_year;
    char *m_make;
    char *m_model;
    char *m_price;
};
