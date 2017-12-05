/*
  Sam Vernaza
  CS202
  Project_4
*/

#include "Car.h"

//default constructor
Car::Car()
{
  m_year = 0;
  m_make = NULL;
  m_model = NULL;
  m_basePrice = 0.0;
  m_finalPrice = 0.0;
  m_available = false;
  m_owner = NULL;
}

/*
//parameterized constructor
Car::Car(char * srcMake, char * srcModel, int srcYear, Sensor &srcSensor,
  float srcBasePrice, float srcFinalPrice, bool srcAvailable, char * srcOwner)
{
  m_make = srcMake;
  m_model = srcModel;
  m_year = srcYear;

  //use the sensor copy constructor
  Sensor m_sensor(srcSensor);
  m_basePrice = srcBasePrice;
  m_finalPrice = srcFinalPrice;
  m_available = srcAvailable;

  m_owner = new char [strlen(m_owner) + 1];
  strcpy(m_owner, srcOwner);
}

//copy constructor
Car::Car(Car &srcCar)
{
  m_make = new char (strlen(srcCar.m_make) + 1);
  m_make = srcCar.m_make;

  m_make = new char (strlen(srcCar.m_model) + 1);
  m_make = srcCar.m_model;

  m_year = srcCar.m_year;

  //get the address of the m_sensor array's first element
  Sensor *p_sensor = srcCar.m_sensor;
  int i = 0;
  while(p_sensor)
  {
    m_sensor[i] = p_sensor;
    ++p_sensor;
    ++i;
  }
  Pointer implementation
  while(p_sensor)
  {
    *m_sensor = p_sensor->srcCar.m_sensor;
    ++p_sensor;
  }

  m_basePrice = srcCar.m_basePrice;
  m_finalPrice = srcCar.m_finalPrice;
  m_available = srcCar.m_available;

  m_owner = new char [strlen(m_owner) + 1];
  strcpy(m_owner, srcCar.m_owner);

}
*/

/*
  GetMake:
    Get the make of the current object
*/
char * Car::GetMake()
{
  return m_make;
}

/*
  GetModel:
    Get the model of the current object
*/
char * Car::GetModel()
{
  return m_model;
}

/*
  GetYear:
    Get the year of the current object
*/
int Car::GetYear()
{
  return m_year;
}

/*
  GetSensor:
    Gets an array of the sensors of the current object
*/
Sensor * Car::GetSensor()
{
  return m_sensor;
}

/*
  GetBasePrice:
    Returns the base price of the vehicle of the current object
*/
float Car::GetBasePrice()
{
  return m_basePrice;
}
/*
  GetFinalPrice:
    returns the final price of the current object
*/
float Car::GetFinalPrice()
{
  return m_finalPrice;
}
/*
  GetAvailability:
    Returns the boolean value of availability of the current object
*/
bool Car::GetAvailability()
{
    return m_available;
}
/*
  GetOwner:
    Returns the owner of the current object if there is one.
    Otherwise the default value of null is returned.
*/
char * Car::GetOwner()
{
    return m_owner;
}

/*
  SetYear:
    Takes the year pass in and assigns it to the member.
*/
bool Car::SetYear(const int srcYear)
{
  if(srcYear < 0)
    return false;

    m_year = srcYear;
    return true;
}

/*
  SetMake:
    Sets the make of the vehicle given a character array passed to it.
*/
bool Car::SetMake(const char * srcMake)
{
  if(!srcMake)
    return false;

  m_make = new char [strlen(srcMake) + 1];
  strcpy(m_make, srcMake);
  return true;
}

/*
  SetModel:
    Assigns the value of the character string being passed in to the member
*/
bool Car::SetModel(const char * srcModel)
{
  if(!srcModel)
    return false;

  //change to my implementation
  m_model = new char[strlen(srcModel) + 1];
  strcpy(m_model, srcModel);
  return true;
}

/*
  SetBasePrice:
    Set the price from the value passed into it.
*/
bool Car::SetBasePrice(const float srcBasePrice)
{
  if(srcBasePrice < 0)
    return false;

  m_basePrice = srcBasePrice;
  return true;
}

/*
  SetSensor:
    Takes an object sensor and copies its values into the member sensor.
    This will need to be an array of sensor.
    Attempted to make an implementation that ripped apart the brackets using
    pointers. Keeps segfaulting and I can't find the problem.
    Though this will end up costing me points, I made this section using
    array notation.

*/

bool Car::SetSensor(const char * srcSensor)
{
  if(!srcSensor)
    return false;
  
}

/*
  Another failed implementation of my sensor. I'm just going to read in
  the sensor as is and try to work with that implementation.

bool Car::SetSensor(const char * srcSensor)
{
  //set up a sensor ptr
  //Sensor *sensor_ptr = m_sensor;
  char tempSensor[50];
  int i = 0;
  while(srcSensor)
  {
    if(srcSensor[i] == '{')
      ++i;
    while(srcSensor[i] != ' ')
    {
      tempSensor[i] = srcSensor[i];
      cout << "Passing control to SetType" << endl;
      ++i;
    }
    m_sensor[i].SetType(tempSensor);
    if(srcSensor[i] == '}')
      break;
    ++i;
  }
  return true;
}
*/
/* No longer in use because of seg fault issues

bool Car::SetSensor(const char * srcSensor)
{
  cout << "In SetSensor" << endl;
  if(!srcSensor)
    return false;

  char *tempSensor = new char[strlen(srcSensor) + 1];
  Sensor *sensor_p = m_sensor;

  cout << "Above SetSensor loop" << endl;
  while(srcSensor != NULL)
  {
    //if the value is a bracket skip it
    cout << "Above { check" << endl;
    if(*srcSensor == '{')
      ++srcSensor;
	//while a space isn't encountered store the into the pointer

	  while(*srcSensor != ' ')
		  *tempSensor++ = *srcSensor++;
	//set the Cars sensor and increment the pointer to the next index
    cout << "Passing control to SetType" << endl;
	  sensor_p->SetType(tempSensor);
	  ++sensor_p;

	if(*srcSensor == '}')
      break;
  }

  return true;
}
*/
/*
  SetFinalPrice:
    Set the final price based on the number of sensors and other data that
    is coming into the function.

bool SetFinalPrice(const float srcFinalPrice)
{
  if(srcFinalPrice < 0)
}
*/

/*
  SetAvailability:
    Availability will be set according to a cars information read into the
    function.
*/
bool Car::SetAvailability(const bool srcAvailable)
{
  m_available = srcAvailable;
  return true;
}

bool Car::SetOwner(const char * srcOwner)
{
  if(!srcOwner)
  {
    m_owner = new char [strlen("None") + 1];
    strcpy(m_owner, "None");
  }
  m_owner = new char [strlen(srcOwner) + 1];
  strcpy(m_owner, srcOwner);
  return true;
}
