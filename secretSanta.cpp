// By Chris Kyle
// from listed input assign random secret santa partners
// without assigning someone their relative.
// https://www.reddit.com/r/dailyprogrammer/comments/3yiy2d/20151228_challenge_247_easy_secret_santa/

#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

#include "person.cpp"

using namespace std;


// Split the string at the delim and return a vector of strings that
// make up the components.
vector<string> split(const string&, char);
// Creates a vector of people from an input file, also adds their
// relatives
vector<Person> add_people(ifstream&);
// Using a list of people without partners and a list of people
// to whom no one is assigned to give a gift yet, this function assigns
// each person a partner randomly.
vector<Person> assign_partner(vector<Person>);

vector<string> split(const string& s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<Person> add_people(ifstream& myfile) {
    vector<Person> people;
    string line;
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
    return people;
}

// If you haven't been assigned a partner yet, then you are in
// the noPartner vector. For every member of the noPartner vector,
// assign them a partner from the noReceive vector. The Person::give_partner
// function will return a 1 if that partner is a relative, or a 0 if a valid
// partner is assigned.
vector<Person> assign_partners(vector<Person> people) {
    vector<Person> noPartner = people;
    vector<Person> noReceive = people; // No one has been assigned the people
                                       // on this list.
    vector<Person> partners;
    for (auto person = noPartner.begin(); person != noPartner.end();) {
        int x = rand() % noReceive.size();
        while (true) {
            if ((*person).give_partner((noReceive.at(x)).get_name())) {
                partners.push_back(*person);
                break;
            } else {
                x = rand() % noReceive.size();
            }
        }
        noPartner.erase(person);
        auto itor = noReceive.begin() + x;
        noReceive.erase(itor);
    }
    return partners;
}

int main() {
    vector<Person> people;
    ifstream myfile ("test");
    if (myfile.is_open()) {
        people = add_people(myfile);
    }
    vector<Person> partners = assign_partners(people);
    for (auto person : partners) {
        person.print_person(cout);
    }
    return 0;

}



