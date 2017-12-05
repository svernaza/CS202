/*
  Samuel Vernaza
  CS202
  Project_9
*/
#ifndef NodeStack_H_
#define NodeStack_H_

#include "DataType.h"

class Node{

  friend class NodeStack;  //allows direct accessing of link and data from class NodeStack

  friend std::ostream& operator<< (std::ostream& os, const Node& srcNode)
  {
    os << "Data value is: " << srcNode.m_data << std::endl;
    return os;
  }

  public:
    Node() : m_next( NULL ){}
    Node(const DataType& data, Node* next = NULL) :
	  m_next( next ),
	  m_data( data )
	{
	}
	Node(const Node& other) :
	  m_next( other.m_next ),
	  m_data( other.m_data )
	{
	}

    DataType& GetData(){  //gets non-const reference, can be used to modify value of underlying data
      //return const_cast<DataType&>(static_cast<const Node&>(*this).getData());  //an alternative implementation, just for studying reference
	  return m_data;
    }

    const DataType& GetData() const{  //gets const reference, can be used to access value of underlying data
      return m_data;
    }

    //just a fun function I made to test some other stuff
    //can be ignored
    DataType& SetData(int intVal, double doubleVal)
    {
      m_data.SetIntVal(intVal);
      m_data.SetDoubleVal(doubleVal);
      return m_data;
    }

    //my implementation
    Node* GetNext() const {
      return m_next;
    }

  private:
    Node* m_next;
    DataType m_data;
};

class NodeStack{
  friend std::ostream& operator<<(std::ostream& os,	
					       const NodeStack& NodeStack);
  public:
    NodeStack();
    NodeStack(size_t count, const DataType& value);
    NodeStack(const NodeStack& other);
    ~NodeStack();

    NodeStack& operator= (const NodeStack& rhs);

    DataType& top();
    const DataType& top() const;

    void push(const DataType& value);
    void pop();

    size_t size() const;
    bool empty() const;
    bool full() const;
    void clear();
    void serialize(std::ostream& os) const;

  private:
    Node* m_top;
};

#endif //NodeStack_H_
