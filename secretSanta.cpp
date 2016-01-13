// By Chris Kyle
// from listed input assign random secret santa partners
// without assigning someone their relative.

#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

vector<string> split(const string&, char);

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
        // The secret santa parter of this person.
        string partner;
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
        vector<string> get_relatives();
        // Sets the partner variable, returns 0 if successful
        // and 1 if the argument is the name of the person.
        int give_partner(string);
};

Person::Person(string _name) : name{_name} {}

string Person::get_name() { return name; }

void Person::add_relatives(vector<string>& names) {
    for (auto _name : names) {
        if (name != _name){
            relatives.push_back(_name);
        }
    }
}

vector<string> Person::get_relatives() { return relatives; }

int Person::give_partner(string _name) { 
    if (name == _name) {
        return 1;
    } else {
        partner = _name;
        return 0;
    }
}

int main() {
    vector<Person> people;
    string line;
    // TODO(ckyle@ucsc.edu): Get the file name as an arg
    ifstream myfile ("test");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            vector<string> names = split(line, ' ');
            // If there is only one name on the line,
            // then this person has no relatives
            if (names.size() == 1) {
                Person newPerson(names.at(0));
                people.push_back(newPerson);
            // Otherwise, iterate through the names
            // and add them as relatives.
            } else {
                for (auto name : names) {
                    Person newPerson(name);
                    newPerson.add_relatives(names);
                    people.push_back(newPerson);
                }
            }
        }
    }
    vector<Person> noPartner = people;
    vector<Person> noReceive = people; // No one has been assigned the people
                                       // on this list.
    for (person : noPartner) {
        int x = rand() % noReceive.size();
        while (person.give_partner(noReceive.at(x)));
        
// If you do not haven't been assigned a partner yet, then you are in
// the noPartner vector. For every member of the noPartner vector,
// assign them a partner from the noReceive vector. The give_partner
// function will return a 1 if that partner is a relative, or a 0 if a valid
// partner is assigned.


}

// Split the string at the delim and return a vector
// of strings that make up the components.
vector<string> split(const string& s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

