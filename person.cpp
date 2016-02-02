// Person.cpp By Chris Kyle
//
// This file contains the implementation for the person Class

#include "person.h"

Person::Person(string _name) : name{_name} {}

string Person::get_name() { return name; }

void Person::add_relatives(vector<string>& names) {
    for (auto _name : names) {
        if (name != _name){
            relatives.push_back(_name);
        }
    }
}

string Person::get_partner() { return partner; }

vector<string> Person::get_relatives() { return relatives; }

int Person::give_partner(string _name) {
    if (name == _name){
        return 0;
    }
    for (auto relative : relatives) {
        if (_name == relative) {     // If we try to add a relative
            return 0;               // as a partner, return 0.
        }
    }
    partner = _name;
    return 1;
}

void Person::print_person(ostream& out) {
    out << name << " " << partner << endl;
}
