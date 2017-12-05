/*
  Samuel Vernaza
  Project 8
  CS202
*/
#include <iostream>
#include "NodeList.h"

/*
  Default constructor:
    Invokes a new Node object (via the default constructor of the Node Class).
    This node's next pointer is initialized to NULL by the constructor
*/

NodeList::NodeList()							    		//(1)
{
  m_head = new Node;
}

//uncomment for empty() test and comment the above destructor
/*
NodeList::NodeList()
{
  m_head = NULL;
}
*/

/*
  Parameterized constructor:
    Invokes a list of new nodes that are of size Count and initializes
    each m_data member to be the value passed into the constructor.
*/
NodeList::NodeList(size_t count, const DataType& value)
{
  if(count <= 0)
  {
    m_head = NULL;
    std::cout << "Zero or less count detected, value not assigned" << std::endl;
  }
  else
  {
    m_head = new Node(value);

    Node * current = m_head;
    while (--count > 0)
    {
      //invokes Parameterized constructor to have a m_data value of value.
      //believe it should automatically handle the assignment.
      current->m_next = new Node(value);
      current = current->m_next;
    }
    //deallocate current
    current = NULL;
    delete current;
  }
}		//(2)

/*
  Copy constructor:
    Takes a pointer to the first node of a list and then copies each value
    into its own LL.
*/
NodeList::NodeList(const NodeList& other)					//(3)
{
/*
  increased performance assignment, considers three cases of assignment
  no list, one item, more than one item.
*/
  if(!other.m_head)
  {
    m_head = NULL;
  }
  else if(!other.m_head->m_next)
  {
    m_head = new Node(other.m_head->m_data);
  }
  else
  {
    Node * otherCurr = other.m_head;
    m_head = new Node (otherCurr->m_data);
    Node * current = m_head;
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
  ~Nodelist:
    Destructor will delete an entire list if it exists. Otherwise a message is
    recorded
*/
NodeList::~NodeList()							   			//(4)
{
  std::cout << std::endl << "------------------------------------" << std::endl;
  std::cout << std::endl << "NodeList D-tor called!" << std::endl;
  size_t count = 0;
  if(m_head)
  {
    Node * del = m_head;
    while(m_head)
    {
      m_head = m_head->m_next;
      del->m_next = NULL;
      delete del;
      del = m_head;
      ++count;
    }
    del = NULL;
    delete del;
  }
    //safety precaution
    std::cout << "Total Number of nodes deleted " << count << std::endl;
    m_head = NULL;
    delete m_head;

}

/*
  operator=
    Checks if the same assignment is happenning. If not, then the assignment
    takes place and copies over the entire list to another after it first
    removes any list that already existed. m_head is then assigned the value of
    rhs.
*/
NodeList& NodeList::operator= (const NodeList& rhs)			//(5)
{
  if(this == &rhs)
    return *this;
//delete any list that current exists
    if(m_head)
    {
      Node * del = m_head;
      while(m_head)
      {
        m_head = m_head->m_next;
        del->m_next = NULL;
        delete del;
        del = m_head;
      }
      del = NULL;
      delete del;
    }
/*
  increased performance assignment, considers three cases of assignment
  no list, one item, more than one item.
*/
  if(!rhs.m_head)
  {
    m_head = NULL;
    return *this;
  }
  else if(!rhs.m_head->m_next)
  {
    m_head = new Node(rhs.m_head->m_data);
    return *this;
  }
  else
  {
    Node * otherCurr = rhs.m_head;
    m_head = new Node (otherCurr->m_data);
    Node * current = m_head;

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
    return *this;
  }
}

/*
  First:
    Returns a pointer to the first node of a list if it exists, else NULL is
    returned.
*/
Node* NodeList::First()							    		//(6)
{
  if(m_head)
    return m_head;
  else
    return NULL;
}

/*
  Last:
    Returns the last Node in the list by traversal.
*/
Node* NodeList::Last()										//(7)
{
  if(m_head)
  {
    Node * last = m_head;
    while(last->m_next)
    {
      last = last->m_next;
    }
    return last;
  }
  else
    return NULL;
}

/*
  Find:
    Searches a NodeList for the ocuraence of a match to the target value.
    If a match is found then it returns the current pointer to the Node
    and assigns that value to the calling client.
*/
Node* NodeList::Find(const DataType & target,					//(8)
           Node * & previous,
           const Node * start)
{
  size_t i = 0;
  if(!m_head)
  {
    std::cout << i << " Nodes searched" << std::endl;
    return NULL;
  }
  else if(!m_head->m_next)
  {
    if(target == m_head->m_data)
    {
      //start = m_head;
      previous = NULL;
      std::cout << ++i << " Nodes searched" << std::endl;
      return m_head;
    }
    else
      return NULL;
  }
  else
  {
    Node * current = m_head;
    while (current)
    {
      if(current->m_data == target)
        {
          std::cout << i << " Nodes searched" << std::endl;
          std::cout << "Match found at position" << ++i << " Node" << std::endl;
          return current;
        }
      previous = current;
      current = current->m_next;
      ++i;
    }
    current = NULL;
    delete current;
    std::cout << i << " Nodes searched" << std::endl;
    return NULL;
  }
}

/*
  InsertAfter:
    searches a list for the target value, if the target value is found it
    will insert the new node after this value initialized to the value
    passed into it.
*/
Node* NodeList::InsertAfter(const DataType& target,    		//(9)
                  const DataType& value)
{
  if(!m_head)
    return NULL;
  else if(!m_head->m_next)
  {
    if(m_head->m_data == target)
    {
      m_head->m_next = new Node(value);
      return m_head;
    }
    return NULL;
  }
  else
  {
    Node * current = m_head;
    while(current)
    {
      if (current->m_data == target)
      {
        Node * temp = new Node(value);
        temp->m_next = current->GetNext();
        current->m_next = temp;
        temp = NULL;
        delete temp;
        return current;
      }
      current = current->m_next;
    }
    current = NULL;
    delete current;
    return NULL;
  }
}

/*
  InsertBefore:
    Uses the target value passed in to check the value of the current NodeList.
    If the current Node's value matches the DataType target passed in then a
    new node is inserted before the target values occurence.
*/
Node* NodeList::InsertBefore(const DataType& target,    		//(10)
                   const DataType& value)
{
  if(!m_head)
    return NULL;
  else if(!m_head->m_next)
  {
    Node * prev = NULL;
    if(m_head->m_data == target)
    {
      prev = new Node(value);
      prev->m_next = m_head;
      m_head = prev;
      return prev;
    }
    return NULL;
  }
  else
  {
    Node * prev = NULL;
    Node * current = m_head;
    prev = current;
    while(current)
    {
      if(current->m_data == target)
      {
        Node * temp = new Node(value);
        temp->m_next = prev->m_next;
        prev->m_next = temp;
        return temp;
      }
      prev = current;
      current = current->m_next;
    }
    return NULL;
  }
}

/*
  Erase:
    Searches a list for a value and Erases a node from the list if the data
    matches the target value.
*/
Node* NodeList::Erase(const DataType& target) 			//(11)
{
  if(!m_head)
    return NULL;
  else if(!m_head->m_next)
  {
    if(m_head->m_data == target)
    {
      m_head = NULL;
      delete m_head;
      return NULL;
    }
  }
  else
  {
    Node * current = m_head;
    Node * prev = current;
    while(current)
    {
      if(current->m_data == target)
      {
        Node * ret = current->m_next;
        prev->m_next = ret;
        current->m_next = NULL;
        delete current;
        return ret;

      }
      prev = current;
      current = current->m_next;
    }
    return NULL;
  }
  return NULL;
}


/*
  operator[]:
    returns the data found at a position within the list. NO error checking.
    Behavior undefined. Non-const version.
*/
DataType& NodeList::operator[] (size_t position)				//(12)
{
    std::cout << "Inside non-const" << std::endl;
    Node * current = m_head;
    size_t i = 0;
    while(i < position)
    {
      current = current->m_next;
      ++i;
    }
    return (current->m_data);
}

/*
  operator[]:
    returns the data found at a position within the list. NO error checking.
    Behavior undefined. Const-version used.
*/
const DataType& NodeList::operator[] (size_t position) const				//(12)
{
  std::cout << std::endl << "Inside const" << std::endl;
  Node * current = m_head;
  size_t i = 0;
  while(i < position)
  {
    current = current->m_next;
    ++i;
  }
  return (current->m_data);
}

/*
  size():
    Returns the size of the current list object.
*/
size_t NodeList::size() const               //(13)
{
  size_t count = 0;
  if(m_head)
  {
    Node * current = m_head;
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
bool NodeList::empty() const									//(14)
{
  if(!m_head)
    return true;
  return false;
}

/*
  Clear():
    Clears the contents of a list and leaves it empty.
*/
void NodeList::clear()										//(15)
{
  if(m_head)
  {
    Node * del = m_head;
    while(m_head)
    {
      m_head = m_head->m_next;
      del->m_next = NULL;
      delete del;
      del = m_head;
    }
    del = NULL;
    delete del;
  }
}

/*
  operator<<:
    Outputs the entire contents of a list as per the requirements of the
    std::ostream object that invokes it.
*/
std::ostream& operator<<(std::ostream& os, const NodeList& nodeList)
{
  using std::endl;

  if(!nodeList.m_head)
  {
    os << "No list to display" << endl;
    return os;
  }
  else
  {
    Node * current = nodeList.m_head;
    //display first node on a new line
    os << endl;

    size_t i = 1;
    while(current)
    {
      os << "Value of Node " << i << ": " << current->GetData() << endl;
      ++i;
      current = current->GetNext();
    }
    return os;
  }
}
