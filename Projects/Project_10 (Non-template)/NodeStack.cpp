/*
  Samuel Vernaza
  Project 9
  CS202
*/
#include <iostream>
#include "NodeStack.h"

/*
  operator<<:
    Outputs the entire contents of a list as per the requirements of the
    std::ostream object that invokes it.
*/
std::ostream& operator<<(std::ostream& os, const NodeStack& srcstack)
{
    srcstack.serialize(os);
    return os;
}

/*
  Default constructor:
    Invokes a new Node object (via the default constructor of the Node Class).
    This node's next pointer is initialized to NULL by the constructor
*/
NodeStack::NodeStack()							    		//(1)
{
  m_top = NULL;
}

/*
  Parameterized constructor:
    Invokes a list of new nodes that are of size Count and initializes
    each m_data member to be the value passed into the constructor.
*/
NodeStack::NodeStack(size_t count, const DataType& value)
{
  if(count <= 0)
  {
    m_top = NULL;
    std::cout << "Zero or less count detected, value not assigned" << std::endl;
  }
  else
  {
    m_top = new Node(value);
    Node * temp = m_top;
    while (--count > 0)
    {
      temp = new Node(value);
      temp->m_next = m_top;
      m_top = temp;
    }
    //deallocate current
    temp = NULL;
  }
}

/*
Copy constructor:
  Takes a pointer to the first node of a list and then copies each value
  into its own LL. This is a standard copy, linearly progressing. The
  reason for this is because we want to keep a direct copy and order of the
  current list. Increased performance assignment, considers three cases of assignment
  no list, one item, more than one item.
*/
NodeStack::NodeStack(const NodeStack& other)					//(3)
{
  if(!other.m_top)
  {
    m_top = NULL;
  }
  else if(!other.m_top->m_next)
  {
    m_top = new Node(other.m_top->m_data);
  }
  else
  {
    Node * otherCurr = other.m_top;
    m_top = new Node (otherCurr->m_data);
    Node * current = m_top;
    otherCurr = otherCurr->m_next;

    while (otherCurr)
    {
      current->m_next = new Node(otherCurr->m_data);
      current = current->m_next;
      otherCurr = otherCurr->m_next;
    }
    current = NULL;
    otherCurr = NULL;
    delete current;
    delete otherCurr;
  }
}

/*
  ~NodeStack:
    Destructor will delete an entire list if it exists. A message is displayed
    with the total number of elements deleted from the node list.
*/
NodeStack::~NodeStack()							   			//(4)
{
  std::cout << std::endl << "------------------------------------" << std::endl;
  std::cout << std::endl << "NodeStack D-tor called!" << std::endl;
  size_t count = 0;
  //convert into a LLL, then delete it
  if(m_top)
  {
    Node * del = m_top;
    while(m_top)
    {
      m_top = m_top->m_next;
      del->m_next = NULL;
      delete del;
      del = m_top;
      ++count;
    }
    del = NULL;
    delete del;
  }
    //Documenting precaution
    std::cout << "Total Number of nodes deleted " << count << std::endl;
    m_top = NULL;
    delete m_top;

}

/*
  operator=
    Checks for self assignment. If not, then the assignment
    takes place. Copies the entire list to a newly allocated one after it first
    removes any list that already existed. m_top's data takes the value of
    rhs' data.
*/
NodeStack& NodeStack::operator= (const NodeStack& rhs)			//(5)
{
  if(this == &rhs)
    return *this;
//delete any list that current exists
    if(m_top)
      clear();

  if(!rhs.m_top)
  {
    m_top = NULL;
  }
  else if(!rhs.m_top->m_next)
  {
    m_top = new Node(rhs.m_top->m_data);
  }
  else
  {
    Node * otherCurr = rhs.m_top;
    m_top = new Node (otherCurr->m_data);
    Node * current = m_top;

    otherCurr = otherCurr->m_next;
    while (otherCurr)
    {
      current->m_next = new Node(otherCurr->m_data);
      current = current->m_next;
      otherCurr = otherCurr->m_next;
    }
    current = NULL;
    otherCurr = NULL;
  }
  return *this;
}

/*
  top():
    Returns a reference to the top element of the stack list.
*/

DataType& NodeStack::top()
{
  std::cout << "Non-const top() method called" << std::endl;
  return m_top->m_data;
}

/*
  ():
    returns a constant reference to the top of the stack list.
*/
const DataType& NodeStack::top() const
{
  std::cout << "Const top() method called" << std::endl;
  return m_top->m_data;
}

/*
  push():
    Takes a const DataType as an argument. Passes this value to the function.
    A new node is created, pushed onto the top of the current list and
    is reassigned to point to this new node. Checks for three conditions: empty,
    one item, multiple elements to decrease traversal time and increase
    efficiency.
*/
void NodeStack::push(const DataType& value)
{
  if(!m_top)
  {
    m_top = new Node(value);
  }
  else
  {
    Node * temp = new Node(value);
    temp->m_next = m_top;
    m_top = temp;
    temp = NULL;
  }
}

/*
  pop():
    Remove the first node in the list from the current stack list.
    Three conditions are tested: There isn't a list, it's returned.
    There's one item in the list, delete current top and set top to NULL.
    Finally, delete the top element and reassign top to point to the second to
    last element of the list.
*/
void NodeStack::pop()
{
  if(!m_top)
    return;
  else if(!m_top->m_next)
  {
    delete m_top;
    m_top = NULL;
  }
  else
  {
    Node * temp = m_top;
    m_top = m_top->m_next;
    delete temp;
    temp = NULL;
  }
}

/*
  size():
    Returns the size of the current stack list object.
*/
size_t NodeStack::size() const               //(13)
{
  size_t count = 0;
  if(m_top)
  {
    Node * current = m_top;
    while(current)
    {
      ++count;
      current = current->m_next;
    }
    current = NULL;
  }
  return count;
}

/*
  empty():
    Returns a boolean value flagging an current stack status.
    Returns True for empty list, False otherwise.
*/
bool NodeStack::empty() const									//(14)
{
  if(!m_top)
    return true;
  return false;
}

/*
  full():
    will always return false because there aren't any size limitations set on
    the Node based stack.
*/
bool NodeStack::full() const
{
  std::cout << "NO size limitations set" << std::endl;
  return false;
}

/*
  Clear():
    Clears the contents of a list and leaves it empty. Note, m_top will be NULL
    autatically based on the value of the next pointer is is assigned throughout
    the deletion process.
*/
void NodeStack::clear()										//(15)
{
  if(m_top)
  {
    Node * del = m_top;
    while(m_top)
    {
      m_top = m_top->m_next;
      del->m_next = NULL;
      delete del;
      del = m_top;
    }
    del = NULL;
  }
}

/*
  serialize:
    Displays the contents of the Node based List using the ostream variable
    passed in.
*/
void NodeStack::serialize(std::ostream& os) const
{
  using std::endl;

  if(!m_top)
  {
    os << "No list to display" << endl;
  }
  else
  {
    Node * current = m_top;
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
