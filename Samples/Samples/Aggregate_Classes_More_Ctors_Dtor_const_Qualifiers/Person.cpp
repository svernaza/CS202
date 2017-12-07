#include <iostream>

#include <cstring> 

#include "Person.h"  

int Person::s_count = 0;

// For Default ctors, it is generally a good idea to leave as much of the data AS POSSIBLE in an uninitialized state to avoid incurring the overhead of copy-constructing/initializing them
// Note: "as much AS POSSIBLE" means that guaranteed functionality considerations always come first, and any possible optimizations come after that
Person::Person() :
  //m_age(DEFAULT_AGE)
  m_gender(DEFAULT_GENDER) 
{
  // Only used for debugging purposes
  std::cout << "Person Default ctor" << std::endl;

  // Increase the count of existing objects
  ++s_count;
}

Person::Person(const char* name, int age, char gender) :
  m_age(age) ,  								
  m_gender(   gender == GENDER_MALE ? GENDER_MALE :			 
            ( gender == GENDER_FEMALE ? GENDER_FEMALE : DEFAULT_GENDER )
          )
{
  // Only used for debugging purposes
  std::cout << "Person Parametrized ctor" << std::endl;

  SetName(name);
  
  // Increase the count of existing objects
  ++s_count;
}

Person::Person(const Person& other) : 
  m_age(other.m_age) , 		
  m_gender(other.m_gender)  	
{
  // Only used for debugging purposes
  std::cout << "Person Copy ctor" << std::endl;

  SetName(other.m_name);

  // Increase the count of existing objects
  ++s_count;
}

Person::~Person(){
  // Only used for debugging purposes
  std::cout << "Person Dtor" << std::endl;

  // Decrease the count of existing objects
  --s_count;
}

Person& Person::operator=(const Person& rhs){
  if (this != &rhs){
    SetGender(rhs.m_gender);
    SetAge(rhs.m_age);
    SetName(rhs.m_name);
  }
  return *this;  
}

Person& Person::operator+(int years){
  m_age += years;
  return *this;  
}

Person& Person::operator+(const char *name_suffix){
  strcat(m_name, name_suffix);
  return *this;  
}

const char* Person::GetName() const{ 
  return m_name;
}

void Person::SetName(const char* name){
  strcpy(m_name, name);
}

int Person::GetAge() const{ 
  return m_age;
}

void Person::SetAge(int age){
  m_age = age;
}

char Person::GetGender() const{  
  return m_gender;
}

void Person::SetGender(char gender){
  m_gender = gender == GENDER_MALE ? GENDER_MALE :			 
            ( gender == GENDER_FEMALE ? GENDER_FEMALE : DEFAULT_GENDER );
}


int Person::GetCount(){
  return s_count;
}


std::ostream& operator<<(std::ostream& os, const Person& p){
  os << "Name: " << p.m_name << ",\tAge: " << p.m_age << ",\tGender: " << p.m_gender; 
  return os;  
}

std::istream& operator>>(std::istream& is, Person& p){
  is >> p.m_name >> p.m_age >> p.m_gender;
  return is;  
}
