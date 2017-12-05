/*
  Sam Vernaza
  CS202
  Project_6
*/

#include "Vehicle.h"

//default constructor
Vehicle::Vehicle ()
{
  cout << "Vehicle: Default-ctor" << endl;
}

//parameterized constructor
Vehicle::Vehicle(const float * srcLLA)
{
  SetLLA(srcLLA);
  cout << "Vehicle: Parameterized-ctor" << endl;
}

//copy constuctor
Vehicle::Vehicle(const Vehicle& srcV)
{
  SetLLA(srcV.m_lla);
  cout << "Vehicle: Copy-ctor" << endl;
}

//virtual destructor
Vehicle::~Vehicle ()
{
  cout << "Vehicle: Dtor" << endl;
}

/*
  Serialize:
    Acts like an overloaded ostream operator
    for virtual functions and ensures that
    the output is formated for whatever
    kind of object is invoking it.
*/
void Vehicle::Serialize (ostream& os)
{
  os << "Vehicle @: [";
  int i = 0;
  while (i < 2)
  {
    os << m_lla[i++] << ", ";
  }
  ++i;
  os << m_lla[i] << "]";
}

/*
  operator=
    Assigns the value of on object to another object
    that invokes it using that assignment operator.
    The special pointer this is used to check against
    self copying and to ensure the simplest function
    is being used.
*/
Vehicle& Vehicle::operator=(const Vehicle& srcV)
{
  cout << "Vehicle: Assignment" << endl;
  if(this != &srcV)
  {
    SetLLA(srcV.m_lla);
  }
    return *this;
}

/*
  SetLLA:
    Sets the longitude-latitude-altitude coordinates
    for the m_lla member.
*/
void Vehicle::SetLLA (const float * srcLLA)
{
  if(!srcLLA)
    return;
  int i = 0;
  while (i < MAX_SIZE)
  {
    m_lla[i] = srcLLA[i];
    ++i;
  }
}

/*
  GetLLA:
    returns the value of the m_lla to the calling routine
*/
const float * Vehicle::GetLLA() const
{
  return m_lla;
}

/*
void Vehicle::Move(const float * srcLLA)
{
  //SetLLA(srcLLA);
}
*/
/*
  operator<<:
    overloaded operator for the insertion operator. Calls the Serialize
    function to work with a virtual method.
*/
ostream& operator<<(ostream& os, Vehicle& srcV)
{
  srcV.Serialize(os);
  return os;
}
