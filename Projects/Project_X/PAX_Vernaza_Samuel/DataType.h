/*
  Sam Vernaza
  CS202
  Project_X
*/

#ifndef DATATYPE_H
#define DATATYPE_H

#include <iostream>

class DataType{

friend std::ostream& operator<<(std::ostream& os, const DataType& dataType);
friend std::istream& operator>>(std::istream& is, DataType& dataType);

  public:
    DataType();
    DataType(int intVal, double doubleVal);

    bool operator==(const DataType& other_dataType) const;
    DataType& operator= (const DataType& other_dataType);

    int GetIntVal() const;
    void SetIntVal(int i);
    double GetDoubleVal() const;
    void SetDoubleVal(double d);

  private:
    int m_intVal;
    double m_doubleVal;
};

#endif
