// Person.h By Chris Kyle
//
// This file defines the interface for the Person class.

#ifndef __PERSON_H_INCLUDED
#define __PERSON_H_INCLUDED

// #include <vector>
// #include <iostream>
// #include <sstream>

using namespace std;

// Stores information about a person
// Example:
//    Person myNewPerson(John);
//    myNewPerson.add_relatives(personVector);
//    myNewPerson.give_partner(Stacy);
class Person {
    private:
        // Keeps track of the name of the person
        string name;
        // A string of relatives that cannot be assigned
        // as a partner.
        vector<string> relatives;
        // The secret santa partner of this person.
        string partner = "I don't have a partner";
    public:
        // Don't allow default constructor, everyone has a name.
        Person() = delete;
        // Person constructor, sets the name of the person.
        Person(string);
        // Retrieves the name of the person.
        string get_name();
        // Adds the vector of strings as the relatives,
        // but do not include your own name as a relative.
        void add_relatives(vector<string>&);
        // Retrieves the vector of relatives.
        string get_partner();
        vector<string> get_relatives();
        // Sets the partner variable, returns 0 if successful
        // and 1 if the argument is the name of the person.
        int give_partner(string);
        void print_person(ostream&);
};

#endif
