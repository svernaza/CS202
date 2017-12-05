class ComplexNumber()
{
  public:
    ComplexNumber();
    ComplexNumber(const ComplexNumber &srcComplexNum);

  private:
    int m_real;
    int m_imaginary;
    static int s_count;

};
