#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include "DataType.h"

class ArrayList{

  friend std::ostream& operator<<(std::ostream& os,			//(i)
					       const ArrayList& arrayList);

  public:
    ArrayList();								    		//(1)
    ArrayList(size_t count, const DataType& value);			//(2)
    ArrayList(const ArrayList& other);				    	//(3)
    ~ArrayList();							    			//(4)

    ArrayList& operator= (const ArrayList& rhs);			//(5)


    DataType* First();							     		//(6)
    DataType* Last();						                //(7)

    DataType* Find(const DataType & target,				    //(8)
                   DataType * & previous,
                   const DataType * start = NULL);

    DataType* InsertAfter(const DataType& target,     		//(9)
                          const DataType& value);
    DataType* InsertBefore(const DataType& target,  		//(10)
                           const DataType& value);
    DataType* Erase(const DataType& target);		 		//(11)


    DataType& operator[] (size_t position);					//(12)

    size_t size() const;									//(13)
    bool empty() const;										//(14)
    void clear();											//(15)

  private:

/*
	deallocate memory pointed to by m_array.
	allocate enough total memory to fit the count
	m_array will be copied over to newly allocated one.
	Enlarges:
		only valid ArrayList elements m_size in total copied.
		Rest (m_maxsize-m_size) should have default value
	Shrink:
*/
    void resize(size_t count);	               			//(16)
//points to D_array data. Container for ArrayList
//resized whenever it needs to grow/shrink
		DataType * m_array;
//keeps track of DataType elements currently stored and valid
    size_t m_size;
//maximum size of the entire array's potential storage.
    size_t m_maxsize;
	};


#endif //ARRAYLIST_H_
