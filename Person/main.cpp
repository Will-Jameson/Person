//
//  main.cpp
//  Person
//
//  Created by Will Jameson on 4/29/24.
//

#include <iostream>
#include "Person.h"
#include "Directory.h"

using namespace std;



void view(Person& aPerson)
{
//    cout << "visit"<< endl;
    cout << aPerson.getName() << ": ";
    aPerson.viewBirthdate();

}

int main()
{
    Person ivy;
    ivy.setName();
    ivy.setBirthdate();
    Person will("Will", 19830727);
    Person tessa("Tessa", 19910729);
    Person alan("Alan", 19980226);
    Person mitch("Mitch", 19661114);
    Person meghan("Meghan", 19821120);
    Person jerome("Jerome", 19880130);
    Person ollie("Ollie", 20241218);
    Person martha("Martha", 19620102);
    Person jesus("Jesus", 19821225);
    
    Directory* book = new Directory();
    cout << "Adding Entries:\nWill\nTessa\nAlan\nMitch\nMeghan\nJerome\nOllie\nJesus\n" << endl;
    
    book->addEntry(will);
    book->addEntry(tessa);
    book->addEntry(alan);
    book->addEntry(mitch);
    book->addEntry(meghan);
    book->addEntry(jerome);
    book->addEntry(ollie);
    book->addEntry(jesus);
    book->addEntry(ivy);
    
    cout << "Displaying Directory: " << endl;
    
    book->displayDirectory(view);
    cout << endl;
    
    cout << "Testing for entries in July" << endl;
    book->sameMonth(view, 7);
    cout << endl;
    book->sameMonth(view, 12);
    cout << endl;
    book->sameMonth(view, 11);
    cout << endl;
    book->sameMonth(view, 2);
    cout << endl;
    cout << "Removing Alan from directory: " << endl;
    book->removeEntry(alan);
    book->searchDirectory(view,alan);
    cout << endl;

    book->sameMonth(view, 2);
    cout << endl;
    cout << "search for ollie.\nShould be found" << endl;
    book->searchDirectory(view, ollie);
    cout <<  endl;
   
    cout << "Searching for Alan in directory. Expect not found:  " << endl;
    book->searchDirectory(view,alan);
  

    
//    book.displayDirectory();
    return 0;
}
//

/*
 SAMPLE OUTPUT:
 Name: Ivy
 Enter Birthday Month: 12

 Day: 25

 Year: 2021

 Adding Entries:
 Will
 Tessa
 Alan
 Mitch
 Meghan
 Jerome
 Ollie
 Jesus

 Displaying Directory:
 Alan: 2/26/1998
 Ivy: 12/25/2021
 Jerome: 1/30/1988
 Jesus: 12/25/1982
 Meghan: 11/20/1982
 Mitch: 11/14/1966
 Ollie: 12/18/2024
 Tessa: 7/29/1991
 Will: 7/27/1983

 Testing for entries in July
 Entries sharing month 7:
 Will: 7/27/1983
 Tessa: 7/29/1991

 Entries sharing month 12:
 Ivy: 12/25/2021
 Jesus: 12/25/1982
 Ollie: 12/18/2024

 Entries sharing month 11:
 Mitch: 11/14/1966
 Meghan: 11/20/1982

 Entries sharing month 2:
 Alan: 2/26/1998

 Removing Alan from directory:
 Directory does not contain Alan

 Entries sharing month 2:
 No entries with this month.

 search for ollie.
 Should be found
 Found!
 Ollie: 12/18/2024

 Searching for Alan in directory. Expect not found:
 Directory does not contain Alan
 Program ended with exit code: 0
 */
