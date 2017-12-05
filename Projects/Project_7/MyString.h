/*
  Samuel Vernaza
  CS202
  Project_7
*/

#ifndef MYSTRING_H_
#define MYSTRING_H_

#include <iostream>
#include <cstring>

const int MAX_BUF = 255;

class MyString{

  public:
    MyString();
    MyString(const char* srcStr);
    MyString(const MyString& srcStr);
    ~MyString();

    size_t size() const;
    size_t length() const;
    const char* c_str() const;

    bool operator== (const MyString& srcStr) const;
    MyString& operator= (const MyString& srcStr);
    MyString operator+ (const MyString& srcStr) const;
    char& operator[] (size_t index);
    const char& operator[] (size_t index) const;

friend std::ostream& operator<<(std::ostream& os, const MyString& myStr);

  private:
    void buffer_deallocate();
    void buffer_allocate(size_t size);

    char * m_buffer;
    size_t m_size;
};

#endif //MYSTRING_H_
