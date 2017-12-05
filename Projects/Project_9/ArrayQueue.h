#ifndef ArrayQueue_H_
#define ArrayQueue_H_

#include "DataType.h"

const size_t ARRAY_MAX = 1000;

class ArrayQueue{

  friend std::ostream& operator<<(std::ostream& os,			//(i)
					       const ArrayQueue& ArrayQueue);

  public:
    ArrayQueue();								    		//(1)
    ArrayQueue(size_t count, const DataType& value);			//(2)
    ArrayQueue(const ArrayQueue& other);				    	//(3)
    ~ArrayQueue();							    			//(4)

    ArrayQueue& operator= (const ArrayQueue& rhs);			//(5)

    DataType& front();
    const DataType& front() const;

    DataType& back();
    const DataType& back() const;

    void push(const DataType& value);
    void pop();

    size_t size() const;									//(13)
    bool empty() const;
    bool full() const;									//(14)
    void clear();
    void serialize(std::ostream& os) const;								//(15)

  private:
    DataType m_array[ARRAY_MAX];
    size_t m_front;
    size_t m_back;
    size_t m_size;
	};


#endif //ArrayQueue_H_
