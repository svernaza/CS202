#include <iostream>

#include "DataType.h"

using namespace std;


class Node{

  friend class Queue;      //allows direct accessing of link m_next from queue class (otherwise, link remains inaccessible outside of Node)

  public:
    Node() 
     : m_next(NULL) { }
    Node(const DataType& data, Node* next = NULL)
     : m_next(next) , m_data(data) { }	    	
    Node(const Node& other)
     : m_next(other.m_next) , m_data(other.m_data) { }

    DataType& GetData(){     //by-Reference access to data (allows mutation/writing)
      return m_data;    	
    }    	
    const DataType& GetData() const{       //by-Reference access to data (read-only)
      return m_data;    	
    }
 
  private:    
    Node* m_next; 						
    DataType m_data;	
};



class Queue{
	
  friend std::ostream& operator<<(std::ostream& os, const Queue& queue);

  public:    
  
    Queue() : 
      m_front(NULL),
      m_back(NULL)
    {
    }
    
    void Push(const DataType& value); 	       
    void Pop();
	void Serialize(std::ostream& os) const; //helper, called by the const-qualified queue object passed to operator<<	

  private:

    Node * m_front, * m_back;
		
};

void Queue::Push(const DataType& value){
  /* Your implementation here */
}

void Queue::Pop(){
  /* Your implementation here */
}

void Queue::Serialize(std::ostream& os) const{
  /* Your implementation here */
}

std::ostream& operator<<(std::ostream& os, const Queue& queue){
    queue.Serialize(os);
    return os;
}


int main(){
	
	Queue queue;

    for (size_t i=0; i<10; ++i){
      DataType dt_i(i, 0.1*i);
      queue.Push( dt_i );	
	}	
    cout << endl << queue << endl;

	for (size_t i=0; i<5; ++i){
      queue.Pop( );	
	}
    cout << endl << queue << endl;

}

