/*
  Sam Vernaza
  CS202
  Project_X
*/
#include "SmartPtr.h"

using std::cout;
using std::endl;

/*
  Default-ctor:
    Dynamically allocates a new DataType object and keeps track of address
    via the m_ptr. Dynamically allocates a new size_t variable sets the value
    it points to to 1.
*/
//confirmed, looks good
SmartPtr::SmartPtr( )
{
  m_ptr = new DataType; //(a)
  m_refcount = new size_t (1);
  cout << "SmartPtr Dflt-ctor allocation, RefCount =" << *m_refcount << endl;
}

/*
  Parameterized-ctor:
    Passed a pointer to DataType as a parameter. The constructor takes in
    previously allocated memory, and wraps itself around the raw pointer.
    No memory allocation occurs, m_ptr is referencing data directly.
    A new size_t variable will be allocated and m_refcount will keep track of
    this new memory. Depending on data pointer is NULL, the value pointed-to by
    m_refcount will set 0 or 1 to dnote that the SmartPtr object does not
    correspond to valid memory, or that there is exists on SmartPtr object
    that points to the Dynamic Memory behind m_ptr. Typical output is displayed
    to demonstrate a successful construction has occured.
*/

//confirmed
SmartPtr::SmartPtr( DataType * data )
{
  m_ptr = data; //assignment (a)
  m_refcount = new size_t; //(b)
  if(m_ptr)
  {
    *m_refcount = 1;
  }
  else
  {
    *m_refcount = 0;
    cout << "NULL pointer was passed, no data was allocated..." << endl;
  }
  //(c)
  cout << "SmartPtr Prmtrz-ctor from data pointer, RefCount =" << *m_refcount;
  cout << endl;
}

/*
  Copy-ctor:
    Takes another SmartPtr object as reference. Since this constructor has access
    to preallocated memory there isn't a dynamic memory allocation. All necessary
    data value are given from the other object passed in. No dynamic memory
    allocation occurs for m_ptr. m_ptr is assigned the value of other.m_ptr.
    m_refcount is assigned value based on the pointed-to value of the other
    object. If m_ptr is NULL, then 0 will exist for the preassigned value of
    m_refcount. If there is a valid member pointer in m_ptr, then m_refcount is
    incremented to show that two pointers refernce the same memory. Standard
    output is printed.
*/
//confirmed
SmartPtr::SmartPtr( const SmartPtr& other ) //access to preallocated other.m_ptr && other.m_refcount
{
  if(other.m_ptr)
  {
    m_ptr = other.m_ptr; //(a) //keep track of data directly
    m_refcount = other.m_refcount;
    ++(*m_refcount);
  }
  else //other.m_ptr == NULL
  {
    cout << "Object with NULL pointer data was passed, refcount not incremented..." << endl;
    m_refcount = new size_t (0);
  }
  cout << "SmartPtr Copy-ctor, RefCount =" << *m_refcount << endl; //(c)
}

/*
  destructor:
      Decrement value pointed-to by m_refcount to denote that one less SmartPtr
      m_refcount is pointing to the constructed object. The destructor will
      confirm that there aren't any more pointers referencing the pointed to
      object before deallocating memory. In order to do this the program will
      ensure that m_refcount has a value of zero prior to deallocation. Or
      it will continue to decrement the value poined to by m_refcount;
*/

//may segfault?
SmartPtr::~SmartPtr( )
{
  if(*m_refcount > 0)
    --(*m_refcount);
  //if the object is the last one, deallocation will happen
  else
  {
      cout << "SmartPtr D-tor, RefCount =" << *m_refcount << endl; //(d)
      delete m_refcount; //(c)
      delete m_ptr; //(c)
  }
}

//overloaded Assignment operator
/*
  operator=:
    Perform assignment from a SmartPtr object. Releases its own Dynamic memory
    by decrementing the m_refcount to symbolize that one less pointer exists.
    Once cleared, reference the same values as the other SmartPtr objects.
    m_ptr and m_refcount will be repointed to this new object by invoking the
    copy constructor.
*/
//cause of segfault?
SmartPtr& SmartPtr::operator=( const SmartPtr& rhs )
{
  if(this == &rhs)
    return *this;

  //if (this != &rhs)
  //{
  if(*m_refcount > 0)
    --(*m_refcount); //(a)
    //if the object is the last one, deallocation will happen
  else if(*m_refcount == 0)
    {
      cout << "SmartPtr Assignment Operator - Pre-releasing Memory , RefCount:";
      cout << *m_refcount << endl;
      delete m_refcount;
      delete m_ptr;
    }

    //return &SmartPtr (rhs);
    //SmartPtr * test_ptr = SmartPtr(rhs);
    //return test_ptr;
    //need to change this function to call the copy constructor
    if(!rhs.m_ptr)
    {
      cout << "Object with NULL pointer data was passed, refcount not incremented..." << endl;
      //m_ptr = NULL;
      m_refcount = new size_t (0);
    }
    else
    {
      cout << "Edit me 2" << endl;
      //m_ptr = NULL;
      m_ptr = rhs.m_ptr;
      m_refcount = rhs.m_refcount;
      ++(*m_refcount);
    }
    cout << "SmartPtr Assignment, RefCount=" << *m_refcount << endl;
  //}
  return *this;
}

//Overloaded dereference operator
/*
  operator*:
    Dereferences the Dynamic Memory Object that is encapsulated within the
    SmartPtr:
    When there exists a raw pointer, dereferencing returns a reference to
    the underlying object:

*/
DataType& SmartPtr::operator*( )
{
  return *m_ptr;
}

//overladed indirect member access operator
DataType* SmartPtr::operator->( )
{
  return m_ptr;
}
