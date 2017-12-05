/*
  Sam Vernaza
  CS202
  Project_6
*/

#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"

#include <iostream>
using namespace std;

const int DFLT_THRTLE = 0;

class Car : public Vehicle
{
private:
  //assignment reads that m_throttle should be private. I think it should
  //be protected but I will leave it just in case.
  int m_throttle;
  virtual void Serialize(std::ostream& os);

public:
  Car();
  Car (const float * srcLLA);
  Car(const Car& srcCar);
  virtual ~Car ();
  void SetThrottle(const int srcThrottle);
  int GetThrottle() const;
  void Drive(const int srcThrottle);
  virtual void Move(const float * srcLLA);
  Car& operator=(Car& srcCar);
};

#endif
