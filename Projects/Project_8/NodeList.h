#ifndef NODELIST_H_
#define NODELIST_H_

#include "DataType.h"

class Node{

  friend class NodeList;  //allows direct accessing of link and data from class NodeList

  friend std::ostream& operator<< (std::ostream& os, const Node& srcNode)
  {
    os << "Data value is: " << srcNode.m_data << std::endl;
    return os;
  }

  public:
    Node() :
	  m_next( NULL )
	{
	}
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

    //just a fun function I made to test some other stuff
    //can be ignored
    DataType& SetData(int intVal, double doubleVal)
    {
      m_data.SetIntVal(intVal);
      m_data.SetDoubleVal(doubleVal);
      return m_data;
    }

    const DataType& GetData() const{  //gets const reference, can be used to access value of underlying data
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

class NodeList{
  friend std::ostream& operator<<(std::ostream& os,		//(i)
					       const NodeList& nodeList);
  public:
    NodeList();								    		//(1)
    NodeList(size_t count, const DataType& value);		//(2)
    NodeList(const NodeList& other);					//(3)
    ~NodeList();							   			//(4)

    NodeList& operator= (const NodeList& rhs);			//(5)

    Node* First();							    		//(6)
    Node* Last();										//(7)

    Node* Find(const DataType & target,					//(8)
               Node * & previous,
               const Node * start = NULL);

    Node* InsertAfter(const DataType& target,    		//(9)
                      const DataType& value);
    Node* InsertBefore(const DataType& target,    		//(10)
                       const DataType& value);
    Node* Erase(const DataType& target); 			//(11)


    DataType& operator[] (size_t position);				//(12a)
    const DataType& operator[] (size_t position) const;	//(12b)

    size_t size() const;								//(13)
    bool empty() const;									//(14)
    void clear();										//(15)

  private:
    Node * m_head;
};

#endif //NODELIST_H_
