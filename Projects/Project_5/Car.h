/*
  Samuel Vernaza
  CS202
  Project_5
                    Car class header file (Derived Class)
*/

#ifndef _CAR_H
#define _CAR_H

#include "Vehicle.h"

const int MAX = 255;

class Car: public Vehicle
{
  public:
    //default constructor
    Car ();
    //parameterized constructor
    Car (const char * srcPlates, int srcThrottle, float * srcLLA);
    //copy constructor
    Car (const Car&);
    //destructor
    ~Car ();
    //overloaded << operator
    friend ostream& operator<<(ostream& os, Car& srcCar);
    //assignment overloaded operator
    Car& operator=(const Car& srcCar);
    //get method for m_plates
    char * GetPlates ();
    //get method for m_throttle
    int GetThrottle () const;
    //set method for m_plates
    bool SetPlates (const char * srcPlates);
    //set method for m_throttle
    int SetThrottle (const int srcThrottle);
    //drive method, take in an int value and sets the throttle speed
    bool Drive (int srcThrottle);
    //move method, takes a new longitude-latitude address for the car to travel
    void Move(float * srcLLA);

  private:
    char m_plates[MAX];
    int m_throttle;
};

#endif //end _CAR_H
