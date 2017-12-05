/*
  Samuel Vernaza
  CS202
  Project_8
*/
#include "ArrayList.h"

const size_t MAX = 50;

using std::cout;
using std::endl;
/* Your implementation here */

/*
  operator<<:
    overloads the std::ostream insertion operator to output the contents
    of an array
*/
std::ostream& operator<<(std::ostream& os,			//(i)
               const ArrayList& arrayList)
{
  os << endl;
  size_t count = arrayList.m_size;
  size_t i = 0;
  while(count--)
  {
    os << arrayList.m_array[i++] << endl;
  }
  return os;
}

/*
  ArrayList():
    Default constructor initializes values, but doesn't do anything with them
*/
ArrayList::ArrayList(): m_maxsize(MAX)				    		//(1)
{
  m_size = 0;
  m_array = NULL;
}

/*
  Parameterized C-tor:
    Takes in a count and DataType value. Creates an array of size count and
    initializes every member of the DataType to value.
*/
ArrayList::ArrayList(size_t count, const DataType& value)			//(2)
{
  m_maxsize = MAX;
  if(count > m_maxsize)
  {
    cout << "Value greater than max, nothing set!" << endl;
    m_array = NULL;
  }
  else if (m_maxsize == 0)
  {
    m_size = 0;
    m_array = NULL;
  }
  else
    m_size = count;

  m_array = new DataType[m_size];

  size_t i = 0;
  while(i < m_size)
    m_array[i++] = value;
}

/*
  Copy c-tor:
    Takes in a constant value of one array and allocates memory of the same
    size to this objects m_size member. Once the memory is allocated it copies
    all the values of the other array into this array.

    THIS CONSTRUCTOR IS SPECIAL IN THAT IT MAKES THE VALUES LARGER AT EACH index
    I THOUGHT IT WOULD MAKE IT EASIER TO READ AND JUST DECIDED TO IMPLEMENT IT
*/
ArrayList::ArrayList(const ArrayList& other)				    	//(3)
{
  int check = ((int)other.m_size);
  if(check < 0)
  {
    m_size = 0;
    m_array = NULL;
    return;
  }
  m_size = other.m_size;
  m_maxsize = other.m_maxsize;
  m_array = new DataType[m_size];

  size_t i = 0;
  while(i < m_size)
  {
    //just changing up the values of the data type at this index to make it
    //more intersting, and to make it easier to read and see different values
    m_array[i] = (other.m_array[i] * i);
    ++i;
  }
}

/*
  destructor:
    deallocates the memory of an ArrayList object. No independent deallocation
    is required for each element since we are working with the int and double
    values stored within the index and can just let them rest as garbage.
*/
ArrayList::~ArrayList()							    			//(4)
{
  cout << "-------------------------------------------" << endl;
  cout << endl << "ArrayList D-tor Called!" << endl;
  clear();
}

/*
  operator =:
    Assigns the contents of the rhs to the contents of the left hand side.
    First will check if the object on the left is the same as the right and if
    so will return the current object's list value. If not the current array
    list is deallocated and then reassigned values
*/
ArrayList& ArrayList::operator= (const ArrayList& rhs)			//(5)
{
  if(this != &rhs)
  {
    clear();
    m_maxsize = rhs.m_maxsize;
    m_array = new DataType[m_size];
    int count = (int)rhs.m_size;
    size_t i = 0;
    while (count--)
    {
        m_array[i] = rhs.m_array[i];
        ++i;
    }
  }
  return *this;
}

/*
  First:
    Returns the first occurence of a value in the array
*/
DataType* ArrayList::First()						     		//(6)
{
  size_t i = 0;
  while(i < m_size)
  {
    if(!empty())
      return &m_array[i];
    ++i;
  }
    return NULL;
}

/*
  Last:
    Starting at the last index of the list continue decrementing until
    the first value of the array is encounterd. Return this value.
*/
DataType* ArrayList::Last()						                //(7)
{
  int count = (int)m_size;
  while(count-- > 0)
  {
    if(!empty())
      return &m_array[count];
  }
  return NULL;
}

/*
  Find:
    Takes in a target DataType target value for comparison of values within the
    current array object. The value is compared through each element of the List
    while we traverse through the array. If a match is found and it's not the
    first value, then the value of previous is set to the previous array index
    and the value of the matched data is returned to the calling routine that
    invoked it. This doesn't invoke the start functionality.
*/
DataType* ArrayList::Find(const DataType & target,				    //(8)
               DataType * & previous,
               const DataType * start)
{
  size_t i = 0;
  while(i < m_size)
  {
    if(m_array[i] == target)
    {
      if(i > 0)
        previous = &m_array[i-1];
      else
        previous = NULL;
      return &m_array[i];
    }
    ++i;
  }
  return NULL;
}

/*
DataType* InsertAfter(const DataType& target,     		//(9)
                      const DataType& value)
{

}
*/

DataType* ArrayList::InsertBefore(const DataType& target,  		//(10)
                       const DataType& value)
{
    //increment the size, if the size is larger than m_maxsize, resize array.
  int i = 0;
  while(i < m_size)
  {
    if(m_array[i] == target)
    {
      ++m_size;
      if(m_array[i] == First())
      {
        
      }
    }
  }
    ++m_size;
    if(m_size > m_maxsize)
      resize(m_size);
    //if the first position found is the target
    //shift everything right and assign index 0 to the value
    if(found == First())
    {
        cout << "First" << endl;
        int i = (int)size() - 2;
        while(i > 0)
        {
          m_array[i + 1] = m_array[i];
          --i;
        }
        m_array[i] = value;
    }
    /*
    else if(found == Last())
    {

      m_array[size() - 2] = m_array[size()-1];
      m_array[size() - 3] = m_array[size()-2];
    }
    */
    return m_array;
  }
  else
    return NULL;
}

/*
DataType* Erase(const DataType& target);		 		//(11)
*/

/*
  operator[]:
    returns the value of the DataType array at the current position
*/
DataType& ArrayList::operator[] (size_t position)					//(12)
{
  return m_array[position];
}


/*
  empty():
    returns true if the arrayList is empty and false otherwise.
*/
bool ArrayList::empty() const										//(14)
{
  if(!this->m_array)
    return true;
  return false;
}

/*
  size():
    returns the size of the array
*/
size_t ArrayList::size() const									//(13)
{
  return m_size;
}

/*
  clear():
    Clears the contents of an m_array member by deleting it. Then sets the
    m_array to NULL.
*/
void ArrayList::clear()											//(15)
{
  delete [] m_array;
  m_array = NULL;
}

void ArrayList::resize(size_t count)		               			//(16)
{
  m_maxsize = count;
  DataType * temp = m_array;
  m_array = NULL;
  m_array = new DataType[count];
  size_t i = 0;
  while(i < count)
  {
    m_array[i] = temp[i];
    ++i;
  }
  DataType def(0, 0.0);
  m_array[i] = def;
}


/* Working implementation of the right shift
if(m_maxsize-m_size)
{
  int i = (int)size() - 2;
  while(i > 0)
  {
    m_array[i + 1] = m_array[i];
    --i;
  }
  m_array[i] = value;
}
*/
