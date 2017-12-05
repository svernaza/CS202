
#include "ComplexNumber.h"

int ComplexNumber::s_count = 0;

int ComplexNumber::GetCount(){
  return s_count;
}

ComplexNumber::ComplexNumber()
{
  ++s_count;
}

ComplexNumber::ComplexNumber(int real, int imaginary) :
  m_real(real) , 
  m_imaginary(imaginary)
{
  ++s_count;
}

ComplexNumber::ComplexNumber(const ComplexNumber& other) :
  m_real(other.m_real) , 
  m_imaginary(other.m_imaginary)
{
  ++s_count;
}

ComplexNumber::~ComplexNumber()
{
  --s_count;
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& rhs){
  if (this != &rhs){
    m_real = rhs.m_real;
    m_imaginary = rhs.m_imaginary;
  }
  return *this;
}

const ComplexNumber ComplexNumber::operator+(const ComplexNumber& rhs){
  return ComplexNumber(m_real + rhs.m_real , m_imaginary + rhs.m_imaginary);
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn){
  os << cn.m_real << " + i" << cn.m_imaginary;
  return os;
}
    
