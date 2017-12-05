/*
  Samuel Vernaza
  CS202
  Project_8
*/

#include <iostream>

#include "ArrayQueue.h"
#include "NodeQueue.h"

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

  cout << endl << "Now testing the NodeQueue class!" << endl;

  cout << endl << "Testing the NodeQueue default C-tor" << endl;
  NodeQueue newList;
  cout << "newList value: " << newList << endl;

  //setting other list to zero will cause seg faults
  cout << endl << "Testing NodeQueue Parameterized C-tor " << endl;
  NodeQueue otherList(10, copyData);
  cout << "NodeQueue Parameterized C-tor works " << endl;
  cout << "otherList value: " << otherList << endl;

  cout << endl << "Testing NodeQueue Copy C-tor " << endl;
  NodeQueue copiedList(otherList);
  cout << "NodeQueue Copy C-tor works " << endl;
  cout << "otherList value: " << copiedList << endl;

  cout << endl << "Testing NodeQueue Assignment operator" << endl;
  NodeQueue assignList(10, copyData);
  assignList = otherList;
  cout << "NodeQueue Assignment works!" << endl;
  cout << "assignList\'s value is: " << assignList << endl;

  cout << endl << "Testing NodeQueue\'s First()" << endl;
  DataType front = assignList.front();
  cout << "First Node\'s data is: " << front << endl;

  cout << endl << "Testing NodeQueue\'s Last()" << endl;
  DataType last = assignList.back();
  //cout << "Last Node\'s address is: " << assignList.Last() << endl;
  cout << "Last's Node\'s data is: " << last << endl;

  //change value of to find in order to verify match/no-match condition
  DataType toFront(45, 10.0);
  cout << endl << "Testing the NodeQueue\'s push()" << endl;
  assignList.push(toFront);
  cout << "New List value is: " << assignList << endl;

  cout << endl << "Testing the NodeQueue\'s pop()" << endl;
  assignList.pop();
  cout << "New List value is: " << assignList << endl;

  cout << endl << "Testing the NodeQueue\'s size()" << endl;
  cout << "Size of the list is currently:" <<  assignList.size() << endl;

  cout << endl << "Testing the NodeQueue\'s empty()" << endl;
  cout << "Uncomment the code in the proj9.cpp file to test un/initialized" << endl;
  /*
    comment out general object and sub the Parameterized object to test empty()
  */
  NodeQueue tempList;
  //NodeQueue tempList(1, copyData);
  if(tempList.empty())
    cout << "List is empty!" << endl;
  else
    cout << "Something in the list" << endl;

  cout << endl << "Testing the NodeQueue\'s full()" << endl;
  assignList.full();
  cout << "Full function is functioning, get it..." << endl;

  cout << endl << "Testing the NodeQueue\'s clear()" << endl;
  tempList.clear();
  otherList.clear();
  cout << tempList << endl;
  cout << otherList << endl;

cout << "------------------------------------------------------" << endl;

   cout << endl << "Testing the ArrayQueue" << endl;

   cout << endl << "Testing the ArrayQueue\'s Default-ctor" << endl;
   ArrayQueue emptyArray;
   cout << "Value of emptyArray:" << endl;
   cout << emptyArray << endl;
   if(emptyArray.empty())
   {
     cout << "The ArrayQueue is empty and cannot display an empty list." << endl;
   }
   else
    cout << emptyArray.front() << endl;

   cout << endl << "Testing the ArrayQueue\'s P-ctor" << endl;
   ArrayQueue paramArray(10, copyData);
   cout << "Value of paramArray:" << endl;
   cout << paramArray << endl;

   cout << endl << "Testing the ArrayQueue\'s C-ctor" << endl;
   ArrayQueue copyArray(paramArray);
   cout << "Value of copyArray:" << endl;
   cout << copyArray << endl;

   cout << endl << "Testing the ArrayQueue\'s Assignment operator" << endl;
   //set const to test for the const front() method
   const ArrayQueue assignArray = paramArray;
   cout << "Value of assignArray:" << endl;
   cout << assignArray << endl;

   DataType retData;
   cout << endl << "Testing the ArrayQueue\'s non-const front()" << endl;
   if(paramArray.empty())
   {
     cout << "The ArrayQueue is empty and cannot display an empty list." << endl;
   }
   else
   {
     retData = paramArray.front();
     cout << "Value of front data:" << endl;
     cout << retData << endl;
   }

   cout << endl << "Testing the ArrayQueue\'s const front()" << endl;
   if(assignArray.empty())
   {
     cout << "The ArrayQueue is empty and cannot display an empty list." << endl;
   }
   else
   {
     cout << "Value of front data:" << endl;
     const DataType constData = assignArray.front();
     cout << constData << endl;
   }

   if(paramArray.empty())
   {
     cout << "The ArrayQueue is empty and cannot display an empty list." << endl;
   }
   else
   {
     cout << endl << "Testing the ArrayQueue\'s non-const back()" << endl;
     retData = paramArray.back();
     cout << "Value of back data:" << endl;
     cout << retData << endl;
   }

   if(assignArray.empty())
   {
     cout << "The ArrayQueue is empty and cannot display an empty list." << endl;
   }
   else
   {
     cout << endl << "Testing the ArrayQueue\'s const back()" << endl;
     const DataType conData = assignArray.back();
     cout << "Value of back data:" << endl;
     cout << conData << endl;
   }

   cout << endl << "Testing the ArrayQueue\'s push()" << endl;
   cout << endl << "Enter how many items you would like to add to list" << endl;
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
     cout << "The ArrayQueue is empty and cannot display an empty list." << endl;
   }
   else
   {
     cout << endl << "Back element is: " << endl;
     cout << paramArray.back() << endl;
   }

   /*

    //uncomment to test functionality on full Array

   cout << endl << "Testing the ArrayQueue\'s push() when full" << endl;
   size_t j = 1;
   while(j < ARRAY_MAX)
   {
     DataType temp((int)j, (double)j * 2.0);
     paramArray.push(temp);
     ++j;
   }
   cout << "New List after push is:" << endl;
   cout << paramArray << endl;
   */

   cout << endl << "Testing the ArrayQueue\'s pop()" << endl;
   paramArray.pop();
   cout << "New List after pop()" << endl;
   cout << paramArray << endl;

   cout << endl << "Testing the ArrayQueue\'s size()" << endl;
   cout << "The list's size is: " << paramArray.size();
   cout << endl << "Back element is: " << endl;
   if(paramArray.empty())
   {
     cout << "The ArrayQueue is empty and cannot display an empty list." << endl;
   }
   else
    cout << paramArray.back() << endl;

//uncommnt to see complete removal of list
/*
   cout << endl << "Testing the ArrayQueue\'s pop() until empty" << endl;
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
*/

  cout << endl << "-----------------------------------------" << endl;
  cout << "Done!" << endl;
  return 0;
}

//done with NodeQueue!
//destructor is tested on exit. Displays total delted nodes for each list
//remember called in reverse order
