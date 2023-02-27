// Name:Wei-Chieh, Chen
// USC NetID:weichieh
// CSCI 455 PA5
// Fall 2022

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 * PRE: to see the command format, type "help" for command information first.
 *      the input commands are case sensitive.
 *      Cannot call grades with size of hashTable less than or eaual to 0.
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>


using namespace std;

//see implementation below
void printComSum();

//see implementation below
void grading(istream &in, const string &command, Table * &grades);

//see implementation below
void doInsert(string &key, string &value, Table* &grades);

//see implementation below
void doChange(string &key, string &newValue, Table * &grades);

//see implementation below
void doLookup(const string &key, Table* &grades);

//see implementation below
void doRemove(string &key, Table * &grades);


int main(int argc, char * argv[]) {


   Table * grades;  // Table is dynamically allocated below, so we can call
                     // different constructors depending on input from the user.
   
   // optionally gets the hash table size from the command line
   if (argc > 1) {
      int hashSize = atoi(argv[1]);  // atoi converts c-string to int
      
      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }

      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }


   grades->hashStats(cout);

   // add more code here
   // Reminder: use -> when calling Table methods, since grades is type Table*
   
   while(cin){
      
      //read in first client input as command, if the command is "quit", exit the program.
      cout << "cmd> ";  
      
      string command;
      cin >> command;
      
      if(command == "quit"){
         return 1;
      }
      
      //if the command is other than "quit", call grading for following action.
      grading(cin, command, grades);
   
   }
   return 0;
}

//print out information needed(whenever user type "help" or incorrect command)
              
void printComSum(){
   cout << "Summary of valid command: " << endl;
   cout << "insert name score" << endl;
   cout << "    Insert this name and score in the grade table." << endl;
   cout << "change name newscore" << endl;
   cout << "    Change the score for name." << endl;
   cout << "lookup name" << endl;
   cout << "    Lookup the name, and print out his or her score." << endl;
   cout << "remove name" << endl;
   cout << "    Remove this student." << endl;
   cout << "print" << endl;
   cout << "    Prints out all names and scores in the table." << endl;
   cout << "size" << endl;
   cout << "    Prints out the number of entries in the table." << endl;
   cout << "stats" << endl;
   cout << "    Prints out statistics about the hash table at this point." << endl;
   cout << "help" << endl;
   cout << "    Prints out a brief command summary." << endl;
   cout << "quit" << endl;
   cout << "    Exits the program." << endl;
}

 /**
  *  A helper function to accept command from cin, the following action depends on the command.
  *  The cin is passed in as well, since what type, length of input depends on what command is.
  *  Also passed the ponter to the Table in to allow member function on it.
  * 
  *  @ param in input stream contains actions with corresponding commands.
  *  @ param command user input commands.
  *  @ param grades grades table that holds student and corresponding score information.
  *
  */

void grading(istream &in, const string &command, Table * &grades){
      
      string key;
      string value;
      string newValue;
      
      //keep read in 2nd & 3rd client input as key and value of insertion.
      if(command == "insert"){
         in >> key;
         in >> value;
         doInsert(key, value, grades);
      }
      
      //keep read in 2nd & 3rd client input as key and value of update.
      else if(command == "change"){
         in >> key;
         in >> newValue;
         doChange(key, newValue, grades);
      }
      
      //keep read in 2nd client input as key of lookup.
      else if(command == "lookup"){
         in >> key;
         doLookup(key, grades);          
      }
      
      //keep read in 2nd client input as key of removal.
      else if(command == "remove"){
         in >> key;
         doRemove(key, grades);
      }
   
      else if(command == "print"){
         grades->printAll();
      }
      
      else if(command == "size"){
         cout << grades->numEntries() << endl;
      }
      
      else if(command == "stats"){
         grades->hashStats(cout);
      }      
      
      else if(command == "help"){
         printComSum();
      }
      
      else{
         cout << "ERROR: invalid command" << endl;
         printComSum();
      }
}
 /**
  *  A single insert action to the table. If the student is already present, do nothing and print out error message.
  *
  *  @ param key student name for the insertion.
  *  @ param value student's score for the insertion.
  *  @ param grades grades table that holds student and corresponding score information.
  */

void doInsert(string &key, string &value, Table* &grades){
   
   bool result = grades->insert(key,stoi(value));
   if (result == false){
      cout << "This name was already present." << endl;
   }
}

 /**
  *  A single change action to the table. If the student is not present, do nothing and print out error message.
  *
  *  @ param key student name for the update.
  *  @ param value student's score for the update.
  *  @ param grades grades table that holds student and corresponding score information.
  */

void doChange(string &key, string &newValue, Table * &grades){

   int* value = grades->lookup(key);
   if(value != NULL){
      *value = stoi(newValue);
   }
   else{
      cout << "The student is not present." << endl;
   } 
}

 /**
  *  A single lookup action to the table. If the student is not present, do nothing and print out error message.
  *
  *  @ param key student name for the lookup.
  *  @ param grades grades table that holds student and corresponding score information.
  */

void doLookup(const string &key, Table* &grades){
   
   int* value = grades->lookup(key);
   if(value != NULL){
      cout << "" << *value << endl;
   }
   else{
      cout << "The student is not present." << endl;
   } 
}
 /**
  *  A single remove action to the table. If the student is not present, do nothing and print out error message.
  *
  *  @ param key student name for the remove.
  *  @ param grades grades table that holds student and corresponding score information.
  */

void doRemove(string &key, Table* &grades){

   bool result = grades->remove(key);
   if(result == false){
      cout << "The student is not present." << endl;
   }
}