//
//  Directory.h
//  Person
//
//  Created by Will Jameson on 4/30/24.
//

#ifndef Directory_h
#define Directory_h

#include "Person.h"


class Directory
{
private:
    

    int numEntries;
    BinaryTreeNode* rootPtr;
    
public:
    Directory();
    Directory(Directory &copyDirectory);
    ~Directory();
    bool isEmpty() const;
    BinaryTreeNode* addNode(BinaryTreeNode* subTreePtr, BinaryTreeNode* newNodePtr, bool& added);
    bool addEntry(const Person& entry);
    bool removeEntry(Person& entryName);
    bool isEntry(Person& entryName);
    void displayBirthday(Person& entryName) const;
    void displayDirectory(void visit(Person&));
  
    int directorySize() {return numEntries;}
    void searchDirectory(void visit(Person&), Person& entry);
    void sameMonth(void visit(Person&), int month);
    
    // helper functions
    BinaryTreeNode* rotate(BinaryTreeNode* indexNode);
    BinaryTreeNode* findNext(BinaryTreeNode* node);
    bool isListed(Person& entryName, BinaryTreeNode* indexPtr) const;
    void inOrderTraversal(void visit(Person&), BinaryTreeNode* indexPtr) const;
    void preOrderTraversal(void visit(Person&), BinaryTreeNode* indexPtr) const;
    void entriesByMonth( void visit(Person&), int& month, BinaryTreeNode* indexPtr, bool& executed) const;
    void searchHelper(void visit(Person&), Person& entry, BinaryTreeNode* indexPtr, bool& success) const;
    BinaryTreeNode* removeNode(BinaryTreeNode* subtreePtr, Person& entry, bool& success);
    //destructor
    void destroy(BinaryTreeNode* treeNode);

    
};

#endif /* Directory_h */
