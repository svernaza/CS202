#ifndef ArrayStack_H_
#define ArrayStack_H_

#include "DataType.h"

const size_t MAX_STACKSIZE = 1000;

class ArrayStack{

  friend std::ostream& operator<<(std::ostream& os,			//(i)
					       const ArrayStack& arrayStack);

  public:
    ArrayStack();								    		//(1)
    ArrayStack(size_t count, const DataType& value);			//(2)
    ArrayStack(const ArrayStack& other);				    	//(3)
    ~ArrayStack();							    			//(4)

    ArrayStack& operator= (const ArrayStack& rhs);			//(5)

    DataType& top();
    const DataType& top() const;

    void push(const DataType& value);
    void pop();

    size_t size() const;									//(13)
    bool empty() const;
    bool full() const;									//(14)
    void clear();
    void serialize(std::ostream& os) const;								//(15)

  private:
    DataType m_container[MAX_STACKSIZE];
    size_t m_top;
	};

#endif //ArrayStack_H_
