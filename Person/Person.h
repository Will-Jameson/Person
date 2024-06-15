//
//  Person.h
//  Person
//
//  Created by Will Jameson on 4/30/24.
//

#ifndef Person_h
#define Person_h
#include<iostream>
using namespace std;

class Person
{
private:
    string name;

    int birthday;
    friend class Directory;
    
public:
    
    Person();
    Person(string entryName, int entryBirthday);
    void setName();
    string getName() const{return name;}
    void setBirthdate();
    int getBirthday() const {return birthday;}
    void viewBirthdate() const;
    int getBdayMonth();
    
    // Operator Section
    
   friend  bool operator>(Person& l, Person& r)
    {
        if (l.getName() > r.getName())
        {
            return true;
        }
        else return false;
    }

   friend  bool operator<(Person& l, Person& r)
    {
        if (l.getName() < r.getName())
        {
            return true;
        }
        else return false;
    }
    void visit(Person& item);
    

};
struct BinaryTreeNode
{

    Person dataEntry;
    BinaryTreeNode* rightPtr;
    BinaryTreeNode* leftPtr;
    

    BinaryTreeNode();
    BinaryTreeNode(Person data)
    {
        dataEntry = data;
        rightPtr = nullptr;
        leftPtr = nullptr;
    }
    
    
    
};
#endif /* Person_h */
