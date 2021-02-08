#include <iostream>
#include "Classes_Hashing.h"
#include<bits/stdc++.h>
#include <sstream>
using namespace std;

HashMap::HashMap(int N)
{
    table = new list<long long int>[N]; // create the hash table that consists of linked lists
}

int HashMap::FoldingFunc(long long int key)
{
    long long int f1 = (key / 100000000); // first 3 bits , 8 bits deleted from right
    long long int f2 = (key /100000); // 5 bits deleted from right
    f2 = f2 % 1000 ; // second 3 bits
    long long int f3 = (key/100);  // 2 bits deleted from right
    f3 = f3 % 1000 ;// third 3 bits
    long long int f4 = (key%100); // last 2 bits
    long long int folded = f1+f2+f3+f4; // add them
    folded = folded %100; // last two digits
    return folded;
}

void HashMap::FoldingInsert(long long int key)
{
    int h = FoldingFunc(key); // h is the position of the element to be inserted
    table[h].push_back(key); // insert into the linked list
}

int HashMap::FoldingSearch(long long int key)
{
    int h = FoldingFunc(key); // h is the position of the element to be searched
    list <long long int> :: iterator i; // define i to search in the list
  for (i = table[h].begin();i != table[h].end(); i++) { // if list is not ended continue to search
    if (*i == key) // if found break the loop
      break;
    }
  if (i != table[h].end())
    return h; // return where it is  found
  else
    return -1; // not found
}

void HashMap::FoldingRemove(long long int key)
{
    int h = FoldingFunc(key); // h is the position of the element to be removed
    list <long long int> :: iterator i;
  for (i = table[h].begin();i != table[h].end(); i++) { // search the element if it is in the linked list
    if (*i == key) // if found
      break;
  }
  if (i != table[h].end()) // if loop is breaked but not ended
    table[h].erase(i); // erase
  else cout<<"T.C. ID Number is not in the table"<<endl; // not found, so not deleted
}


int HashMap::TruncationFunc(long long int key)
{
    return key % 100; // last two digits
}

void HashMap::TruncationInsert(long long int key)
{
    int h = TruncationFunc(key); // h is the position of the element to be inserted
    table[h].push_back(key); // insert into linked list
}

int HashMap::TruncationSearch(long long int key)
{// same with folding search just the calculation of the h is different
    int h = TruncationFunc(key); // h is calculated by using truncation function
    list <long long int> :: iterator i;
  for (i = table[h].begin();
           i != table[h].end(); i++) {
    if (*i == key)
      break;
    }
  if (i != table[h].end())
    return h;
  else
    return -1;
}

void HashMap::TruncationRemove(long long int key)
{// same with folding remove just the calculation of the h is different
    int h = TruncationFunc(key);
    list <long long int> :: iterator i;
  for (i = table[h].begin();
           i != table[h].end(); i++) {
    if (*i == key)
      break;
  }
  if (i != table[h].end())
    table[h].erase(i);
  else cout<<"T.C. ID Number is not in the table"<<endl;
}


int HashMap::MiddleSquaringFunc(long long int key)
{
    key = key % 10000000; // deleted left 4 bits
    key = (key / 10000); // deleted right 4 bits
    key = (key*key); // take square
    key = key %100; // last two digits
    return key;
}


void HashMap::MiddleSquaringInsert(long long int key)
 {// same with folding Insert just the calculation of the h is different
    int h = MiddleSquaringFunc(key);
    table[h].push_back(key);
}

int HashMap::MiddleSquaringSearch(long long int key)
 {// same with folding search just the calculation of the h is different
    int h = MiddleSquaringFunc(key);
    list <long long int> :: iterator i;
  for (i = table[h].begin();
           i != table[h].end(); i++) {
    if (*i == key)
      break;
    }
  if (i != table[h].end())
    return h;
  else
    return -1;
}

void HashMap::MiddleSquaringRemove(long long int key)
{// same with folding remove just the calculation of the h is different
    int h = MiddleSquaringFunc(key);
    list <long long int> :: iterator i;
  for (i = table[h].begin();
           i != table[h].end(); i++) {
    if (*i == key)
      break;
  }
  if (i != table[h].end())
    table[h].erase(i);
  else cout<<"T.C. ID Number is not in the table"<<endl;
}


void HashMap::PrintHashMap() {
// prints the items of the list one by one into a readable form
  for (int i = 0; i < N; i++) {
    cout << i;
    for (auto x : table[i])
      cout << " --> " << x;
    cout << endl;
  }
}


int main()
{

int menu_options=0;// menu options
int hash_func=0; // hash function select
long long int TC_number;
int Size=0; // hash table size will be decided by user

// to minimalize the errors initialize the table first
    cout<<"Hash Table has to be initialized before start"<<endl;
    cout<<"1. Initialize Hash Table"<<endl;
    cout<<"Enter the has table size N: "<<endl; // size
    cin>>Size; // write size of the table
    while (Size<1){
        cout<<"size can not be '0' or negative"<<endl;
        cin>>Size; // make sure user typed a valid size
    }
    HashMap MyHashMap(Size); // initialize the table
    MyHashMap.N=Size;
    cout<<"Choose hash function: "<<endl; // choose hash function
    cout<<"1. Folding"<<endl;
    cout<<"2. Middle Squaring"<<endl;
    cout<<"3. Truncation"<<endl;
    cin>>hash_func;
    while(hash_func>3 || hash_func<1){// make sure a valid option is chosen
                    cout<<"Invalid Option. It must be 3, 2 or 1."<<endl;
                    cout<<"Choose hash function:"<<endl;
                    cin>>hash_func;
                }
// INITIALIZATION IS DONE
while (1) { // Menu Loop
    cout<<endl;
    cout<<"You can navigate through the options represented below"<<endl;
    cout<<"2. Load T.C. ID Numbers from file"<<endl;
    cout<<"3. Add a new T.C. ID Number"<<endl;
    cout<<"4. Delete a T.C. ID Number"<<endl;
    cout<<"5. Search for a T.C. ID Number"<<endl;
    cout<<"6. Print out Hash Table"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>> menu_options;
    if(menu_options==2){ // load from file
        string s;
        string line; // lines will be considered as strings
        long long int temp;
        long long int TC_init[200];
        ifstream myfile ("hash_table_init200.txt"); //if file is changed dont forget to change TC_Init ARRAY SIZE
            if (myfile.is_open())
            {
                int i=0;
                while ( getline (myfile,line) )
                {
                    s = line;
                    stringstream convert(s); // convert the strings into long lonn intiger
                    convert >> temp; // put them into temp variable
                    TC_init[i]= temp; //this array will be used to construct the linked list
                    i++;
                }
            myfile.close();
            }
            else cout << "Unable to open file";

// Insert the items one by one into the correct places by using corresponding hash functions
            if(hash_func==1) // folding
                {
                    cout<<"200 T.C. ID number is initialized to system "<<endl;
                        for(long long int i=0;i<200;i++){
                            MyHashMap.FoldingInsert(TC_init[i]);
                        }
                }
            else if(hash_func==2) // middle square
                {
                    cout<<"200 T.C. ID number is initialized to system "<<endl;
                        for(long long int i=0;i<200;i++){
                            MyHashMap.MiddleSquaringInsert(TC_init[i]);
                        }
                }

            else if(hash_func==3) // truncation
                {
                    cout<<"200 T.C. ID number is initialized to system "<<endl;
                        for(long long int i=0;i<200;i++){
                            MyHashMap.TruncationInsert(TC_init[i]);
                        }
                }
        }

        else if(menu_options==3 && Size!=0){
            if(hash_func==1)//folding
            {
                cout<<"Enter the T.C. ID Number to be added: "<<endl;
                cin>>TC_number;
                while(TC_number>99999999999 || TC_number<10000000000){ // make sure TC is valid
                    cout<<"Invalid T.C. ID Number. The number has to be between 99 999 999 999 - 10 000 000 000"<<endl;
                    cout<<"Enter the T.C. ID Number to be added:"<<endl;
                    cin>>TC_number;
                }

                MyHashMap.FoldingInsert(TC_number); // insert
            }
            else if(hash_func==2)// middle square
            {
                cout<<"Enter the T.C. ID Number to be added: "<<endl;
                cin>>TC_number;
                while(TC_number>99999999999 || TC_number<10000000000){// make sure TC is valid
                    cout<<"Invalid T.C. ID Number. The number has to be between 99 999 999 999 - 10 000 000 000"<<endl;
                    cout<<"Enter the T.C. ID Number to be added:"<<endl;
                    cin>>TC_number;
                }
                MyHashMap.MiddleSquaringInsert(TC_number);
            }
            else if(hash_func==3) // truncation
            {
                cout<<"Enter the T.C. ID Number to be added: "<<endl;
                cin>>TC_number;
                while(TC_number>99999999999 || TC_number<10000000000){// make sure TC is valid
                    cout<<"Invalid T.C. ID Number. The number has to be between 99 999 999 999 - 10 000 000 000"<<endl;
                    cout<<"Enter the T.C. ID Number to be added:"<<endl;
                    cin>>TC_number;
                }
                MyHashMap.TruncationInsert(TC_number);
            }
        }
         else if(menu_options==4){
            if(hash_func==1)//folding
            {
                cout<<"Enter the T.C. ID Number to be deleted: ";
                cin>>TC_number;
                while(TC_number>99999999999 || TC_number<10000000000){// make sure TC is valid
                    cout<<"Invalid T.C. ID Number. The number has to be between 99 999 999 999 - 10 000 000 000"<<endl;
                    cout<<"Enter the T.C. ID Number to be added:"<<endl;
                    cin>>TC_number;
                }
                MyHashMap.FoldingRemove(TC_number);// remove
            }
            else if(hash_func==2)//middle Square
            {
                cout<<"Enter the T.C. ID Number to be deleted: ";
                cin>>TC_number;
                while(TC_number>99999999999 || TC_number<10000000000){// make sure TC is valid
                    cout<<"Invalid T.C. ID Number. The number has to be between 99 999 999 999 - 10 000 000 000"<<endl;
                    cout<<"Enter the T.C. ID Number to be added:"<<endl;
                    cin>>TC_number;
                }
                MyHashMap.MiddleSquaringRemove(TC_number);
            }
            else if(hash_func==3)// truncation
            {
                cout<<"Enter the T.C. ID Number to be deleted: ";
                cin>>TC_number;
                while(TC_number>99999999999 || TC_number<10000000000){// make sure TC is valid
                    cout<<"Invalid T.C. ID Number. The number has to be between 99 999 999 999 - 10 000 000 000"<<endl;
                    cout<<"Enter the T.C. ID Number to be added:"<<endl;
                    cin>>TC_number;
                }
                MyHashMap.TruncationRemove(TC_number);
            }
         }
        else if(menu_options==5){
            if(hash_func==1)//folding
            {
                cout<<"Enter the T.C. ID Number to be searched: "<<endl;
                cin>>TC_number;
                while(TC_number>99999999999 || TC_number<10000000000){// make sure TC is valid
                    cout<<"Invalid T.C. ID Number. The number has to be between 99 999 999 999 - 10 000 000 000"<<endl;
                    cout<<"Enter the T.C. ID Number to be searched:"<<endl;
                    cin>>TC_number;
                }
                if (MyHashMap.FoldingSearch(TC_number) == -1) {
                    cout<<"T.C. ID Number not found "<<endl;
                    continue;
                }
                else {
                    cout<<"The item is at key : ";
                    cout<<MyHashMap.FoldingSearch(TC_number)<<endl;
                }
            }
            else if(hash_func==2)// middle square
            {
                cout<<"Enter key of the T.C. ID Number to be searched: "<<endl;
                cin>>TC_number;
                while(TC_number>99999999999 || TC_number<10000000000){// make sure TC is valid
                    cout<<"Invalid T.C. ID Number. The number has to be between 99 999 999 999 - 10 000 000 000"<<endl;
                    cout<<"Enter the T.C. ID Number to be searched:"<<endl;
                    cin>>TC_number;
                }
                if (MyHashMap.MiddleSquaringSearch(TC_number) == -1) {
                    cout<<"T.C. ID Number not found "<<endl;
                    continue;
                }
                else {// if the item is found, the number "h" returns from search function
                    cout<<"The item is at key : ";
                    cout<<MyHashMap.MiddleSquaringSearch(TC_number)<<endl;
                }
            }
            else if(hash_func==3)//truncation
            {
                cout<<"Enter key of the T.C. ID Number to be searched: "<<endl;
                cin>>TC_number;
                while(TC_number>99999999999 || TC_number<10000000000){// make sure TC is valid
                    cout<<"Invalid T.C. ID Number. The number has to be between 99 999 999 999 - 10 000 000 000"<<endl;
                    cout<<"Enter the T.C. ID Number to be searched:"<<endl;
                    cin>>TC_number;
                }
                if (MyHashMap.TruncationSearch(TC_number) == -1) {
                    cout<<"T.C. ID Number not found "<<TC_number<<endl;
                    continue;
                }
                else {//if the item is found, the number "h" returns from search function
                    cout<<"The item is at key : ";
                    cout<<MyHashMap.TruncationSearch(TC_number)<<endl;
                }
            }
        }
        else if(menu_options==6){
                MyHashMap.PrintHashMap(); // print the table
        }
        else
            {cout<<"\nINVALID OPTION\n";} // Warn the user to choose a valid option
}
   return 0;
}
