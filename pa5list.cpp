// Name:Wei-Chieh, Chen
// USC NetID:weichieh
// CSCI 455 PA5
// Fall 2022

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {
   
   bool result; //record the results of linked list boolean action(remove & update)
   int* value; //record the Node found by loopup fuction

   Node * list = NULL;
   cout << "Print empty list: " << ends;
   printList(list);
   cout << endl;
   
   cout << "Adding 5 Nodes...." << endl;
   insertList(list, "Mark", 1);
   insertList(list, "Lucy", 2);
   insertList(list, "Tom", 3);
   insertList(list, "Kathy", 4);
   insertList(list, "King", 5);
   
   cout << "Print whole list: " << endl;
   printList(list);   
   cout << endl;
   
   cout << "Lookup Lucy...." << endl;
   value = lookupValueList(list, "Lucy");
   cout << "Found result: key lucy, value " << *value << endl;
   
   
   
   
   cout << "Remove Tom(in the middle)..." << endl;
   result = removeList(list, "Tom");
   cout << "Removal of Tom is: " << result << endl;
   printList(list);
   cout << endl;
   
   cout << "Remove King(in the beginning)...." << endl;
   result = removeList(list, "King");
   cout << "Removal of King is: " << result << endl;
   printList(list);
   cout << endl;
   
   cout << "Remove Mark(in the end)...." << endl;
   result = removeList(list, "Mark");
   cout << "Removal of Mark is: " << result << endl;
   printList(list);
   cout << endl;
   
   cout << "Remove Big(does not exist)...." << endl;
   result = removeList(list, "Big");
   cout << "Removal of Big is: " << result << endl;
   printList(list);
   cout << endl;
   
   cout << "Remove Kathy(2nd to the last)...." << endl;
   result = removeList(list, "Kathy");
   cout << "Removal of Kathy is: " << result << endl;
   printList(list);
   cout << endl;
   
   cout << "Remove Lucy(last)...." << endl;
   result = removeList(list, "Lucy");
   cout << "Removal of Lucy is: " << result << endl;
   printList(list);
   cout << endl;
   
   
   return 0;
}
