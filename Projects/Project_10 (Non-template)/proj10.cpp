/*
  Samuel Vernaza
  CS202
  Project_8
*/

#include <iostream>

#include "ArrayStack.h"
#include "NodeStack.h"

using namespace std;

int main(){

  //Testing DataType default constructor
  DataType myData;
  cout << "DataType Default C-tor worked!" << endl;
  cout << "Value of myData: " << myData << endl;

  //Testing DataType Parameterized Constructor
  DataType otherData(5, 10.0);
  cout << endl << "DataType Parameterized C-tor Worked!" << endl;
  //Testing the overloaded operator << of the DataType
  cout << "Value of otherData: " << otherData << endl;

  //Testing DataType CopyConstructor
  DataType copyData(otherData);
  cout << endl << "DataType Copy C-tor Worked!" << endl;
  cout << "Value of copyData" << copyData << endl;

  //Testing DataType operator==
  if(copyData == otherData)
    cout << endl << "Overloaded operator works and they are the same" << endl;
  else
    cout << endl << "Overloaded operator works, they are the different" << endl;

  //Testing DataType GetIntVAl()
  cout << endl << "Testing DataType GetIntVAle()" << endl;
  cout << "copyData.GetIntVal(): " << copyData.GetIntVal() << endl;

  //Testing DataType SetIntVal()
  cout << endl << "Testing DataType SetIntVal()" << endl;
  copyData.SetIntVal(35);
  cout << "copyData.SetIntVal() set!" << endl;
  cout << "copyData int value is: " << copyData.GetIntVal() << endl;

  //Testing DataType GetDoubleVal()
  cout << endl << "Testing DataType GetDoubleVal()" << endl;
  cout << "copyData.GetDoubleVal(): " << copyData.GetDoubleVal() << endl;

  cout << endl << "Testing DataType SetDoubleVal()" << endl;
  cout << "copyData.SetDoubleVal() set!" << endl;
  copyData.SetDoubleVal(1.0);
  cout << "copyData double value is: " << copyData.GetDoubleVal() << endl;

  cout << "--------------------------------------------------------" << endl;

  //Test node constructor
  cout << endl << "Testing the Node class and Creation of Nodes" << endl;

  Node myNode;
  cout << endl << "Default myNode constructor worked!" << endl;
  cout << "Value of myNode" << myNode << endl;

  cout << endl << "Testing Parameterized Node C-tor" << endl;
  Node otherNode(copyData);
  cout << "Node Parameterized C-tor worked!" << endl;
  cout << "Value of otherNode" << otherNode << endl;

  cout << endl << "Testing Copy C-tor" << endl;
  Node copyNode(otherNode);
  cout << "Node Copy C-tor" << endl;
  cout << "Value of CopyNode: " << copyNode << endl;

  //envokes the operator<< for m_data can do both const and non const
  cout << endl << "Testing GetData(): " << endl;
  cout << "copyNode.GetData(): " << copyNode.GetData() << endl;

  cout << "--------------------------------------------------------" << endl;

  cout << endl << "Now testing the NodeStack class!" << endl;

  cout << endl << "Testing the NodeStack default C-tor" << endl;
  NodeStack newList;
  cout << "newList value: " << newList << endl;

  //setting other list to zero will cause seg faults
  cout << endl << "Testing NodeStack Parameterized C-tor " << endl;
  NodeStack otherList(10, copyData);
  cout << "NodeStack Parameterized C-tor works " << endl;
  cout << "otherList value: " << otherList << endl;

  cout << endl << "Testing NodeStack Copy C-tor " << endl;
  NodeStack copiedList(otherList);
  cout << "NodeStack Copy C-tor works " << endl;
  cout << "otherList value: " << copiedList << endl;

  cout << endl << "Testing NodeStack Assignment operator" << endl;
  NodeStack assignList(10, copyData);
  assignList = otherList;
  cout << "NodeStack Assignment works!" << endl;
  cout << "assignList\'s value is: " << assignList << endl;

  cout << endl << "Testing NodeStack\'s top()" << endl;
  DataType top = assignList.top();
  cout << "Node\'s data is: " << top << endl;

  //change value of to find in order to verify match/no-match condition
  cout << endl << "Testing the NodeStack\'s push()" << endl;
  DataType toTop(45, 10.0);
  assignList.push(toTop);
  cout << "New List value is: " << assignList << endl;

/*
  //this is for testing multiple items pushed onto the stack
  //uncomment to test
  cout << endl << "Testing optional multi-push functionality" << endl;
  cout << "Will automatically insert values" << endl;
  cout << "Enter the number of new elements you would like to add" << endl;
  int input;
  cin >> input;
  if(input < 0)
  {
    cout << "Reinsert the input, must be greater than zero" << endl;
    cin >> input;
  }
  else
  {
    int i = 0;
    while(input--)
    {
      DataType temp((int)i, (double)i * 2.0);
      assignList.push(temp);
      ++i;
    }
  }
  cout << "New list value is: " << assignList << endl;
*/

  cout << endl << "Testing the NodeStack\'s pop()" << endl;
  assignList.pop();
  cout << "New List value is: " << assignList << endl;

  cout << endl << "Testing the NodeStack\'s size()" << endl;
  cout << "Size of the list is currently:" <<  assignList.size() << endl;

  cout << endl << "Testing the NodeStack\'s empty()" << endl;
  cout << "Uncomment the code in the proj10.cpp file to test un/initialized" << endl;
  /*
    comment out general object and sub the Parameterized object to test empty()
  */
  NodeStack tempList;
  //NodeStack tempList(1, copyData);
  if(tempList.empty())
    cout << "List is empty!" << endl;
  else
    cout << "Something in the list" << endl;

  cout << endl << "Testing the NodeStack\'s full()" << endl;
  assignList.full();
  cout << "Full function is functioning...get it?" << endl;

  cout << endl << "Testing the NodeStack\'s clear()" << endl;
  tempList.clear();
  otherList.clear();
  cout << "Templist after clear: " << tempList << endl;
  cout << "otherList after clear: " << otherList << endl;

cout << "------------------------------------------------------" << endl;

   cout << endl << "Testing the ArrayStack" << endl;

   cout << endl << "Testing the ArrayStack\'s Default-ctor" << endl;
   ArrayStack emptyArray;
   cout << "Value of emptyStack:" << endl;
   cout << emptyArray << endl;
   if(emptyArray.empty())
   {
     cout << "The ArrayStack is empty and cannot display an empty list." << endl;
   }
   else
    cout << emptyArray.top() << endl;

   cout << endl << "Testing the ArrayStack\'s P-ctor" << endl;
   ArrayStack paramArray(10, copyData);
   cout << "Value of paramArray:" << endl;
   cout << paramArray << endl;

   cout << endl << "Testing the ArrayStack\'s C-ctor" << endl;
   ArrayStack copyArray(paramArray);
   cout << "Value of copyArray:" << endl;
   cout << copyArray << endl;

   cout << endl << "Testing the ArrayStack\'s Assignment operator" << endl;
   //set const to test for the const top() method
   const ArrayStack assignArray = paramArray;
   cout << "Value of assignArray:" << endl;
   cout << assignArray << endl;

   DataType retData;
   cout << endl << "Testing the ArrayStack\'s non-const top()" << endl;
   if(paramArray.empty())
   {
     cout << "The ArrayStack is empty and cannot display an empty list." << endl;
   }
   else
   {
     retData = paramArray.top();
     cout << "Value of top data:" << endl;
     cout << retData << endl;
   }

   cout << endl << "Testing the ArrayStack\'s const top()" << endl;
   if(assignArray.empty())
   {
     cout << "The ArrayStack is empty and cannot display an empty list." << endl;
   }
   else
   {
     cout << "Value of top data:" << endl;
     const DataType constData = assignArray.top();
     cout << constData << endl;
   }

   cout << endl << "Testing the ArrayStack\'s push()" << endl;
   cout << endl << "Enter number of items you would like to add to ArrayStack" << endl;

   size_t insert;
   cin >> insert;
   size_t i = 0;
   while(i < insert)
   {
     DataType temp((int)i, (double)i * 2.0);
     paramArray.push(temp);
     ++i;
   }
   cout << "New List after push is:" << endl;
   cout << paramArray << endl;

   if(paramArray.empty())
   {
     cout << "The ArrayStack is empty and cannot display an empty list." << endl;
   }
   else
   {
     cout << endl << "Top element is: " << endl;
     cout << paramArray.top() << endl;
   }

/*
    //uncomment to test functionality on full Array
    //THIS WILL ALWAYS AUTOFILL

   cout << endl << "Testing the ArrayStack\'s push() when full" << endl;
   size_t j = 1;
   while(j < MAX_STACKSIZE)
   {
     DataType temp((int)j, (double)j * 2.0);
     paramArray.push(temp);
     ++j;
   }
   cout << "New List after push is:" << endl;
   cout << paramArray << endl;
*/


   cout << endl << "Testing the ArrayStack\'s pop()" << endl;
   paramArray.pop();
   cout << "New List after pop()" << endl;
   cout << paramArray << endl;

   cout << endl << "Testing the ArrayStack\'s size()" << endl;
   cout << "The list's size is: " << paramArray.size();
   cout << endl << "Back element is: " << endl;
   if(paramArray.empty())
   {
     cout << "The ArrayStack is empty and cannot display an empty list." << endl;
   }
   else
    cout << paramArray.top() << endl;

//uncommnt to see complete removal of list
/*
   cout << endl << "Testing the ArrayStack\'s pop() until empty" << endl;
   int k = 0;
   while(!paramArray.empty())
   {
     paramArray.pop();
     cout << endl << "List value after pop() " << paramArray << endl;
     ++k;
   }
   cout << "Pop called " << k << " times";
   cout << endl << "New List after pop is: " << endl;
   cout << paramArray << endl;

  cout << endl << "-----------------------------------------" << endl;
  cout << "Done!" << endl;
*/
  return 0;
}

//done with NodeStack!
//DONE WITH ARRAYSTACK!
//destructor is tested on exit. Displays total deleted nodes for each list
//remember called in reverse order
