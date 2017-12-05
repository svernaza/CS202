/*
  Samuel Vernaza
  CS202
  Project_6
*/

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

using namespace std;

const int MAX_SIZE = 3;
const float DFLT_LLA [3] = {0.0F, 0.0F, 0.0F};

class Vehicle
{
  friend ostream& operator<<(ostream& os, Vehicle& srcV);
protected:
  float m_lla[MAX_SIZE];

private:
  virtual void Serialize (std::ostream& os);

public:

  Vehicle();
  //Parameterized-ctor
  Vehicle(const float * srcLLA);
  //Copy-ctor
  Vehicle(const Vehicle& srcV);
  virtual ~Vehicle ();
  Vehicle& operator=(const Vehicle& srcV);
  void SetLLA(const float * srcLLA);
  const float * GetLLA() const;
  virtual void Move(const float * srcLLA) = 0;
};

#endif
