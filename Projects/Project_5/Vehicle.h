/*
  Samuel Vernaza
  CS202
  Project_5
                  Contains the Vehicle class (Base Class)
*/

#ifndef _VEHICLE_H
#define _VEHICLE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;


const float DFLT_LLA = 0.0;
class Vehicle
{
  public:
    //default constuctor
    Vehicle ();
    //parameterized constructor (look up)
    Vehicle (int srcVin, float * srcLLA);
    //copy constructor (look up)
    Vehicle (const Vehicle& srcVehicle);
    //destructor for the Vehicle w/debug output
    ~Vehicle ();
    //overloaded insertion operator w/debug output
    friend ostream& operator<<(ostream& os, const Vehicle& srcV);
    //overloaded assignment operator w/debug output
    Vehicle& operator= (const Vehicle& srcV);
    //return the vehicle vin to the calling routine
    int GetVin () const;
    //return the longitude-latitude to the calling routine
    float * GetLLA ();
    //generates a random ID for the s_idgen variabled
    static int GetIdgen();
    //move a Vehicle
    void Move(float * srcDest);
    //set the longitude-latitude for a Vehicle
    bool SetLongLat (float * srcDest);
  protected:
    //longitude-latitude coordinate of the Vehicle
    float m_lla [3];
    //Vehicle vin number
    const int m_vin;

  private:
      static int s_idgen;
      static int SetVin (int srcVin);
};

#endif //_VEHICLE_H
