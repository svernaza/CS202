/*
  Samuel Vernaza
  CS202
  Project_10
*/
#ifndef NodeStack_H_
#define NodeStack_H_

//#include "DataType.h"

//forward declarations
template <class T>
class Node;

template <class T>
std::ostream& operator<<(std::ostream& os, const Node<T>& srcNode);

template <class T>
class NodeStack;

template <class T>
std::ostream& operator<<(std::ostream& os, const NodeStack<T>& NodeStack);

//template class declaration
template <class T>
class Node{

  friend class NodeStack<T>;  //allows direct accessing of link and data from class NodeStack

  friend std::ostream& operator<< (std::ostream& os, const Node<T>& srcNode)
  {
    os << "Data value is: " << srcNode.m_data << std::endl;
    return os;
  }

  public:
    Node() : m_next( NULL ){}
    Node(const T& data, Node<T>* next = NULL) :
	  m_next( next ),
	  m_data( data )
	{
	}
	Node(const Node<T>& other) :
	  m_next( other.m_next ),
	  m_data( other.m_data )
	{
	}

    T& GetData(){  //gets non-const reference, can be used to modify value of underlying data
      //return const_cast<DataType&>(static_cast<const Node&>(*this).getData());  //an alternative implementation, just for studying reference
	  return m_data;
    }

    const T& GetData() const{  //gets const reference, can be used to access value of underlying data
      return m_data;
    }

    //just a fun function I made to test some other stuff
    //can be ignored
    T& SetData(int intVal, double doubleVal)
    {
      m_data.SetIntVal(intVal);
      m_data.SetDoubleVal(doubleVal);
      return m_data;
    }

    //my implementation
    Node<T>* GetNext() const {
      return m_next;
    }

  private:
    Node<T>* m_next;
    T m_data;
};

//templated class declaration
template <class T>
class NodeStack{
  friend std::ostream& operator<< < >(std::ostream& os,
					       const NodeStack<T>& NodeStack);
  public:
    NodeStack();
    NodeStack(size_t count, const T& value);
    NodeStack(const NodeStack<T>& other);
    ~NodeStack();

    NodeStack<T>& operator= (const NodeStack<T>& rhs);

    T& top();
    const T& top() const;

    void push(const T& value);
    void pop();

    size_t size() const;
    bool empty() const;
    bool full() const;
    void clear();
    void serialize(std::ostream& os) const;

  private:
    Node<T>* m_top;
};

//template class implemenations
/*
  operator<<:
    Outputs the entire contents of a list as per the requirements of the
    std::ostream object that invokes it.
*/
template <class T>
std::ostream& operator<<(std::ostream& os, const NodeStack<T>& srcstack)
{
    srcstack.serialize(os);
    return os;
}

/*
  Default constructor:
    Invokes a new Node object (via the default constructor of the Node Class).
    This node's next pointer is initialized to NULL by the constructor
*/
template <class T>
NodeStack<T>::NodeStack()							    		//(1)
{
  m_top = NULL;
}

/*
  Parameterized constructor:
    Invokes a list of new nodes that are of size count and initializes
    each m_data member to be the value passed into the constructor.
*/
template <class T>
NodeStack<T>::NodeStack(size_t count, const T& value)
{
  if(count <= 0)
  {
    m_top = NULL;
    std::cout << "Zero or less count detected, value not assigned" << std::endl;
  }
  else
  {
    m_top = new Node<T>(value);
    Node<T>* temp = m_top;
    while (--count > 0)
    {
      temp = new Node<T>(value);
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
  current list. Increased performance assignment, considers three cases of
  assignment no list, one item, more than one item.
*/
template <class T>
NodeStack<T>::NodeStack(const NodeStack<T>& other)					//(3)
{
  if(!other.m_top)
  {
    m_top = NULL;
  }
  else if(!other.m_top->m_next)
  {
    m_top = new Node<T>(other.m_top->m_data);
  }
  else
  {
    Node<T>* otherCurr = other.m_top;
    m_top = new Node<T>(otherCurr->m_data);
    Node<T>* current = m_top;
    otherCurr = otherCurr->m_next;

    while (otherCurr)
    {
      current->m_next = new Node<T>(otherCurr->m_data);
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
template <class T>
NodeStack<T>::~NodeStack()							   			//(4)
{
  std::cout << std::endl << "------------------------------------" << std::endl;
  std::cout << std::endl << "NodeStack D-tor called!" << std::endl;
  size_t count = 0;
  //convert into a LLL, then delete it
  if(m_top)
  {
    Node<T>* del = m_top;
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
template <class T>
NodeStack<T>& NodeStack<T>::operator= (const NodeStack<T>& rhs)			//(5)
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
    m_top = new Node<T>(rhs.m_top->m_data);
  }
  else
  {
    Node<T>* otherCurr = rhs.m_top;
    m_top = new Node<T>(otherCurr->m_data);
    Node<T>* current = m_top;

    otherCurr = otherCurr->m_next;
    while (otherCurr)
    {
      current->m_next = new Node<T>(otherCurr->m_data);
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
template <class T>
T& NodeStack<T>::top()
{
  std::cout << "Non-const top() method called" << std::endl;
  return m_top->m_data;
}

/*
  ():
    returns a constant reference to the top of the stack list.
*/
template <class T>
const T& NodeStack<T>::top() const
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
template <class T>
void NodeStack<T>::push(const T& value)
{
  if(!m_top)
  {
    m_top = new Node<T>(value);
  }
  else
  {
    Node<T> * temp = new Node<T>(value);
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
template <class T>
void NodeStack<T>::pop()
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
    Node<T>* temp = m_top;
    m_top = m_top->m_next;
    delete temp;
    temp = NULL;
  }
}

/*
  size():
    Returns the size of the current stack list object.
*/
template <class T>
size_t NodeStack<T>::size() const               //(13)
{
  size_t count = 0;
  if(m_top)
  {
    Node<T> * current = m_top;
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
    Returns a boolean value flagging a current stack status.
    Returns True for empty list, False otherwise.
*/
template <class T>
bool NodeStack<T>::empty() const									//(14)
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
template <class T>
bool NodeStack<T>::full() const
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
template <class T>
void NodeStack<T>::clear()										//(15)
{
  if(m_top)
  {
    Node<T> * del = m_top;
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
template <class T>
void NodeStack<T>::serialize(std::ostream& os) const
{
  using std::endl;

  if(!m_top)
  {
    os << "No list to display" << endl;
  }
  else
  {
    Node<T> * current = m_top;
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

#endif //NodeStack_H_
