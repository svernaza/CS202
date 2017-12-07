#include "Department.h"

// Note: A const-qualified function is called on a const-qualified object, this means that within the implementation of the function the implicit "this->" that is inserted whenever you are
// referring to member variables (e.g. "m_roster" is treated by the compiler as if it read "this->m_roster") is a const-qualified pointer!
// This means that you CANNOT do the following as "this->m_roster: has also becoma a const-qualified array because "this" is const-qualified itself
//   Person* Department::GetRoster() const{
//     return m_roster;
//   } 

// const-qualified Getter function, way to access internal data by-const-Address
const Person* Department::GetRoster() const{
  return m_roster;
}

// Note: Here on the other hand that the implicit "this->" is no longer const-qualified you may safely return a non-const pointer to the array

// non-const-qualified Getter function, way to access internal data by-Address
Person* Department::GetRoster(){
  return m_roster;
}

// const-qualified operator[] function overload, way to access internal data by-const-Reference
const Person& Department::operator[](int i) const{
  return m_roster[i];
}

// non-const-qualified operator[] function overload, way to access internal data by-Reference
Person& Department::operator[](int i) {
  return m_roster[i];
}


// Outputs the m_roster data: Exploits the fact that operator<< is oveloaded already for Person objects by the class Person itself
std::ostream& operator<<(std::ostream& os, const Department& d){
  for (int i=0; i<MAX_PEOPLE; ++i){
    os << d.m_roster[i] << std::endl;
  }
  return os;
}

// Inputs m_roster data: Exploits the fact that operator>> is oveloaded already for Person objects by the class Person itself
std::istream& operator>>(std::istream& is, Department& d){
  for (int i=0; i<MAX_PEOPLE; ++i){
    is >> d.m_roster[i];
  }
  return is;
}


