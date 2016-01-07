// By Chris Kyle
// from listed input assign random secret santa partners
// without assigning someone their relative.

#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

vector<string>& split(const string&, char, vector<string>&);

class Person {

   private:
      string name;
      string partner;
      vector<string> relatives;

   public:
      Person() = delete;
      Person(string);
      string get_name();
      void add_relatives(vector<string>&);
      vector<string> get_relatives();
      void give_partner(string);
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

void Person::give_partner(string _name) { partner = _name; }

int main() {
   vector<Person> people;
   string line;
   ifstream myfile ("test");
   if (myfile.is_open()) {
      while (getline(myfile, line)) {
         vector<string> names = split(line, ' ', names);
         if (names.size() == 1) {
            Person newPerson(names.at(0));
            people.push_back(newPerson);
         } else {
            for (auto name : names) {
               Person newPerson(name);
               newPerson.add_relatives(names);
               people.push_back(newPerson);
            }
         }
      }

   }

}



vector<string>& split(const string& s, char delim, vector<string>& elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

