/*
  Samuel Vernaza
  CS202
  Project_8
*/
#include "ArrayQueue.h"

using std::cout;
using std::endl;
/*
  operator<<:
    overloads the std::ostream insertion operator to output the contents
    of an array
*/
std::ostream& operator<<(std::ostream& os,			//(i)
               const ArrayQueue& ArrayQueue)
{
  ArrayQueue.serialize(os);
  return os;
}

/*
  ArrayQueue():
    Default constructor initializes values, but doesn't do anything with them
*/
ArrayQueue::ArrayQueue()				    		//(1)
{
  m_size = 0;
  m_front = m_back = -1;
}

/*
  Parameterized C-tor:
    Takes in a count and DataType value. Creates an array of size count and
    initializes every member of the DataType to value.
*/
ArrayQueue::ArrayQueue(size_t count, const DataType& value)			//(2)
{
  if (count <= 0 || count > ARRAY_MAX)
  {
    if(count > ARRAY_MAX)
      std::cout << "Value outside ARRAY_MAX" << std::endl;
    m_size = 0;
    m_front = m_back = -1;
  }
  else
  {
    size_t i = 0;
    m_size = count;
    m_front = i;
    while (i < m_size)
    {
      m_back = i;
      m_array[i++] = value;
    }
  }
}

/*
  Copy c-tor:
    Takes in a constant value of one array and allocates memory of the same
    size to this objects m_size member. Once the memory is allocated it copies
    all the values of the other array into this array.
    Didn't need to implement this, but chose to. System's copy constructor
    would have sufficed.

*/
ArrayQueue::ArrayQueue(const ArrayQueue& other)				    	//(3)
{
  if(other.m_size <= 0 || other.m_size > ARRAY_MAX)
  {
    if(other.m_size > ARRAY_MAX)
      std::cout << "Value outside ARRAY_MAX" << std::endl;
    m_size = 0;
    m_front = m_back = -1;
    return;
  }
  else
  {
    m_size = other.m_size;
    m_front = other.m_front;
    m_back = other.m_back;

    size_t i = m_front;
    while(i < m_size)
    {
      m_array[i] = other.m_array[i];
      ++i;
    }
  }
}

/*
  destructor:
    destructor doesn't need to be implemented. System can handle static memory
    removal, but I chose to anyway.
*/
ArrayQueue::~ArrayQueue()							    			//(4)
{
  cout << "-------------------------------------------" << endl;
  cout << endl << "ArrayQueue D-tor Called!" << endl;
  clear();
}

/*
  operator =:
    Assigns the contents of the rhs to the contents of the left hand side.
    First will check if the object on the left is the same as the right and if
    so will return the current object's list value. If not the current array
    list is deallocated and then reassigned values
*/
ArrayQueue& ArrayQueue::operator= (const ArrayQueue& rhs)			//(5)
{
  if(this != &rhs)
  {
    clear();
    m_size = rhs.m_size;
    m_front = rhs.m_front;
    m_back = rhs.m_back;
    size_t i = m_front;
    while (i < m_size)
    {
        m_array[i] = rhs.m_array[i];
        ++i;
    }
  }
  return *this;
}

/*
  front:
    returns the front value of the queue.
*/
DataType& ArrayQueue::front()
{
  std::cout << "non-const front() called" << std::endl;
  return m_array[m_front];
  //this is an implementation that I was going to implement, but changed my mind
/*
  try {
    return m_array[m_front];
  }
  catch (...)
  {
    if(m_front == -1)
      throw Exception("Array Queue Empty");
  }
*/
}

/*
  front:
    returns a constant reference to the value in the front of the queue
*/
const DataType& ArrayQueue::front() const
{
  std::cout << "const-front() called" << std::endl;
  return m_array[m_front];
  //this is an implementation that I was going to implement, but changed my mind
  /*try {
    return m_array[m_front];
  }
  catch (...)
  {
    if(m_front == -1)
      throw Exception("Array Queue Empty");
  }
  */
}

/*
  back:
    returns the rear value of the queue;
*/
DataType& ArrayQueue::back()
{
  std::cout << "non-const back() called" << std::endl;
  return m_array[m_back];
  //this is an implementation that I was going to implement, but changed my mind
  /*
    try {
      return m_array[m_back];
    }
    catch (...)
    {
      if(m_back == -1)
        throw Exception("Array Queue Empty");
    }
  */
}

/*
  back:
    returns a constant reference to the rear value of the queue
*/
const DataType& ArrayQueue::back() const
{
  std::cout << "const-back() called" << std::endl;
  return m_array[m_back];
  //this is an implementation that I was going to implement, but changed my mind
/*
  try {
    return m_array[m_back];
  }
  catch (...)
  {
    if(m_back == -1)
      throw Exception("Array Queue Empty");
  }
*/
}

/*
  push:
    Inserts a value to the back of the queue if there is space.
*/
void ArrayQueue::push(const DataType& value)
{
  if(full())
  {
    std::cout << "The list is full, can't add!" << std::endl;
    return;
  }
  else if(empty())
  {
    m_back = m_front = 0;
    m_size = 1;
  }
  else
  {
    //++m_back;
    m_back = (m_back+1) % ARRAY_MAX;
    ++m_size;
  }
  m_array[m_back] = value;
}

/*
  pop:
    Removes an element from a particular index if it exists.
*/
void ArrayQueue::pop()
{
  if(empty())
    return;
  else if(m_back == m_front)
  {
    m_size = 0;
    m_front = m_back = -1;
  }
  else
  {
    cout << "----------" << endl;
    std::cout << m_array[m_front] << " is being removed" << endl;
    //++m_front;
    m_front=(m_front+1)% ARRAY_MAX;
    --m_size;
  }
}
/*
  size():
    returns the size of the array
*/
size_t ArrayQueue::size() const									//(13)
{
  return m_size;
}

/*
  empty():
    returns true if the ArrayQueue is empty and false otherwise.
*/
bool ArrayQueue::empty() const										//(14)
{
  return (m_front == -1 && m_back == -1);
}

/*
  full:
    Returns a boolean value indicating if the array is max capacity
*/
bool ArrayQueue::full() const
{
  return (m_size == ARRAY_MAX);
}

/*
  clear():
    Clears the contents of an m_array by setting each cell of the array to '\0'.
*/
void ArrayQueue::clear()											//(15)
{
  if(empty())
    return;
  else
  {
    DataType dummy;
    //may seg fault, might need to do m_size-1
    while(m_size--)
      m_array[m_size] = dummy;
  }
}

/*
  serialize:
    Takes the ostream object passed to it and displays the contents of the
    m_array.
*/
void ArrayQueue::serialize(std::ostream& os) const
{
  if(m_size > 0)
  {
    os << endl;
    size_t i = m_front;
    while (i <= m_back)
    {
      os << m_array[i] << endl;
      ++i;
    }
  }
  else
    std::cout << "Array Empty!" << std::endl;
}
