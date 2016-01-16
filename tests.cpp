// Tests for secretSanta.cpp
//

void test_relatives();

void test_relatives() {
    Person test_person1("John");
    Person test_person2("Bob");
    Person test_person3("Billy");
    Person test_person4("Fred");
    Person test_person5("Joe");
    vector<string> people;
    people.push_back("John");
    people.push_back("test_person2");
    people.push_back("test_person3");
    people.push_back("test_person4");
    test_person1.add_relatives(people);
    for (auto person : test_person1.get_relatives()) {
        cout << person << endl;
        cout << test_person1.give_partner(person) << endl;
    }
    cout << "partner" << test_person1.get_partner();
    // need to make it so if someone has a partner already, they
    // can't be given another one.
    test_person1.give_partner("sally");
    test_person1.print_person(cout);
    cout << "partner" << test_person1.get_partner();

}
