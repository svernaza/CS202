/*
  Sam Vernaza
  CS202
  Project_4
*/

#include "Sensor.h"

//implement
Sensor::Sensor()
{
  m_type = NULL;
  m_extraCost = 0.0;
  m_gpsCnt = 0;
  m_cameraCnt = 0;
  m_lidarCnt = 0;
  m_radarCnt = 0;
}

//create parameterized sensor list

/*
  Sensor:
    Copy constructor for a sensor object

Sensor::Sensor(Sensor& srcSensor)
{
  m_type = new char [strlen(srcSensor.m_type) + 1];
  strcpy(m_type, srcSensor.m_type);
  m_extraCost = srcSensor.m_extraCost;
  m_gpsCnt = srcSensor.m_gpsCnt;
  m_cameraCnt = srcSensor.m_cameraCnt;
  m_lidarCnt = srcSensor.m_lidarCnt;
  m_radarCnt = srcSensor.m_radarCnt;
}
*/
/*
  GetType:
    Returns the type of the sensor of the current object.
*/
const char * Sensor::GetType() const
{
  return m_type;
}

/*
  GetExtraCost:
    Returns a value for each additional cost for each day of use of
    an sensor item. This function will need to be passed in a value
    so that it can calculate the days of use and return the value
    of the extra cost.
*/
float Sensor::GetExtraCost(const char * srcSensor, int daysRenting)
{
    //will need to pass in a character array and stringcompare it with
    //each possible sensor type. when a match is found the cost for that
    //time the number of days is computed and returned to the calling routine
    //will need a while loop to cycle through each sensor.
    //will need to string compare each value of the sensor array

  if(daysRenting < 1)
    return 0.00;

  if(strcmp("gps", srcSensor) == 0)
    return (5.00 * daysRenting);

	if(strcmp("camera", srcSensor) == 0)
		return (10.00 * daysRenting);

	if(strcmp("lidar", srcSensor) == 0)
		return (15.00 * daysRenting);

	if(strcmp("radar", srcSensor) == 0)
		return (20.00 * daysRenting);
//nothing case
  return 0.00;
}

/*
  GetGpsCnt:
    Returns the count of the GPS units
*/
int Sensor::GetGpsCnt()
{
  return m_gpsCnt;
}

/*
  GetCameraCnt:
    Returns the camera count.
*/
int Sensor::GetCameraCnt()
{
  return m_cameraCnt;
}

/*
  GetLidarCnt:
    Returns the lidar count.
*/
int Sensor::GetLidarCnt()
{
    return m_lidarCnt;
}

/*
  GetRadarCnt:
    Returns the radar count.
*/
int Sensor::GetRadarCnt()
{
    return m_radarCnt;
}

/*
  SetType:
    Takes a constant character pointer from the passed in source
    and assigns its value to the objects type value by performing
    a deep copy of the source type.
*/
bool Sensor::SetType(const char * srcType)
{
  //check there is a source type and
  if(!srcType)
    return false;

  //assign the value to the type

  m_type = new char[strlen(srcType) + 1];
  strcpy(m_type, srcType);
  cout << "String copy was successful" << endl;
  return true;
}

//need to make this!
//bool SetExtraCost(const float srcExtraCst);

/*
  SetGpsCnt:
    Takes the source count. Assigns the value to
    the member gps count.
*/
bool Sensor::SetGpsCnt(int srcCount)
{
  if(srcCount < 0)
    return false;

  m_gpsCnt = srcCount;
  return true;
}

/*
  SetCameraCnt:
    Sets the static member for the count of the program
*/
bool Sensor::SetCameraCnt(int srcCameraCnt)
{
  if(srcCameraCnt < 0)
    return false;

  m_cameraCnt = srcCameraCnt;
  return true;
}

/*
  SetLidarCnt:
    Set the lidar count given a static member passed to it
*/
bool Sensor::SetLidarCnt(int srcLidarCnt)
{
    if(srcLidarCnt < 0)
      return false;
    m_lidarCnt = srcLidarCnt;
    return true;
}

/*
  setRadarCnt:
    Sets the radar count for the object.
*/
bool Sensor::SetRadarCnt(int srcRadarCnt)
{
  if(srcRadarCnt < 0)
    return 0;
  m_radarCnt = srcRadarCnt;
  return true;
}
