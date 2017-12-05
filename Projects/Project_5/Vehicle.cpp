/*
  Sam Vernaza
  CS202
  Project_5
                          The Vehicle Implementation file
*/

#include "Vehicle.h"

int Vehicle::s_idgen = 0;

  //default constuctor
  Vehicle::Vehicle () : m_vin(GetIdgen())
  {
    cout << "Vehicle: " << m_vin << ": Default-ctor" << endl;
  }

  //parameterized constructor
  Vehicle::Vehicle (int srcVin, float * srcLLA) : m_vin(SetVin(srcVin))
  {
    SetLongLat(srcLLA);
    cout << "Vehicle " << m_vin << ": Parametrized-ctor" << endl;

  }

  //copy constructor
  Vehicle::Vehicle (const Vehicle& srcVehicle) : m_vin(srcVehicle.m_vin)
  {
    int i = 0;
    while (i < 3)
    {
      m_lla[i] = srcVehicle.m_lla[i];
      ++i;
    }
    cout << "Vehicle " << m_vin << ": Copy-ctor" << endl;
  }

  //destructor for the Vehicle
  Vehicle::~Vehicle ()
  {
    //implement as time passes
    cout << "Vehicle " << m_vin << ": Dtor" << endl;
  }

  //return the vehicle vin to the calling routine
  int Vehicle::GetVin () const
  {
      return m_vin;
  }

  //return the longitude-latitude to the calling routine
  float * Vehicle::GetLLA ()
  {
    return m_lla;
  }

  //static int random number generator
  int Vehicle::GetIdgen ()
  {
    s_idgen = ((rand()%12345) + 12345);
    return s_idgen;
  }

/*
  Move:
    Demonstrates that a vehicle cannot be moved because it doesn't have parts
*/
  void Vehicle::Move (float * srcDest)
  {
    if(!srcDest)
      return;
    cout << "Vehicle " << m_vin << ": CANNOT MOVE - I DON'T KNOW HOW" << endl;
  }

  //set the vin number for a Vehicle
  int Vehicle::SetVin (int srcVin)
  {
    if(!(srcVin >= 12345 && srcVin <= 35675))
    {
      cout << "Unable to set the this value for vin." << endl;
      cout << "Assigning a value for our system" << endl;
      return GetIdgen();
    }
    else
      return srcVin;
  }

  /*
    SetLongLat:
      Sets the longitude-latitude of a Vehicle
      If the vehicle wasn't passed in coordinate.
      Default value is assigned (primary use for constuctor)
      Ask instructor why I get an error saying can't set a float*
      with float const[255];
  */
  bool Vehicle::SetLongLat (float * srcDest)
  {
    int i = 0;
    if(!srcDest)
    {
      while(i < 3)
        m_lla[i++] = DFLT_LLA;
    }
    else
    {
      int i = 0;
      while(i < 3)
      {
        m_lla[i] = srcDest[i];
        ++i;
      }
    }
    return true;
  }

/*
  operator<<:
    Overload the insertion operator to produce output similar to that of the
    use of cout on ostream variables.
    Expected output: "Vehicle #vin @ [lon, lat, alt]"
*/
  ostream& operator<< (ostream& os, const Vehicle& srcV)
  {
    os << "Vehicle " << srcV.m_vin << " @[";
    int i = 0;
    while(i < 2)
      os << srcV.m_lla[i++] << ", ";
    os << srcV.m_lla[i] << "]"<< endl;
    return os;
  }

/*
  operator=:
    This will allow the assignment from one class object to another extracting
    the data members of the objects as necessary and assigning those values to
    the newly created object taking the value of the rvalued object member.
*/
  Vehicle& Vehicle::operator= (const Vehicle& srcV)
  {
    int i = 0;
    while(i < 3)
    {
      m_lla[i] = srcV.m_lla[i];
      ++i;
    }
    SetVin(srcV.m_vin);

    return *this;
  }
