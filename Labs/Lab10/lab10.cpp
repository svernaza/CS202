#include <iostream>

#include DataType.h

using namespace std;


class Node{
	friend class LinkedList;
public:
	Node():m_next(NULL) {}
	Node(const DataType& data, Node* next = NULL)
	:m_next(next), m_data(data) {}
	Node(const Node & other)
	:m_next(other.m_next), m_data(other.m_data) {}
	DataType& GetData(){
		return m_data;
	}
	const DataType& GetData() const {
		return m_data;
	}
private:
	DataType m_data;
	Node * m_next;
  /* Your declaration and implementation of class Node that manages class DataType objects */

}


class LinkedList{

  public:

    LinkedList();

    void InsertLast(const DataType& value);

    size_t size() const;

  private:
    Node * m_head;
}

LinkedList::LinkedList()
{
	m_head = new Node(NULL);
  /* Your implementation here */
}

void LinkedList::InsertLast(const DataType& value){
  /* Your implementation here */
	if(!m_head)
	{
			m_head = new Node(value);
	}
	else if(!m_head->m_next)
	{
		m_head->next = new Node(value);
	}
	else
	{
		Node * current = m_head;
		Node * temp = new Node(value);
		while(current->m_next)
			current = current->m_next;
		current->next = temp;
	}
}

size_t LinkedList::size() const{
  /* Your implementation here */
	Node * current = m_head;
	size_t i = 0;
	while(current)
	{
		++i;
		current = current->m_head;
	}
	return i;
}


int main(){

	LinkedList list;
	cout << endl << list.size() << endl;

	DataType dt_01(0, 1.0);
	list.InsertLast( dt_01 );
    cout << endl << list.size() << endl;

	DataType dt_12(1, 2.0);
	list.InsertLast( dt_12 );
    cout << endl << list.size() << endl;
}
