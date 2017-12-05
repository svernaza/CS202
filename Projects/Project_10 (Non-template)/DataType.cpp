#include "DataType.h"

#include <cstdlib>

DataType::DataType(){
  m_intVal = 0;
  m_doubleVal = 0.0;
}

DataType::DataType(int intVal, double doubleVal){
  m_intVal = intVal;
  m_doubleVal = doubleVal;
}

//copy constructor
DataType::DataType(const DataType& srcData)
{
  m_intVal = srcData.m_intVal;
  m_doubleVal = srcData.m_doubleVal;
}

bool DataType::operator==(const DataType& rhs) const{
  return m_intVal==rhs.m_intVal && m_doubleVal==rhs.m_doubleVal;
}

DataType& DataType::operator=(const DataType& rhs){
  if (this != &rhs){
    m_intVal = rhs.m_intVal;
    m_doubleVal = rhs.m_doubleVal;
  }
  return *this;
}

//my own implementation
DataType& DataType::operator* (const int multiplier)
{
  std::cout << "Being called" << std::endl;
  m_intVal *= multiplier;
  m_doubleVal *= (double)multiplier;
  return *this;
}

int DataType::GetIntVal() const{
  return m_intVal;
}

void DataType::SetIntVal(int i){
  m_intVal = i;
}

double DataType::GetDoubleVal() const{
  return m_doubleVal;
}

void DataType::SetDoubleVal(double d){
  m_doubleVal = d;
}

std::ostream& operator<<(std::ostream& os, const DataType& dt){
  os << "{" << dt.m_intVal << "," << dt.m_doubleVal << "}";
  return os;
}

std::istream& operator>>(std::istream& is, DataType& dt){
  char in_buf[255];
  is >> in_buf;
  dt.m_doubleVal = atof(in_buf);
  dt.m_intVal = (int)dt.m_doubleVal;
  dt.m_doubleVal -= dt.m_intVal;
  return is;
}
