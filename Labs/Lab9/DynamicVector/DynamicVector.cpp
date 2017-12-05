#include <iostream>

#include "DynamicVector.h"

DynamicVector::DynamicVector(size_t size, int value) :
  m_size( size )
{
  if (m_size){  //allocate only when it makes sense
    m_data = new(std::nothrow) int [m_size];
    if (m_data){
      for (size_t i=0; i<m_size; ++i){
        m_data[i] = value;
      }
    }
    else{
      std::cerr << "DynamicVector: Allocation failed!" << std::endl;
      m_size = 0;
    }
  }
  else{
    m_data = NULL;
  }
}

DynamicVector::DynamicVector(const DynamicVector& other) :
  m_size( other.m_size )
{
  if (m_size){  //allocate only when it makes sense
    m_data = new(std::nothrow) int [m_size];
    if (m_data){
      for (size_t i=0; i<m_size; ++i){
	m_data[i] = other.m_data[i];
      }
    }
    else{
      std::cerr << "DynamicVector: Allocation failed!" << std::endl;
      m_size = 0;
    }
  }
  else{
    m_data = NULL;
  }
}

DynamicVector::~DynamicVector()
{
  delete [] m_data;
}

DynamicVector& DynamicVector::operator=(const DynamicVector& rhs)
{
  if (this != &rhs){
    if (m_size != rhs.m_size){  //allocate only when it makes sense
      delete [] m_data;  //deallocate first
      if (rhs.m_size){  //allocate only when it makes sense
        m_size = rhs.m_size;
	m_data = new(std::nothrow) int [m_size];
	if (!m_data){  //row allocation failed, cleanup everything (could retry too)
          std::cerr << "DynamicVector: Allocation failed!" << std::endl;
	  m_size = 0;
        }
      }
      else{
	m_size = 0;
  	m_data = NULL;
      }
    }
    if (m_data){  //reaching this far with a non-NULL pointer means allocation succeeded, or previously allocated data is maintained and will be overwritten
      for (size_t i=0; i<m_size; ++i){
	m_data[i] = rhs.m_data[i];
      }
    }
  }
  return *this;
}

const DynamicVector DynamicVector::operator+(const DynamicVector& rhs) const{
  if (m_size && m_size==rhs.m_size ){  //have to have same non-zero size
    DynamicVector this_cpy = *this;  //create a different temporary local object, allocation handled by ctor
    for (size_t i=0; i<m_size; ++i){
      this_cpy.m_data[i] += rhs.m_data[i];
    }
    return this_cpy;
  }
  else{
    return DynamicVector(0);  // 0-rows 0-cols marked object (invalid state)
  }
}

DynamicVector DynamicVector::Expanded() const{
  if (m_size){
    DynamicVector expanded( 2 * m_size - 1);  //create a different temporary local object, allocation handled by ctor
    for (size_t i=0; i<m_size; ++i){
      expanded.m_data[2*i] = m_data[i]; //fill alternating positions from start to end
    }
    for (size_t i=1; i<expanded.m_size-1; i+=2){
      expanded.m_data[i] = (expanded.m_data[i-1]+expanded.m_data[i+1])/2; //interpolate intermediate positions
    }
    return expanded;
  }
  else{
    return DynamicVector(0);  // 0-rows 0-cols marked object (invalid state)
  }
}

std::ostream& operator<<(std::ostream& os, const DynamicVector& dv){
  os << "[";
  for (size_t i=0; i<dv.m_size; ++i){
    os << " " << dv.m_data[i];
  }
  os << " ]";
  return os;
}
