/*
  Sam Vernaza
  CS202
  Project_6
*/

#include "Car.h"

//default constructor
Car::Car()
{
  m_throttle = DFLT_THRTLE;
  cout << "Car: Default-ctor" << endl;
}

//parameterized constructor
Car::Car(const float * srcLLA)
{
  SetLLA(srcLLA);
  SetThrottle(DFLT_THRTLE);
  cout << "Car: Parametrized-ctor" << endl;
}

//copy constructor
Car::Car(const Car& srcCar)
{
  this->SetThrottle(srcCar.m_throttle);
  cout << "Car: Copy-ctor" << endl;
}
//virtual destructor
Car::~Car()
{
  cout << "Car: Dtor" << endl;
}

/*
  SetThrottle:
    Set's the throttle member of the car class by assigning
    the integer value passed in. If the value is less than zero than
    the default throttle value is used.
*/
void Car::SetThrottle(const int srcThrottle)
{
  if(srcThrottle < 0)
  {
    cout << "Can't be less than 0, that's braking!" << endl;
    m_throttle = DFLT_THRTLE;
  }
  m_throttle = srcThrottle;
}

/*
  GetThrottle:
    Returns the value of the throttle to the calling routine
*/
int Car::GetThrottle() const
{
  return m_throttle;
}

/*
  Drive:
    Makes the car go vroom vroom. In other words, it drives
    at the speed passed in.
*/
void Car::Drive(const int srcThrottle)
{
  if(srcThrottle < DFLT_THRTLE)
  {
    cout << "Can't be negative. Locking your brakes!" << endl;
    m_throttle = DFLT_THRTLE;
  }
  m_throttle = srcThrottle;
  cout << "We're now driving!" << endl;
}

void Car::Serialize(std::ostream& os)
{
  os << "Car @: [";
  int i = 0;
  while (i < 2)
  {
    os << m_lla[i++] << ", ";
  }
  ++i;
  os << m_lla[i] << "]";
  os << "Throttle: " << m_throttle;
}

/*
  Move:
    Overrides the Pure virtual Vehicle::Move() function.
    It then takes the new LLA location by address in order
    for the car object to move there. It then calls drive
    and passes the acceleration of 75 mph.
*/
void Car::Move(const float * srcLLA)
{
  //Drive to this destination at 75 mph
  cout << "Moving to destination: [";
  int i = 0;
  while (i < 2)
  {
    cout << srcLLA[i] << ", ";
    ++i;
  }
  cout << srcLLA[i] << "]" << endl;
  Drive(75);
  cout << "Car: DRIVE to destination, with throttle @75 " << endl;
}


/*
  operator=:
    Assign members values to the calling object based
    ont he values of another Car object.
*/
Car& Car::operator=(Car& srcCar)
{
  if(this != &srcCar) //parameter check
  {
    SetThrottle(srcCar.m_throttle);
  }
  cout << "Car: Assignment" << endl;
  return *this;
}
