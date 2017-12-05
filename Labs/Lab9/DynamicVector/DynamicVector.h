#ifndef DYNAMICVECTOR_H_
#define DYNAMICVECTOR_H_

#include <iostream>

class DynamicVector {
 public:
  DynamicVector(size_t size, int value=0);
  DynamicVector(const DynamicVector& other);
  ~DynamicVector();

  DynamicVector& operator=(const DynamicVector& rhs);
 
  const DynamicVector operator+(const DynamicVector& rhs) const;
  
  DynamicVector Expanded() const;
  
  friend std::ostream& operator<<(std::ostream& os, const DynamicVector& dv);
  
 private:
  size_t m_size;
  int *m_data;
};

#endif //DYNAMICVECTOR_H_
