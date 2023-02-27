// Name:Wei-Chieh, Chen
// USC NetID:weichieh
// CSCI 455 PA5
// Fall 2022


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}




//*************************************************************************
// put the function definitions for your list functions below

//This insertList use a add-to-the-front implementation: 
//given a linked list(pointer), start checking whether the value it point to is NULL or not. If it is NULL,   
//then create a new Node, and make that pointer re-point to the new Node. Otherwise, further check whether 
//the already existed linked list include the Nodes with given key or not. If already exists, return false
//immediately, otherwise, create a new Node, then add the new Node to the front of the LL.
//Meantime, returns true if the insertion is successful; otherwise, returns false.

bool insertList(ListType &list, const string &key, int val){
   
   //if the list input is NULL, create a new node and make list point to the new node.
   if(list == NULL){
      Node* newNode = new Node(key, val);
      list = newNode;
      return true;
   }
   
   //if the list is not NULL, search the LL first, if the key already exists, return false directly.
   int* found = lookupValueList(list, key);
   if (found != NULL){
      return false;
   }
   
   //if the key does not exist, create a new node and add that new node to the front of the LL.
   Node* newNode = new Node(key, val, list);
   list = newNode;
   return true;
}

//Use two pointers "traverseP" and "prevP" to iterate the whole linked list if it existed.
//Dereference the travereP to check whether the key dwelling in that node matches target
//or not. If matching, use the 3rd pointer "rest" to store the linked list but not any node
//preceding traverseP and traverseP itself. Further check if the node being removed is 1st
//node.If it is, make list point to the rest directly. If not, make prevP(=previous node)
//point to the rest. Either situation, delete the traversP to reclaim the memory used by the
//node being removed. Finally returns true. Returns false if the target doesn't exist in the
//whole linked list.

bool removeList(ListType &list, const string &target){
   
   Node* traverseP = list;
   Node* prevP = list;
   while(traverseP != NULL){
      string key = traverseP->key;
      if(key == target){
         Node* rest = traverseP->next;
         //Make list point to the rest if the first node is deleted.
         if(list==traverseP){
            list = rest;
         }
         //Make prevP point to the rest for situation other than deleting first node.
         else{ prevP->next = rest; }
         //After finishing relinking prevP and rest, recliam memory of the Node being removed.
         delete traverseP;
         return true;
      }
      prevP = traverseP;
      traverseP = traverseP->next;
   }
   return false;
}


//Use a pointer "traversP" to traverse the linked list given. Returns its value if 
//target exist in the node being examined. Returns NULL if the target is not 
//found after the traversal.

int * lookupValueList(ListType &list, const string &target){
   
   Node* traverseP = list;
   while(traverseP != NULL){
      string key = traverseP->key;
      if(key == target){
         return &(traverseP->value);
      }
      traverseP = traverseP->next;
   }
   return NULL;
}


//Print out the key and value of each node in the linked list given.

void printList(const ListType &list){
   Node* traverseP = list;
   while(traverseP != NULL){
      cout << traverseP->key << " " << traverseP->value << endl;
      traverseP = traverseP->next;
   }
}

//Returns the length of the linked list given.

int lengthList(const ListType &list){
   int length = 0;
   Node* traverseP = list;
   while(traverseP != NULL){
      length++;
      traverseP = traverseP->next;
   }
   return length;
}