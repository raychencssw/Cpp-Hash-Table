// Name:Wei-Chieh, Chen
// USC NetID:weichieh
// CSCI 455 PA5
// Fall 2022


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to *not* put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string
//
// PRE: all the input are case sensitive.

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <string>
  

struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

 /**
  *  insert a Node to the "front" of the linked list, redirect the pointer list when necessarry.
  *  if the insertion is successful, return true; otherwise, return false.
  * 
  *  @ list the linked list in the current bucket.
  *  @ param key the key value of node being inserted.
  *  @ param val the value correponds to the key being inserted.
  */

bool insertList(ListType &list, const std::string &key, const int val);

 /**
  *  remove the Node that its key matches target, reclaims memory of the Node being removed.
  *  if the removal is successful, return true; otherwise, return false.
  *
  *  @ list the linked list in the current bucket.
  *  @ param target the key value of node being removed.
  */
  
bool removeList(ListType &list, const std::string &target);

 /**
  *  return a pointer point to the value of the node that matches the target given, or NULL
  *  if not found, can also update the value with this pointer.
  *
  *  @ list the linked list in the current bucket.
  *  @ param target the key value of node under lookup.
  */

int * lookupValueList(ListType &list, const std::string &target);

 /**
  *  print all entries in the linked list with format: "mark 1".
  *
  *  @ list the linked list in the current bucket.
  */ 
  
void printList(const ListType &list);

 /**
  *  Return the length of the linked list. It is called whenever a removal
  *  of one element from the linked list(called in Table::lookup) to check 
  *  whether the linked list become empty or not. The other situation is 
  *  calling hashStats(function of Table) to check the longest chain in the hashTable.
  *
  *  @ list the linked list in the current bucket.
  *  @ return length of current linked list.
  */ 

int lengthList(const ListType &list);


// keep the following line at the end of the file
#endif
