/*
  Samuel Vernaza
  CS202
  Project_4
*/

/*
  Car.h:
    The purpose of this file is to give an overview of the details about the
    Car class and its primary pupose. The Car class will hold a make, model,
    year, sensor (Class object) of size 3, baseprice, finalprice, availability,
    the owner of the car (if applicable).

    This class also includes, the default, parameterized, and copy constructors.
    Get methods and set methods, except for those of the sensor class and final
    price. Update price (method to update the final price after changes.
    Print, prints all of a car's data. EstimateCost will give price estimates
    if the number of days are included.
    */

#ifndef CAR_H
#define CAR_H

#include "Sensor.h"

class Car {
  public:
  Car();

  //parameterized constructor
  Car(char * srcMake, char * srcModel, int srcYear, Sensor & srcSensor,
  float srcBasePrice, float srcFinalPrice, bool srcAvailable, char * srcOwner);
  //copy constructor
  Car(Car &srcCar);

  //need parameterized constructor list
  //need copy constructor
  //get methods
  char * GetMake();
  char * GetModel();
  int GetYear();
  Sensor * GetSensor();
  float GetBasePrice();
  float GetFinalPrice();
  bool GetAvailability();
  char * GetOwner();
  //set methods
  bool SetYear(const int srcYear);
  bool SetMake(const char * srcMake);
  bool SetModel(const char * srcModel);
  bool SetSensor(const char* srcSensor);
  bool SetBasePrice(const float srcBasePrice);
  bool SetFinalPrice(const float srcFinalPrice);
  bool SetAvailability(const bool srcAvailable);
  bool SetOwner(const char * srcOwner);
  //updateprice
  //print
  //EstimateCost
  //AddSensor()
  //AddLessee()

  private:
    int m_year;
    char * m_make;
    char * m_model;
    Sensor m_sensor[3];
    float m_basePrice;
    float m_finalPrice;
    bool m_available;
    char * m_owner;
};

#endif
