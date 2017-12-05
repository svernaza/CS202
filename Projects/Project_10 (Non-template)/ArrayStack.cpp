/*
  Samuel Vernaza
  CS202
  Project_8
*/
#include "ArrayStack.h"

using std::cout;
using std::endl;
/*
  operator<<:
    overloads the std::ostream insertion operator to output the contents
    of an array
*/
std::ostream& operator<<(std::ostream& os,			//(i)
               const ArrayStack& arrayStack)
{
  arrayStack.serialize(os);
  return os;
}

/*
  ArrayStack():
    Default constructor initializes values, but doesn't do anything with them
*/
ArrayStack::ArrayStack()				    		//(1)
{
  m_top = 0;
}

/*
  Parameterized C-tor:
    Takes in a count and DataType value. Creates an array of size count and
    initializes every member of the DataType to value.
*/
ArrayStack::ArrayStack(size_t count, const DataType& value)			//(2)
{
  if (count <= 0 || count > MAX_STACKSIZE)
  {
    if(count > MAX_STACKSIZE)
      std::cout << "Value outside MAX_STACKSIZE" << std::endl;
    m_top = 0;
  }
  else
  {
    m_top = count;
    size_t i = 0;
    while (i < m_top)
    {
      std::cout << "Count" << i << std::endl;
      m_container[i] = value;
      ++i;
      std::cout<< "Pass" << std::endl;

    }
  }
}

/*
  Copy c-tor:
    Takes in a constant value of one array and allocates memory of the same
    size to this objects m_top member. Once the memory is allocated it copies
    all the values of the other array into this array.
    Didn't need to implement this, but chose to. System's copy constructor
    would have sufficed.

*/
ArrayStack::ArrayStack(const ArrayStack& other)				    	//(3)
{
  if(other.m_top <= 0 || other.m_top > MAX_STACKSIZE)
  {
    if(other.m_top > MAX_STACKSIZE)
      std::cout << "Value outside MAX_STACKSIZE" << std::endl;
    m_top = 0;
    return;
  }
  else
  {
    m_top = other.m_top;

    size_t i = 0;
    while(i < m_top)
    {
      m_container[i] = other.m_container[i];
      ++i;
    }
  }
}

/*
  destructor:
    destructor doesn't need to be implemented. System can handle static memory
    removal, but I chose to anyway.
*/
ArrayStack::~ArrayStack()							    			//(4)
{
  cout << "-------------------------------------------" << endl;
  cout << endl << "ArrayStack D-tor Called!" << endl;
  clear();
}

/*
  operator =:
    Assigns the contents of the rhs to the contents of the left hand side.
    First will check if the object on the left is the same as the right and if
    so will return the current object's list value. If not the current array
    list is deallocated and then reassigned values
*/
ArrayStack& ArrayStack::operator= (const ArrayStack& rhs)			//(5)
{
  if(this != &rhs)
  {
    clear();
    m_top = rhs.m_top;
    size_t i = 0;
    while (i < m_top)
    {
        m_container[i] = rhs.m_container[i];
        ++i;
    }
  }
  return *this;
}

/*
  front:
    returns the front value of the stack.
*/
DataType& ArrayStack::top()
{
  std::cout << "non-const top() called" << std::endl;
  return m_container[m_top-1];
}

/*
  top:
    returns a constant reference to the value in the top of the stack
*/
const DataType& ArrayStack::top() const
{
  std::cout << "const-top() called" << std::endl;
  return m_container[m_top-1];
}

/*
  push:
    Inserts a value to the back of the stack if there is space.
*/
void ArrayStack::push(const DataType& value)
{
  if(full())
  {
    std::cout << "The list is full, can't add!" << std::endl;
    return;
  }
  m_container[m_top++] = value;
}

/*
  pop:
    Removes an element from a particular index if it exists.
*/
void ArrayStack::pop()
{
  if(empty())
    return;
  else
    --m_top;
}
/*
  size():
    returns the size of the array
*/
size_t ArrayStack::size() const									//(13)
{
  return m_top;
}

/*
  empty():
    returns true if the ArrayStack is empty and false otherwise.
*/
bool ArrayStack::empty() const										//(14)
{
  return m_top == 0;
}

/*
  full:
    Returns a boolean value indicating if the array is max capacity
*/
bool ArrayStack::full() const
{
  return m_top == MAX_STACKSIZE;
}

/*
  clear():
    Clears the contents of an m_container by setting each cell of the array to '\0'.
*/
void ArrayStack::clear()											//(15)
{
  if(empty())
    return;
  else
  {
    DataType dummy;
    while(m_top--)
      m_container[m_top] = dummy;
  }
}

/*
  serialize:
    Takes the ostream object passed to it and displays the contents of the
    m_container.
*/
void ArrayStack::serialize(std::ostream& os) const
{
  if(m_top > 0)
  {
    os << endl;
    size_t i = 0;
    while (i < m_top)
    {
      os << m_container[i] << endl;
      ++i;
    }
  }
  else
    std::cout << "Array Stack Empty!" << std::endl;
}
