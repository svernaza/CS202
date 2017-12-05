#ifndef COMPLEX_NUMBER_H_
#define COMPLEX_NUMBER_H_

#include <iostream>

class ComplexNumber{
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn);

  public:
    ComplexNumber();
    ComplexNumber(int real, int imaginary);
    ComplexNumber(const ComplexNumber& other);

    ~ComplexNumber();

    ComplexNumber& operator=(const ComplexNumber& rhs);
    const ComplexNumber operator+(const ComplexNumber& rhs);

    static int GetCount();
    
  private:
    int m_real;
    int m_imaginary;

    static int s_count;
};

#endif //COMPLEX_NUMBER_H_
