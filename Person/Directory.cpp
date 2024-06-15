//
//  Directory.cpp
//  Person
//
//  Created by Will Jameson on 4/30/24.
//

#include <stdio.h>
#include "Directory.h"

Directory::Directory()
{
    numEntries = 0;
    rootPtr = nullptr;
}

Directory::~Directory()
{
    destroy(rootPtr);
}
bool Directory::isEmpty() const
{
    return numEntries == 0;
}
BinaryTreeNode* Directory::addNode(BinaryTreeNode* subTreePtr, BinaryTreeNode* newNodePtr, bool& added)
{

    if (subTreePtr == nullptr)
    {
        return newNodePtr;
    }
    else
    {
        BinaryTreeNode* left = subTreePtr->leftPtr;
        BinaryTreeNode* right = subTreePtr->rightPtr;
        
        if (newNodePtr->dataEntry < subTreePtr->dataEntry)
        {
            left = addNode(left, newNodePtr, added);
            subTreePtr->leftPtr = left;
            added = true;
        }
        else if (newNodePtr->dataEntry > subTreePtr->dataEntry)
        {
            right = addNode(right, newNodePtr, added);
            subTreePtr->rightPtr = right;
            added = true;
        }
    return subTreePtr;
    }
}
bool Directory::addEntry(const Person& entry)
{
    bool added = false;
    BinaryTreeNode* addition = new BinaryTreeNode(entry);
    rootPtr = addNode(rootPtr, addition, added);
    numEntries++;
    if (added)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Directory::removeEntry(Person& entryName)
{

    bool removed = false;
    rootPtr = removeNode(rootPtr, entryName, removed);
    return removed;
}

void Directory::destroy(BinaryTreeNode* treePtr)
{
    if (treePtr != nullptr)
    {
        destroy(treePtr->leftPtr);
        destroy(treePtr->rightPtr);
        delete treePtr;
    }

}
void Directory::displayDirectory(void visit(Person&))
{
    inOrderTraversal(visit, rootPtr);
}

void Directory::searchDirectory(void visit(Person&), Person& entry)
{
    bool success = false;
    searchHelper(visit, entry, rootPtr, success);
    if (!success)
    {
        cout << "Directory does not contain " << entry.getName() << endl;
    }
}
bool Directory::isListed(Person& entryName, BinaryTreeNode* indexPtr) const
{
    int count= 0;
    if (indexPtr != nullptr)
    {
        string name = indexPtr->dataEntry.getName();
        if (name == entryName.getName())
        {
            return true;
        }
        if (isListed(entryName, indexPtr->leftPtr))
        {
            count++;
        }
        
        if (isListed(entryName, indexPtr->leftPtr))
        {
            count++;
            
        }
    }
    if (count > 0)
    {
        return true;

    }
    else
    {
        return false;
    }



}
bool Directory::isEntry(Person& entryName)
{
    if (isListed(entryName, rootPtr))
    {
        return true;
    }
    else
    {
        return false;
    }
}


// HELPER FUNCTIONS
//

BinaryTreeNode* Directory::removeNode(BinaryTreeNode* indexPtr, Person& entry, bool& success) //passes success by reference!
{
    if (indexPtr == nullptr)
    {
        success = false;
        return nullptr;
    }
    if (indexPtr->dataEntry.getName() == entry.getName())
    {
        success = true;
        // case 1:  Entry has no children
        if ((indexPtr->rightPtr == nullptr) && (indexPtr->leftPtr == nullptr))
        {
            delete indexPtr;
            return nullptr;
        }
        //case 2: Entry has exactly 1 child
        else if (indexPtr->leftPtr == nullptr)
        {
            BinaryTreeNode* tmp = indexPtr->rightPtr;
            delete indexPtr;
            return tmp;
        }
        else if (indexPtr->rightPtr == nullptr)
        {
            BinaryTreeNode* tmp = indexPtr->leftPtr;
            delete indexPtr;
            return tmp;
        }
        //case 3: has two children
        else
        {
            BinaryTreeNode* successor = findNext(indexPtr->rightPtr);  // find the in order successor
            successor->dataEntry = indexPtr->dataEntry;
            
            indexPtr->rightPtr = removeNode(indexPtr->rightPtr, successor->dataEntry, success);
            return indexPtr;
        }
    }
    else if (indexPtr->dataEntry.getName() < entry.getName())
    {
        indexPtr->rightPtr = removeNode(indexPtr->rightPtr, entry, success);
        
    }
    else
    {
        indexPtr->leftPtr = removeNode(indexPtr->leftPtr, entry, success);
    }
    return indexPtr;
}


BinaryTreeNode* Directory::findNext(BinaryTreeNode* node)
{
    while (node->leftPtr != nullptr)
    {
        node = node->leftPtr;
    }
    return node;
}
void Directory::sameMonth(void visit(Person&), int month)
{
    bool success = false;
    
    cout << "Entries sharing month " << month << ": " << endl;
    entriesByMonth(visit, month, rootPtr, success);
    if (!success)
    {
        cout << "No entries with this month." << endl;
    }
}
void Directory::entriesByMonth(void visit(Person&), int& month, BinaryTreeNode* indexPtr, bool& success) const
{

    if (indexPtr!= nullptr)
    {
        int indexMonth = indexPtr->dataEntry.getBdayMonth();
        if (indexMonth == month)
        {
            success = true;

            visit(indexPtr->dataEntry);
            entriesByMonth(visit, month, indexPtr->leftPtr, success);
            entriesByMonth(visit, month, indexPtr->rightPtr, success);
        }
        else
        {
            entriesByMonth(visit, month, indexPtr->leftPtr, success);
            entriesByMonth(visit, month, indexPtr->rightPtr, success);
        }
    }

}
void Directory::searchHelper(void visit(Person&), Person& entry, BinaryTreeNode* indexPtr, bool& success) const
{
    if (indexPtr!= nullptr)
    {
        string indexName = indexPtr->dataEntry.getName();
        if (indexName == entry.getName())
        {
            cout << "Found!" << endl;
            success = true;
            visit(indexPtr->dataEntry);
            return;
        }
        else
        {
            searchHelper(visit, entry, indexPtr->leftPtr, success);
            searchHelper(visit, entry, indexPtr->rightPtr, success);
        }
    }

}


void Directory::inOrderTraversal(void visit(Person&), BinaryTreeNode* indexPtr) const
{
    if (indexPtr != nullptr)
    {
        Person item = indexPtr->dataEntry;
        inOrderTraversal(visit, indexPtr->leftPtr);
        visit(item);
        inOrderTraversal(visit, indexPtr->rightPtr);
    }
}
void Directory::preOrderTraversal(void visit(Person&), BinaryTreeNode* indexPtr) const
{
    
    if (indexPtr != nullptr)
    {
        Person item = indexPtr->dataEntry;
        
        visit(item);
        preOrderTraversal(visit, indexPtr->leftPtr);
        preOrderTraversal(visit, indexPtr->rightPtr);
    }
}



