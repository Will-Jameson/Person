//
//  Person.cpp
//  Person
//
//  Created by Will Jameson on 4/30/24.
//

#include "Person.h"

Person::Person() {name = "John Doe"; birthday = 99999999; }

Person::Person(string entryName, int entryBirthday)
{
    name = entryName;
    birthday = entryBirthday;
    
}
void Person::setBirthdate()
{
    int month;
    int day;
    int year;
    
    
    cout << "Enter Birthday Month: ";
    cin >> month;
    cout << "\nDay: ";
    cin >> day;
    cout << "\nYear: ";
    cin >> year;
    cout << endl;
    
    birthday = (year * 10000) + (month * 100) + day;
    
}

void Person::viewBirthdate() const
{
    cout << (birthday/100) % 100 << "/" << birthday % 100 << "/" << birthday / 10000 << endl;
    
}
int Person::getBdayMonth()
{
    return (birthday/100) % 100;
}
void Person::setName()
{
    cout << "Name: ";
    

    getline(cin, name);
    
    cin.clear();
    //clear the input buffer
} // end Person class


