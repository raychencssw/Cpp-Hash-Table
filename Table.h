// Name:Wei-Chieh, Chen
// USC NetID:weichieh
// CSCI 455 PA5
// Fall 2022


#ifndef TABLE_H
#define TABLE_H

// Table class
//    stores a collection of (string, int) entries
//    such that each key (the string) is unique
//    with efficient (O(1)) lookup, insert, and removal of entries

// Note: it's good practice to *not* put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string


#include <iostream>
#include <string>

// the following line of code is a forward declaration of Node struct.
// allows us to use Node* (or ListType because of typedef) in private 
// section of Table below. (Complete Node definition is in listFuncs.h)
struct Node;

typedef Node * ListType;

class Table {
 public:
   
  /**
   *   Representation invariant:
   *
   *   <put rep. invar. comment here>
   *   There is no duplicate key in the Table.
   *   The time complexity for insert/remove/lookup are O(1) since the implementation
   *   of it is an random access array. Even though there exist some buckets have linked
   *   list of length longer than 1, these three actions are still efficient due to the
   *   chain are not long(mostly <= 4 for a txt file with thousands of word).
   *   numEntry >= 0.
   *   occupiedEntry >= 0.
   *   The input key is case sensitive.
   *   
   *   PRE:customized size of hash Table CANNOT be negative or zero. It must be > 0.
   */

   static const unsigned int HASH_SIZE = 9973;  // a prime number

   // create an empty table, i.e., one where numEntries() is 0
   // (Underlying hash table is HASH_SIZE.)
   Table();

   // create an empty table, i.e., one where numEntries() is 0
   // such that the underlying hash table is hSize
   Table(unsigned int hSize);

   // insert a new pair into the table
   // return false iff this key was already present 
   //         (and no change made to table)
   bool insert(const std::string &key, int value);

   // returns the address of the value that goes with this key
   // or NULL if key is not present.
   //   Thus, this method can be used to either lookup the value or
   //   update the value that goes with this key.
   int *lookup(const std::string &key);

   // remove a pair given its key
   // return false iff key wasn't present
   //         (and no change made to table)
   bool remove(const std::string &key);

   // print out all the entries in the table, one per line.
   // Sample output:
   //   zhou 283
   //   sam 84
   //   babs 99
   void printAll() const;

   int numEntries() const;      // number of entries in the table

   // hashStats: for diagnostic purposes only
   // prints out info to let us know if we're getting a good distribution
   // of values in the hash table.
   // Sample output from this function
   //   number of buckets: 997
   //   number of entries: 10
   //   number of non-empty buckets: 9
   //   longest chain: 2
   void hashStats(std::ostream &out) const;

 private:

   //***********do not change the following two lines of code*************
   // making these private disallows copying of tables  
   // (do not implement these two methods)
   Table &operator =(const Table &);
   Table(const Table &);

   // (we defined this for you: see Table.cpp for details)
   unsigned int hashCode(const std::string &word) const;

   // add private data and private method headers here
   
   // size of the hash table (NOTE: YOU MUST USE THIS INSTANCE VARIABLE BECAUSE THE
   // HASHCODE METHOD ABOVE USES IT)
   unsigned int hashSize;
   
   //a pointer point to the first bucket of the hashTable. Each bucket is a pointer as well.
   Node* * hashTable;
   
   //Keep track of the number of entries. Can only be accessed by accessor.
   int numEntry;
   
   //keep track of the number of non-empty entries.
   int occupiedEntry;

   
   //initialize all the elements of hashTable to NULL.
   void initNull();
   
   //An accessor return the length of the longest chain in the hashTable.
   int longChain() const;


};

#endif

