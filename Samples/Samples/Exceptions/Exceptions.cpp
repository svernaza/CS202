/**
 * @brief  CS-202 Finals Sample
 * @Author Christos Papachristos (cpapachristos@unr.edu)
 * @date   October, 2017
 *
 * This file shows a sample implementation of Exception class hierarchies (Base Exception - Derived Exception) for the purposes of CS-202
 * The exceptions are thrown from within the contructors and/or methods of a Templated Array-based Stack class, and a test-driver main() is also provided
 */

#include <iostream>
#include <string>
#include <sstream>
// Helper for std::to_string http://en.cppreference.com/w/cpp/string/basic_string/to_string which is unfortunately not there in g++, irrelevant with Exceptions for the purposes of this sample
template < typename T > std::string to_string( const T& n ){
  std::ostringstream stm;
  stm << n ;
  return stm.str() ;
}
using namespace std;


/*
 *************************************
 * The Exception class(es) hierarchy *
 *************************************
*/  


/** 
 * A generic exception class, that carries a std::string member named m_info.
 * Its constructor initializes m_info with a string which is indicative (descriptive) of the exception cause 
 */
class MyException{
  public:
    MyException();
    MyException(const char* s)
      : m_info( s )
    {
    }
    /* 
     * Base class Polymorphic info()
     * vitrual so it can be overriden
     */
    virtual const char* info() const {  
      return m_info.c_str(); 
    }  
  protected:
    std::string m_info;
};

/** 
 * A specialized exception class, that initializes the m_info std::string of the Parent class to something like: "Self-Assignment attempted"
 */
class MySelfAssignmentException : public MyException{
  public:
    MySelfAssignmentException()
      : MyException("Self-Assignment attempted...")
    {
    }
};

/**
 * A specialized exception class, that initializes the m_info std::string of the Parent class to something like: "Bad Size instantiation attempted"
 * This Derived class also has a std::size_t member named m_badsize, which is instantiated with the value that was the actual bad size that triggered the exception
 * and a std::string m_info_with_value member, which is the concatenated m_info and the m_badsize and can be updated
 */
class MyBadsizeException : public MyException{
  public:
    MyBadsizeException()
      : MyException("Bad Size instantiation attempted..."),
        m_badsize( 0 ),
        m_info_with_value( m_info + " (" + to_string( m_badsize ) + ")" )
    {
    }
    MyBadsizeException(std::size_t badsize)
      : MyException("Bad Size instantiation attempted..."),
        m_badsize( badsize ),
        m_info_with_value( m_info + " (" + to_string( m_badsize ) + ")" )
    {
    }
    const std::size_t& badsize() const {
      return m_badsize;
    }
    /* 
     * Derived class Polymorphic info() - overrides Base class one 
     * Note: If info() method is not virtual, then the behavior of catch()'ing by-Base-Class-Reference (const MyException& e) in the test driver will be the non-polyomrphic one of the Base class.
     */
    virtual const char* info() const {  
      return m_info_with_value.c_str(); 
    }  
  private:
    std::size_t m_badsize; 
    std::string m_info_with_value;
};



/*
 *******************************************
 * The templated ArrayStack implementation *
 *******************************************
*/  


const std::size_t MAX_SIZE = 1000000;
const std::size_t DEFAULT_SIZE = 1000;

template<class T, std::size_t N> class ArrayStack;
template<class T, std::size_t N> std::ostream& operator<<(std::ostream& os, const ArrayStack<T,N>& aS);

template <class T, std::size_t N=DEFAULT_SIZE>
class ArrayStack{
  public:
    ArrayStack(); 
    ArrayStack(std::size_t size, const T& value=T());
    ArrayStack(const ArrayStack<T,N>& other); 
    ~ArrayStack();

    ArrayStack& operator= (const ArrayStack<T,N>& other);

    const T& top() const;
    T& top();

    void push(const T& value);
    void pop(); 
    void clear();

    std::size_t size() const;
    bool empty() const;
    bool full() const;
    void serialize(std::ostream& os) const;

  friend std::ostream& operator<< <> (std::ostream& os, const ArrayStack<T,N>& aS);

  private:
    T m_container[N];
    std::size_t m_size;
};

template<class T, std::size_t N>
ArrayStack<T,N>::ArrayStack(){
  if (!N || N>MAX_SIZE){
    throw MyBadsizeException(N);
  }
  m_size = 0;
}

template<class T, std::size_t N>
ArrayStack<T,N>::ArrayStack(std::size_t size, const T& value){
  if (!N || N>MAX_SIZE){
    throw MyBadsizeException(N);
  }
  if (size>N){
    throw MyBadsizeException(size);
  }
  m_size = size;
  for (std::size_t i=0; i<m_size; ++i){
    m_container[i] = value;
  }
}

template<class T, std::size_t N>
ArrayStack<T,N>::ArrayStack(const ArrayStack<T,N>& other){
  if (!N || N>MAX_SIZE){
    throw MyBadsizeException(N);
  }
  m_size = other.m_size;
  for (std::size_t i=0; i<m_size; ++i){
    m_container[i] = other.m_container[i];
  }
}

template<class T, std::size_t N>
ArrayStack<T,N>::~ArrayStack(){
  // nothing to do here, static array is deallocated automatically ...
}

template<class T, std::size_t N>
ArrayStack<T,N>& ArrayStack<T,N>::operator= (const ArrayStack<T,N>& other){
  if(this==&other){
    throw MySelfAssignmentException();
  }
  m_size = other.m_size;
  for (std::size_t i=0; i<m_size; ++i){
    m_container[i] = other.m_container[i];
  }
  return *this;
}

template<class T, std::size_t N>
const T& ArrayStack<T,N>::top() const{
  if (!m_size){
    throw MyException("Tried to get reference to top element of an empty stack...");
  }
  return m_container[m_size-1];
}

template<class T, std::size_t N>
T& ArrayStack<T,N>::top(){
  if (!m_size){
    throw MyException("Tried to get reference to top element of an empty stack...");
  }
  return m_container[m_size-1];
}

template<class T, std::size_t N>
void ArrayStack<T,N>::push(const T& value){
  if (m_size >= N){
    throw MyException("Pushing on a full stack attempted...");
  }
  m_container[m_size++] = value;
}

template<class T, std::size_t N>
void ArrayStack<T,N>::pop(){
  if (!m_size){
    throw MyException("Popping from an empty stack attempted...");
  }
  --m_size;
}

template<class T, std::size_t N>
void ArrayStack<T,N>::clear(){
  --m_size = 0;
}

template<class T, std::size_t N>
std::size_t ArrayStack<T,N>::size() const{
  return m_size;
}

template<class T, std::size_t N>
bool ArrayStack<T,N>::empty() const{
  return !m_size;
}

template<class T, std::size_t N>
bool ArrayStack<T,N>::full() const{
  return (m_size >= N);
}

template<class T, std::size_t N>
void ArrayStack<T,N>::serialize(std::ostream& os) const{
  if (!m_size){
    throw MyException("Tried to output an empty stack...");
  }
  for (std::size_t i=0; i<m_size; ++i){
    os << m_container[i] << " ";
  }
}

template<class T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const ArrayStack<T,N>& aS){
  aS.serialize(os);
  return os;
}


/*
 *******************
 * The test driver *
 *******************
*/  


int main(){

  /* TEST 1 */
  // try to create a stack of 100 int elements
  cout << endl << "TEST 1" << endl;
  try{
    ArrayStack<int, 100> intStack0;
  }
  catch(const MyException& e){
    cerr << e.info() << endl;
  }

  /* TEST 2 */
  // try to create a stack of 10 int elements (through the template parameter list), but then request instantiation of an object of size 100 (defined through constructor parameter list)
  cout << endl << "TEST 2" << endl;
  try{
    ArrayStack<int, 10> intStack1(100);
  }
  catch(const MyException& e){
    cerr << e.info() << endl;
  }


  /* TEST 3 */
  // try to create a stack without specifying template parameter for size (through template parameter list this will default to 1000), but then request instantiation of an object of size 5000 (defined through constructor parameter list)
  cout << endl << "TEST 3" << endl;
  try{
    ArrayStack<int> intStack2(5000, -10);
  }
  catch(const MyException& e){
    cerr << e.info() << endl;
  }


  /* TEST 4 */
  // try to create a stack without specifying template parameter for size (through template parameter list this will default to 1000), and then request instantiation of an object of size 500 (defined through constructor parameter list)
  cout << endl << "TEST 4" << endl;
  try{
    ArrayStack<int> intStack3(500,-10);
  }
  catch(const MyException& e){
    cerr << e.info() << endl;
  }


  /* TEST 5 */
  // try to create a stack with size > N, and then try to create another stack via copy-constructor
  cout << endl << "TEST 5" << endl;
  try{
    ArrayStack<int> intStack4(2000,-2);
    ArrayStack<int> intStack5( intStack4 );
  }
  catch(const MyException& e){
    cerr << e.info() << endl;
  }


  /* TEST 6 */
  cout << endl << "TEST 6" << endl;
  try{
    ArrayStack<int, 10> intStack6;
    ArrayStack<int, 10>* intStack6_Pt = &intStack6;

    //try to perform assignment but pass the same object (self-assignment)
    intStack6 = *intStack6_Pt;
  }
  catch(const MyException& e){
    cerr << e.info() << endl;
  }


  /* TEST 7 */
  cout << endl << "TEST 7" << endl;
  ArrayStack<int, 5> intStack7;

  try{
    //try to output an empty stack
    cout << intStack7 << endl;
  }
  catch(const MyException& e){
    cerr << e.info() << endl;
  }

  try{
    //try to get and output the top element of an empty stack
    int no_top_element = intStack7.top();
    cout << no_top_element << endl;
  }
  catch(const MyException& e){
    cerr << e.info() << endl;
  }

  try{
    //try to push 2 elements and then output the non-empty stack 
    intStack7.push(1);
    intStack7.push(2);
    cout << intStack7 << endl;
  }
  catch(const MyException& e){
    cerr << e.info() << endl;
  }

  try{
    //try to get and output the top element of a non-empty stack
    int valid_top_element = intStack7.top();
    cout << valid_top_element << endl;
  }
  catch(const MyException& e){
    cerr << e.info() << endl;
  }

  try{
    //try to push another 5 elements (7 total) on a stack of size 5, and then output the non-empty stack
    intStack7.push(3);
    intStack7.push(4);
    intStack7.push(5);
    intStack7.push(6);
    intStack7.push(7);
    cout << intStack7 << endl;
  }
  catch(const MyException& e){
    cerr << e.info() << endl;
  }

  try{
    //try to output the non-empty stack 
    cout << intStack7 << endl;
  }
  catch(const MyException& e){
    cerr << e.info() << endl;
  }
  /* Stack unwinding DOES NOT REVERSE the side-effects of what happened inside a try block! Therefore the stack will have 12345 (these elements were already pushed until the exception was raised) */

}

