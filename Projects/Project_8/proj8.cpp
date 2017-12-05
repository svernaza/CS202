/*
  Samuel Vernaza
  CS202
  Project_8
*/

#include <iostream>

#include "ArrayList.h"
#include "NodeList.h"

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
  copyData.SetIntVal(6);
  cout << "copyData.SetIntVal() set!" << endl;
  cout << "copyData int value is: " << copyData.GetIntVal() << endl;

  //Testing DataType GetDoubleVal()
  cout << endl << "Testing DataType GetDoubleVal()" << endl;
  cout << "copyData.GetDoubleVal(): " << copyData.GetDoubleVal() << endl;

  cout << endl << "Testing DataType SetDoubleVal()" << endl;
  cout << "copyData.SetDoubleVal() set!" << endl;
  copyData.SetDoubleVal(12.0);
  cout << "copyData double value is: " << copyData.GetDoubleVal() << endl;

  cout << "--------------------------------------------------------" << endl;

  //Test node constructor
  cout << endl << "Testing the Node Class and Creation of Nodes" << endl;

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

  cout << endl << "Now testing the NodeList class!" << endl;

  cout << endl << "Testing the NodeList default C-tor" << endl;
  NodeList newList;
  cout << "newList value: " << newList << endl;

  //need to fix this!
  cout << endl << "Testing NodeList Parameterized C-tor " << endl;
  NodeList otherList(20, copyData);
  cout << "NodeList Parameterized C-tor works " << endl;
  cout << "otherList value: " << otherList << endl;

  cout << endl << "Testing NodeList Copy C-tor " << endl;
  NodeList copiedList(otherList);
  cout << "NodeList Copy C-tor works " << endl;
  cout << "otherList value: " << copiedList << endl;

  cout << endl << "Testing NodeList Assignment operator" << endl;
  NodeList assignList(2, copyData);
  assignList = otherList;
  cout << "Nodelist Assignment works!" << endl;
  cout << "assignList\'s value is: " << assignList << endl;

  cout << endl << "Testing NodeList\'s First()" << endl;
  Node * first = assignList.First();
  cout << "First Node\'s address is: " << assignList.First() << endl;
  cout << "First Node\'s data is: " << first->GetData() << endl;
  cout << "The following SetData function is just for fun" << endl;
  cout << "Assignning new value to First Node's Data" << endl;
  first->SetData(2, 5.5);
  cout << "First Node\'s new data values are: " << first->GetData() << endl;
  cout << "New List: " << assignList << endl;

  cout << endl << "Testing NodeList\'s Last()" << endl;
  Node * last = assignList.Last();
  cout << "Last Node\'s address is: " << assignList.Last() << endl;
  cout << "Last's Node\'s data is: " << last->GetData() << endl;
  cout << "Setting last Node\'s data to different value: " << endl;
  last->SetData(45, 10.0);
  cout << "New List: " << assignList << endl;

  //change value of to find in order to verify match/no-match condition
  DataType toFind(45, 10.0);
  Node * prev = NULL;
  cout << endl << "Testing the NodeList\'s Find()" << endl;
  Node * found = assignList.Find(toFind, prev);
  if(found)
  {
    cout << endl << "Found a match! " << endl;
    cout << "Address of found: " << found << endl;
    cout << "Found\'s Data: " << found->GetData() << endl;
  }
  else
   cout << endl << "No match found! " << endl;

   cout << endl << "Testing the NodeList\'s InsertAfter()" << endl;
   DataType useMe(30, 15.0);
   Node * after = assignList.InsertAfter(toFind, useMe);
   cout << "Insertion sucessful!" << endl;
   cout << "Address of insertion: " << after << endl;
   cout << "Value of insertion: " << after->GetData() << endl; //could use dereference if desired
   cout << "New list: " << assignList << endl;

   cout << endl << "Testing the NodeList\'s InsertBefore()" << endl;
   DataType useMe2(25, 11.0);
   Node * before = assignList.InsertBefore(toFind, useMe2);
   cout << "Insertion sucessful!" << endl;
   cout << "Address of insertion: " << before << endl;
   cout << "Value of insertion: " << before->GetData() << endl; //could use dereference if desired
   cout << "New list: " << assignList << endl;

   cout << endl << "Testing NodeList\'s Erase()" << endl;
   Node * next = assignList.Erase(useMe);
   cout << "Erase successful" << endl;
   cout << "Address of the next node after erased Node " << next << endl;
   //cout << "Value of the next node after erased Node" << *next << endl;
   cout << "New List" << assignList << endl;

   cout << endl << "Testing NodeList\'s operator[]" << endl;
   cout << "Value at the index: " << endl << assignList[20] << endl;
   cout << "Operator[] works!" << endl;

   cout << endl << "Testing the NodeList\'s size()" << endl;
   int len = assignList.size();
   cout << "The Length of assignList is: " << len << endl;

   cout << endl << "Tesing the NodeList\'s empty()" << endl;
   cout << "Creating an empty list to get a true value " << endl;
   //"Remember to comment and uncomment the default constructor"
   NodeList im;
   if(im.empty())
    cout << "Empty List Detected " << endl;
   else
    cout << "List detected" << endl;

  cout << endl << "Testing Clear()" << endl;
  NodeList tempList(assignList);
  cout << "Worked" << endl;
  //tempList = assignList;
  if(tempList.size() > 0)
  {
    tempList.clear();
    if(tempList.empty())
      cout << "Worked! List empty." << endl;
    else
      cout << "Problem detected. The list remains, tread cautiously" << endl;
  }
  else
    cout << "TempList wasn't created" << endl;


  cout << "--------------------------------------------------------" << endl;
  cout << endl << "Testing the ArrayList Class" << endl;
  cout << "Will eventually seg fault if you assign a value of zero" << endl;


  cout << endl << "Testing the ArrayList D-tor" << endl;
  ArrayList defList;
  cout << "Default constructor works!" << endl;
  cout << "Can't output because it would require dereferencing a NULL" << endl;

  cout << endl << "Testing the ArrayList Parameterized c-tor" << endl;
  ArrayList paramList(5, useMe*2);
  cout << "Parameterized constructor works!" << endl;
  cout << "Value of D-tor" << paramList << endl;

  cout << endl << "Testing the ArrayList Copy c-tor" << endl;
  ArrayList copyList(paramList);
  cout << "Copy C-tor Works!" << endl;
  cout << "Value of copyList" << copyList << endl;

  cout << endl << "Testing the ArrayList Assignment" << endl;
  copyList = paramList;
  cout << "Assignment Works!" << endl;
  cout << "Value of new copyList" << copyList << endl;

  cout << endl << "Testing the ArrayList First()" << endl;
  ArrayList anotherList(paramList);
  cout << "Value of anotherList" << anotherList << endl;
  cout << "First value is: " << *anotherList.First() << endl;

  cout << endl << "Testing the ArrayList Last()" << endl;
  cout << "Value of anotherList is still same, proof" << anotherList << endl;
  cout << "Last value is: " << *anotherList.Last() << endl;

  cout << endl << "Testing the ArrayList Find()" << endl;
  DataType dumbVal(960, 480);
  DataType * previous = NULL;
  cout << "Value found is: " << *anotherList.Find(dumbVal, previous) << endl;
  cout << "Value of previous is: " << endl;
  if(!previous)
    cout << "NULL" << endl;
  else
    cout << *previous << endl;

  cout << endl << "Testing the ArrayList Size()" << endl;
  cout << "anotherList size is: " << anotherList.size() << endl;

  cout << endl << "Testing the ArrayList insertBefore()" << endl;
  DataType FirstTest(0, 0.0);
  anotherList.InsertBefore(FirstTest, dumbVal);
  cout << "anotherList is now: " << anotherList << endl; 
  cout << "Worked" << endl;
  return 0;
}

//done with NodeList!
//destructor is tested on exit. Displays total delted nodes for each list
//remember called in reverse order
