/*
  Sam Vernaza
  CS202
  Project_4
*/

/*
  Sensor.h:
    The purpose of this file is to store all information about the sensor of a
    particular vehicle's information. This file will deal with facilitating all
    of the information about a vehicles sensors.
*/

#ifndef SENSOR_H
#define SENSOR_H

#include <fstream>
#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;
#define MAX_CHAR_SIZE 255

class Sensor {
  public:
    Sensor();
    //parameterized sensor list
    /*
    Sensor(char * type, float extraCost, static int gps_C, static int camera_C,
    static int lidar_C, static int radar_C):
    m_type(type), m_extraCost(extraCost), m_gpsCnt(gps_C),
    m_cameraCnt(camera_C), m_lidarCnt(lidar_C), m_radarCnt(radar_C);
    */
    //copy constructor
  //  Sensor(Sensor& srcSensor);
    //get/set methods for all members
    const char * GetType() const;

    //NEED TO UNDERSTAND BETTER AND THEN PROGRAM
    float GetExtraCost(const char * srcSensor, int daysRenting);
    //DONE
    int GetGpsCnt();
    //DONE
    int GetCameraCnt();
    //DONE
    int GetLidarCnt();
    //DONE
    int GetRadarCnt();

    //DONE
    bool SetType(const char * srcType);
    //NEED TO UNDERSTAND MORE AND THEN PROGRAM
    bool SetExtraCost(float srcExtraCst);
    bool SetGpsCnt(int srcGpsCount);
    bool SetCameraCnt(int srcCameraCnt);
    bool SetLidarCnt(int srcLidarCnt);
    bool SetRadarCnt(int srcRadarCnt);
    //Get/Reset for static members to return and to reset all static member var.
    //method to check if 2 sensor objects are the same

  private:
    char * m_type;
    float m_extraCost;
    int m_gpsCnt;
    int m_cameraCnt;
    int m_lidarCnt;
    int m_radarCnt;


};

#endif
