ComplexNumber::ComplexNumber()
{
  static int s_count = 0;
}

ComplexNumber::ComplexNumber(const ComplexNumber &srcComplexNum)
{
  m_real = srcComplexNum.m_real;
  m_imaginary = srcComplexNum.m_imaginary;
  s_count = srcComplexNum.s_count;
}
void ComplexNumber::ComplexNumber operator= 
