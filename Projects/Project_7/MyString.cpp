/*
  Sam Vernaza
  CS202
  Project_7
*/

#include "MyString.h"

//default constructor
MyString::MyString()
{
  m_buffer = NULL;
  buffer_allocate(0);
}

//parameterized constructor
MyString::MyString (const char * str)
{
  m_buffer = NULL;
  size_t len = strlen(str);
  buffer_allocate(len);
  std::strcpy (m_buffer, str);
}

/*
  copy constructor:
    Takes in an object and calls the buffer_allocate()
    Then the value in the srcStr buffer is copied to the
    newly allocated m_buffer to ensure a sucessful
    copy is completed
*/
MyString::MyString (const MyString& srcStr)
{
  buffer_allocate (srcStr.m_size);
  std::strcpy (m_buffer, srcStr.m_buffer);
}

/*
  ~MyString:
    Deallocates the memory created for a char *
*/
MyString::~MyString()
{
  delete [] m_buffer;
}

/*
  buffer_allocate:
    Takes a size passed in and initializes the m_buffer
    to be of length size. After the first value is set to NULL
    to ensure that a valid value exists to prevent memory leaks
*/
void MyString::buffer_allocate (size_t size)
{
  if(m_buffer != NULL)
    buffer_deallocate();
  m_size = size;
  m_buffer = new char [m_size + 1];
  m_buffer[0] = '\0';
}

/*
  buffer_deallocate:
    Deallocates the memory pointed to
    by the m_buffer member and updates
    the size to zero.
*/
void MyString::buffer_deallocate()
{
    if(m_buffer != NULL)
    {
      delete [] m_buffer;
      m_buffer = NULL;
      m_size = 0;
    }
    else
      return;
}

/*
  size:
    Returns the size of the buffer in bytes.
*/
size_t MyString::size () const
{
  return (sizeof(m_buffer));
}

/*
  length:
    returns the length of the buffer as a valid data semantic
*/
size_t MyString::length() const
{
  size_t len = std::strlen(m_buffer);
  return len;
}

/*
  c_str:
    Returns a c_string of the current object to the calling client.
    NULL terminated. This implementation will return m_buffer if it is
    a non-null result. Otherwise a zero allocated buffer is created and
    will be returned.
*/
const char* MyString::c_str() const
{
  if(m_buffer)
    return m_buffer;
  else
  {
    char * cstr = new char [1];
    cstr[0] = '\0';
    return cstr;
  }

}

/*
  operator==:
    Checks if the calling object represents the same string as another
    MyString object, and return true (or false) respectively.
*/
bool MyString::operator== (const MyString& srcStr) const
{
  return (std::strcmp(m_buffer, srcStr.m_buffer) == 0);
}

/*
  opertor=:
    assign a new value to the calling object's string data
    based on the data passed as a parameter.
    Reference is returned for cascading.
*/
MyString& MyString::operator= (const MyString& srcStr)
{
  //if this is the same object, just return it
  if(this == &srcStr)
    return *this;
  //if there is a value in the buffer, delete it
  buffer_deallocate();
  //initializing the contents of the srcStr
  buffer_allocate(srcStr.m_size);
  std::strcpy(m_buffer, srcStr.m_buffer);
  return *this;
}

/*
  operator+:
    concatenates C-string equivalent data of srcStr object
    and returns it by value, invoking the copy constructor.
*/
MyString MyString::operator+ (const MyString& srcStr) const
{
  //create temporary object
  MyString temp;
  //store the total size of all the buffer sizes
  temp.m_size = m_size + srcStr.m_size;
  //allocate memory to hold the total size of all elements
  temp.m_buffer = new char [temp.m_size + 1];
  //copy the calling objects data into the newly allocated temp
  std::strcpy(temp.m_buffer, m_buffer);
  //concatenate the srcStr to the newly allocated buffer
  std::strcat(temp.m_buffer, srcStr.m_buffer);
  //return the object created (invokes the copy constructor).
  return temp;
}

/*
  operator[]:
    by reference accessing of a specific character at index of size_t
    within the allocated m_buffer. This allows access to MyString data
    by reference, with read/write access.
*/
char& MyString::operator[] (size_t index)
{
  return m_buffer[index];
}

/*
  operator[]:
    by reference access of a specific character at index
    but with read-only priviliges.
*/
const char& MyString::operator[] (size_t index) const
{
  return m_buffer[index];
}

/*
  operator<<
    Friend operator that writes the values of the MyString object
    to the calling routine requesting.
*/
std::ostream& operator<<(std::ostream& os, const MyString& myStr)
{
  size_t i = 0;
  while(i < myStr.m_size)
  {
    os << myStr.m_buffer[i++];
  }
  os << std::endl << "Length: " << myStr.m_size;
  return os;
}
