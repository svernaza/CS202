/*
  Samuel Vernaza
  CS202
  Project_10
*/

#ifndef ArrayStack_H_
#define ArrayStack_H_

#include "DataType.h"

using std::cout;
using std::endl;

const size_t MAX_STACKSIZE = 1000;

//forward declarations
template <class T>
class ArrayStack;

template <class T>
std::ostream& operator<<(std::ostream& os, const ArrayStack<T>& arrayStack);

//templated class
template <class T>
class ArrayStack{

  friend std::ostream& operator<<(std::ostream& os,			//(i)
					       const ArrayStack<T>& arrayStack)
  {
      arrayStack.serialize(os);
      return os;
  }

  public:
    ArrayStack();								    		//(1)
    ArrayStack(size_t count, const T& value);			//(2)
    ArrayStack(const ArrayStack<T>& other);				    	//(3)
    ~ArrayStack();							    			//(4)

    ArrayStack<T>& operator= (const ArrayStack<T>& rhs);			//(5)

    T& top();
    const T& top() const;

    void push(const T& value);
    void pop();

    size_t size() const;									//(13)
    bool empty() const;
    bool full() const;									//(14)
    void clear();
    void serialize(std::ostream& os) const;								//(15)

  private:
    T m_container[MAX_STACKSIZE];
    size_t m_top;
	};

#endif //ArrayStack_H_

//templated implementations
/*
  ArrayStack():
    Default constructor initializes values, but doesn't do anything with them
*/
template <class T>
ArrayStack<T>::ArrayStack()				    		//(1)
{
  m_top = 0;
}

/*
  Parameterized C-tor:
    Takes in a count and T value. Creates an array of size count and
    initializes every member of the DataType to value.
*/
template <class T>
ArrayStack<T>::ArrayStack(size_t count, const T& value)			//(2)
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
      m_container[i] = value;
      ++i;
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
template <class T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& other)				    	//(3)
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
template <class T>
ArrayStack<T>::~ArrayStack()							    			//(4)
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
template <class T>
ArrayStack<T>& ArrayStack<T>::operator= (const ArrayStack<T>& rhs)			//(5)
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
template <class T>
T& ArrayStack<T>::top()
{
  std::cout << "non-const top() called" << std::endl;
  return m_container[m_top-1];
}

/*
  top:
    returns a constant reference to the value in the top of the stack
*/
template <class T>
const T& ArrayStack<T>::top() const
{
  std::cout << "const-top() called" << std::endl;
  return m_container[m_top-1];
}

/*
  push:
    Inserts a value to the back of the stack if there is space.
*/
template <class T>
void ArrayStack<T>::push(const T& value)
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
template <class T>
void ArrayStack<T>::pop()
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
template <class T>
size_t ArrayStack<T>::size() const									//(13)
{
  return m_top;
}

/*
  empty():
    returns true if the ArrayStack is empty and false otherwise.
*/
template <class T>
bool ArrayStack<T>::empty() const										//(14)
{
  return m_top == 0;
}

/*
  full:
    Returns a boolean value indicating if the array is max capacity
*/
template <class T>
bool ArrayStack<T>::full() const
{
  return m_top == MAX_STACKSIZE;
}

/*
  clear():
    Clears the contents of an m_container by setting each cell of the array to '\0'.
*/
template <class T>
void ArrayStack<T>::clear()											//(15)
{
  if(empty())
    return;
  else
  {
    T dummy;
    while(m_top--)
      m_container[m_top] = dummy;
  }
}

/*
  serialize:
    Takes the ostream object passed to it and displays the contents of the
    m_container.
*/
template <class T>
void ArrayStack<T>::serialize(std::ostream& os) const
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
