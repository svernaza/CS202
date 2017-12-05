/*
  Samuel Vernaza
  Project 9
  CS202
*/
#include <iostream>
#include "NodeQueue.h"

/*
  operator<<:
    Outputs the entire contents of a list as per the requirements of the
    std::ostream object that invokes it.
*/
std::ostream& operator<<(std::ostream& os, const NodeQueue& srcQueue)
{
    srcQueue.serialize(os);
    return os;
}

/*
  Default constructor:
    Invokes a new Node object (via the default constructor of the Node Class).
    This node's next pointer is initialized to NULL by the constructor
*/
NodeQueue::NodeQueue()							    		//(1)
{
  m_front = NULL;
  m_back = m_front;
}

/*
  Parameterized constructor:
    Invokes a list of new nodes that are of size Count and initializes
    each m_data member to be the value passed into the constructor.
*/
NodeQueue::NodeQueue(size_t count, const DataType& value)
{
  if(count <= 0)
  {
    m_front = m_back = NULL;
    std::cout << "Zero or less count detected, value not assigned" << std::endl;
  }
  else
  {
    m_front = new Node(value);
    Node * current = m_front;
    int i = 0;
    while (--count > 0)
    {
      //invokes Parameterized constructor to have a m_data value of value.
      //believe it should automatically handle the assignment.
      current->m_next = new Node(value);
      current = current->m_next;
      m_back = current;
      ++i;
    }
    //deallocate current
    current = NULL;
    delete current;
  }
}

/*
  Copy constructor:
    Takes a pointer to the first node of a list and then copies each value
    into its own LL.
*/
NodeQueue::NodeQueue(const NodeQueue& other)					//(3)
{
/*
  increased performance assignment, considers three cases of assignment
  no list, one item, more than one item.
*/
  if(!other.m_front)
  {
    m_front = m_back = NULL;
  }
  else if(!other.m_front->m_next)
  {
    m_front = new Node(other.m_front->m_data);
    m_back = m_front;
  }
  else
  {
    Node * otherCurr = other.m_front;
    m_front = new Node (otherCurr->m_data);
    Node * current = m_front;
    otherCurr = otherCurr->m_next;

    while (otherCurr)
    {
      current->m_next = new Node(otherCurr->m_data);
      current = current->m_next;
      m_back = current;
      otherCurr = otherCurr->m_next;
    }
    current = NULL;
    otherCurr = NULL;
    delete current;
    delete otherCurr;
  }
}

/*
  ~NodeQueue:
    Destructor will delete an entire list if it exists. Otherwise a message is
    recorded
*/
NodeQueue::~NodeQueue()							   			//(4)
{
  std::cout << std::endl << "------------------------------------" << std::endl;
  std::cout << std::endl << "NodeQueue D-tor called!" << std::endl;
  size_t count = 0;
  //convert into a LLL, then delete it
  if(m_front)
  {
    m_back = NULL;
    Node * del = m_front;
    while(m_front)
    {
      m_front = m_front->m_next;
      del->m_next = NULL;
      delete del;
      del = m_front;
      ++count;
    }
    del = NULL;
    delete del;
  }
    //safety precaution
    std::cout << "Total Number of nodes deleted " << count << std::endl;
    m_front = NULL;
    delete m_front;

}

/*
  operator=
    Checks if the same assignment is happenning. If not, then the assignment
    takes place and copies over the entire list to another after it first
    removes any list that already existed. m_front is then assigned the value of
    rhs.
*/
NodeQueue& NodeQueue::operator= (const NodeQueue& rhs)			//(5)
{
  if(this == &rhs)
    return *this;
//delete any list that current exists
    if(m_front)
    {
      m_back = NULL;
      Node * del = m_front;
      while(m_front)
      {
        m_front = m_front->m_next;
        del->m_next = NULL;
        delete del;
        del = m_front;
      }
      del = NULL;
      delete del;
    }

  if(!rhs.m_front)
  {
    m_front = m_back = NULL;
    return *this;
  }
  else if(!rhs.m_front->m_next)
  {
    m_front = new Node(rhs.m_front->m_data);
    m_back = m_front;
    return *this;
  }
  else
  {
    Node * otherCurr = rhs.m_front;
    m_front = new Node (otherCurr->m_data);
    Node * current = m_front;

    otherCurr = otherCurr->m_next;
    while (otherCurr)
    {
      current->m_next = new Node(otherCurr->m_data);
      current = current->m_next;
      m_back = current;
      otherCurr = otherCurr->m_next;
    }
    current = NULL;
    otherCurr = NULL;
    delete current;
    delete otherCurr;
    return *this;
  }
}

/*
  front():
    Returns a reference to the front element of the queue.
*/

DataType& NodeQueue::front()
{
  std::cout << "Non-const front() method called" << std::endl;
  return m_front->m_data;
}

/*
  front():
    returns a constant reference to the front of the list.
*/
const DataType& NodeQueue::front() const
{
  std::cout << "Const front() method called" << std::endl;
  return m_front->m_data;
}

/*
  back():
    returns a reference to the data type found at the last node of the List
*/
DataType& NodeQueue::back()
{
  std::cout << "Non-const back() method called" << std::endl;
  return m_back->m_data;
}

/*
  back():
    returns a constant reference to the back of the list and ensures
    no altercations will take place to the data.
*/
const DataType& NodeQueue::back() const
{
  std::cout << "Const back() method being called" << std::endl;
  return m_back->m_data;
}

/*
  push():
    Takes a const DataType as an argument. Passes this value to the function
    and a new node is created, pushed onto the current list and assigned.
*/
void NodeQueue::push(const DataType& value)
{
  if(!m_front)
  {
    m_front = new Node(value);
    m_back = m_front;
  }
  else
  {
    Node * temp = new Node(value);
    m_back->m_next = temp;
    m_back = temp;
    temp = NULL;
  }
}

/*
  pop():
    Remove the first node in the list from the current list. Three conditions
    There isn't a list, it's returned. There's one item in the list,
    set back to NULL and delete front; set front to NULL. Finally, delete
    the front and then set it to NULL.
*/
void NodeQueue::pop()
{
  if(!m_front)
    return;
  else if(!m_front->m_next)
  {
    m_back = NULL;
    delete m_front;
    m_front = NULL;
  }
  else
  {
    Node * temp = m_front;
    m_front = m_front->m_next;
    delete temp;
    temp = NULL;
  }
}

/*
  size():
    Returns the size of the current list object.
*/
size_t NodeQueue::size() const               //(13)
{
  size_t count = 0;
  if(m_front)
  {
    Node * current = m_front;
    while(current)
    {
      ++count;
      current = current->m_next;
    }
    current = NULL;
    delete current;
  }
  return count;
}

/*
  empty():
    Returns a boolean value flagging if the list is empty. True for empty list.
    False otherwise.
*/
bool NodeQueue::empty() const									//(14)
{
  if(!m_front)
    return true;
  return false;
}

/*
  full():
    will always return false because there aren't any size limitations set on
    the Node based queue.
*/
bool NodeQueue::full() const
{
  std::cout << "NO size limitations set" << std::endl;
  return false;
}

/*
  Clear():
    Clears the contents of a list and leaves it empty.
*/
void NodeQueue::clear()										//(15)
{
  if(m_front)
  {
    Node * del = m_front;
    while(m_front)
    {
      m_front = m_front->m_next;
      del->m_next = NULL;
      delete del;
      del = m_front;
    }
    del = NULL;
    delete del;
  }
}

/*
  serialize:
    Displays the contents of the Node based List using the ostream variable
    passed in.
*/
void NodeQueue::serialize(std::ostream& os) const
{
  using std::endl;

  if(!m_front)
  {
    os << "No list to display" << endl;
  }
  else
  {
    Node * current = m_front;
    //display first node on a new line
    os << endl;

    size_t i = 1;
    while(current)
    {
      os << "Value of Node " << i << ": " << current->GetData()<< endl;
      ++i;
      current = current->GetNext();
    }
  }
}
