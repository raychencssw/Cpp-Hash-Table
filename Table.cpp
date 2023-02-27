// Name:Wei-Chieh, Chen
// USC NetID:weichieh
// CSCI 455 PA5
// Fall 2022

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************

//This constructor takes fixed hashSize which is static constant HASH_SIZE.
//The hashTable is allocated on the stack and initialized to NULL.
//Number of entries and number of non-empty bucket are also initialized to zero.

Table::Table() {
   occupiedEntry = 0;
   numEntry = 0;
   hashSize = HASH_SIZE;
   //a pointer point to the first element of an int type array with HASH_SIZE size, all element are default to NULL.
   //NOTE: Even though the size of the array, hashTable, is fixed with HASH_SIZE, the linked lists resides in every 
   //bucket are still need to be dynamically allocated(the length of linked list depend on how many element we insert)
   hashTable = new Node*[hashSize]();
   initNull();
   
}


//This constructor takes customized hashSize from client.
//The hashTable is dynamic allocated and initialized to NULL.
//Number of entries and number of non-empty bucket are also initialized to zero.

Table::Table(unsigned int hSize) {
   occupiedEntry = 0;
   numEntry = 0;
   hashSize = hSize;
   //a pointer point to the first element of an int type array with customized hSize size, all element are default to NULL.
   hashTable = new Node*[hashSize]();
   initNull();
}

//This function start from computing hashCode, get into the bucket where the key belongs to,
//then check whether the pointer dwelling in that bucket is NULL or not. If it is NULL, return
//NULL directly; otherwise, check if the key given resides in that linked list by lookupValueList
//, function of listFuncs.cpp, and the return value will either be NULL or int.


int * Table::lookup(const string &key) {
   
   int bucket = hashCode(key);

   //if the bucket is empty, return NULL immediately.
   Node* list = hashTable[bucket];
   if(list == NULL){
      return NULL;
   }
   
   int *value;
   value = lookupValueList(list, key); 

   //if there exist LL in that bucket, lookup that LL.
   //returns either NULL or int depends on whether the key already existed in the linkedlist or not.
   return value;
}

//This function start from computing hashCode, get into the bucket where the key belongs to,
//then check whether the pointer dwelling in that bucket is NULL or not. If that bucket is 
//empty(NULL), return false immediately. Otherwuse, use a boolean variable "result" to store
//the return value from removeList(function of listFuncs.cpp). removeList returns true if the
//removal is success, so the list is modified, then put that list back to that bucket. Further
//check whether numBucket(length of the linked list of that bucket) is 0 or not. If it is 0, 
//decrement both the occupiedEntery(number of non-empty bucket) and numEntry(number of entries). 
//Otherwise decrement numEntry only. Finnally return true, or false if the removal is unsuccessful.

bool Table::remove(const string &key) {
   
   int bucket = hashCode(key);
   Node* list = hashTable[bucket];
   if(list == NULL){
      return false;
   }
   bool result = removeList(list, key);
   
   //if the removal is successful, check if the size of that bucket becomes 0,
   //if so, decrement the occupiedEntry. Decrement numEntry and put the modified
   //linked list back to that bucket. Finally reutrn true.
   if(result == true){
      int numBucket = lengthList(list);
      if(numBucket == 0){
         occupiedEntry--;
      }
      numEntry--;
      hashTable[bucket] = list;
      return true;
   }
   
   //if the removal is unsuccessful, return false.
   else{
      return false;
   }
}


//This function start from computing hashCode, get into the bucket where the key belongs to,
//then check whether the pointer dwelling in that bucket is NULL or not. If the linked list
//in that bucket is NULL, then imcrement the occupiedEntry(number of non-empty bucket). Then use 
//a boolean variable "result" to store the return value from insertList(function of listFuncs.cpp).
//insertList returns non-NULL value if the insertion is successful, so the list is modied and then
//is put back to that bucket. Meantime, increment numEntry by one(number of entries). Finally return
//true. Otherwise, return false if same key is alreadt existed in that linkedlist. 

bool Table::insert(const string &key, int value) {
   int bucket = hashCode(key);
   Node* list = hashTable[bucket];
   
   //if the bucket being inserted is empty, increment occupiedEntry.
   if(list == NULL){
      occupiedEntry++;
   }   
   
   bool result = insertList(list, key, value);
   if(result == 1){
      hashTable[bucket] = list;
      numEntry ++;
   }
   
   return result; 
}

//get the number of entries by accessing to the instance variable numEntry.
int Table::numEntries() const {
   return numEntry;     
}

//iterate the whole hashTable and call printList, function of listFuncs.cpp, to
//print out each linkedlist. The order of printing in the view of hashTable is
//fixed because hashCode function is given by starting code. However, for elements
//in the linked list(has same value from hashCode) that the length is bigger than one, 
//the order will depend on how we insert the element into the linkedlist. In this 
//implementation, the element is always added to the front, so it is a LIFO(stack) 
//style implementation.

void Table::printAll() const {
   for(int i = 0; i < hashSize; i++){    
      printList(hashTable[i]);    
   }
}

//pass the diagnose information to the out stream.
void Table::hashStats(ostream &out) const {
   out << "number of buckets: " << hashSize << endl;
   out << "number of entries: " << numEntries() << endl;
   out << "number of non-empty buckets: " << occupiedEntry << endl;
   out << "longest chain: " << longChain() << endl;
}


// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const {

   // Note: calls a std library hash function for string (it uses the good hash
   //   algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashSize;

}


// add definitions for your private methods here


//initialize all the element of the hashTable to NULL.
void Table::initNull(){
   for (int i = 0; i < hashSize; i++){
      hashTable[i] = NULL;
   }
}


//iterate the whole hashTable to find out longest chain whenever hashStats is called.
int Table::longChain() const{
   int longestChain = 0;
   for (int i = 0; i < hashSize; i++){
      Node* list = hashTable[i];
      int length = lengthList(list);
      if (length > longestChain){
         longestChain = length;
      }
   } 
   return longestChain;
}





