/*
  Sam Vernaza
  CS202
  Project_5
*/
#include "Car.h"

  /* Default constructor
      the instructions said to leave everything else blank so I did
      however I'm not sure if a default value is wanted, so I'm showing I could
      have put it there to not lose points.
      Car::Car (): m_plates("Empty")
  */
  Car::Car ()
  {
    SetThrottle(0);
    cout << "Car: " << m_vin << ": Default-ctor" << endl;
  }

  //parameterized constructor
  Car::Car (const char * srcPlates, int srcThrottle, float * srcLLA):
  m_throttle(SetThrottle(srcThrottle))
  {
    strcpy(m_plates, srcPlates);
    SetLongLat(srcLLA);
    cout << "Car " << m_vin << ": Parametrized-ctor" << endl;
  }

  //copy constructor
  Car::Car (const Car& srcCar):
    m_throttle(SetThrottle(srcCar.m_throttle))
  {
    strcpy(m_plates, srcCar.m_plates);
    int i = 0;
    while (i < 3)
    {
      m_lla[i] = srcCar.m_lla[i];
      ++i;
    }

   cout << "Car " << m_vin << ": Copy-ctor" << endl;
  }

  //destructor
  Car::~Car ()
  {
    cout << "Car " << m_vin << ": Dtor" << endl;
  }

  //overloaded insertion operator
  ostream& operator<<(ostream& os, Car& srcCar)
  {
    os << "Car: " << srcCar.GetVin();
    os << " Plates:" << srcCar.GetPlates();
    os << " Throttle:" << srcCar.GetThrottle();
    os << " LLA: @[";
    int i = 0;
    while(i < 2)
      os << srcCar.m_lla[i++] << ", ";
    os << srcCar.m_lla[i] << "]"<< endl;
    return os;
  }

/*
  operator=:
    Overloaded parameter loads the contents of one car object to another
*/
  Car& Car::operator=(const Car& srcCar)
  {
    strcpy(m_plates, srcCar.m_plates);
    SetThrottle(srcCar.m_throttle);
    int i = 0;
    while (i < 3)
    {
      m_lla[i] = srcCar.m_lla[i];
      ++i;
    }
    cout << "Car " << m_vin << ": Assignment" << endl;
    return *this;
  }

/*
  GetPlates:
    Returns the plate to the calling routine.
*/
  char * Car::GetPlates ()
  {
    return m_plates;
  }

  //get method for m_throttle
  int Car::GetThrottle () const
  {
    return m_throttle;
  }

  //set method for m_plates
  bool Car::SetPlates (const char * srcPlates)
  {
    if(!srcPlates)
      return false;
    strcpy(m_plates, srcPlates);
    return true;
  }

  //set method for m_throttle
  int Car::SetThrottle (const int srcThrottle)
  {
    if(srcThrottle < 0)
      return 0;
    m_throttle = srcThrottle;
    return m_throttle;
  }

  //drive method, take in an int value and sets the throttle speed
  bool Car::Drive (int srcThrottle)
  {
    if(srcThrottle > 0)
      m_throttle = srcThrottle;
    else
      return false;
    return true;
  }

  //move method, takes a new longitude-latitude address for the car to travel
  void Car::Move(float * srcLLA)
  {
    cout << "Driving Car: " << m_vin << " from  [";

    int i = 0;
    while(i < 2)
      cout << m_lla[i++] << ", ";
    cout << m_lla[i] << "]";
    cout << " to  [";

    i = 0;
    while(i < 3)
    {
      m_lla[i] = srcLLA[i];
      ++i;
    }

    i = 0;
    while(i < 2)
      cout << m_lla[i++] << ", ";
    cout << m_lla[i] << "]"<< endl;

    cout << "Vroom Vroom!!!!!!!" << endl;
    Drive(75);
    cout << "We're going: " << m_throttle << " mph!" << endl;
  }
