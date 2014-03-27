#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct Contact
{
	string name;
	string phone;
	string email;
	string address;
};

ostream& operator<< (ostream& out, const Contact& contact);

ostream& operator<< (ostream& out, vector<Contact>& contacts);

istream& operator>> (istream& out, Contact& contact);

bool compare_contacts_by_name(const Contact& lhs, const Contact& rhs);

bool compare_contacts_by_phone(const Contact& lhs, const Contact& rhs);


istream& operator>> (istream& in, Contact& contact)
{
    getline(in, contact.name, ';');
    getline(in, contact.phone, ';');
    getline(in, contact.email, ';');
    getline(in, contact.address);
	return in;
}

ostream& operator<< (ostream& out, const Contact& contact)
{
    out << "Name:  " << contact.name << endl;
    out << "Phone: " << contact.phone << endl;
    out << "Email: " << contact.email << endl;
    out << "Addr:  " << contact.address << endl;
    return out;
}

ostream& operator<< (ostream& out, vector<Contact>& contacts)
{
	for(size_t i = 0; i < contacts.size(); i++) {
		out << contacts[i] << endl;
	}
	return out;
}

bool compare_contacts_by_name(const Contact& lhs, const Contact& rhs)
{
	return lhs.name < rhs.name;
}

bool compare_contacts_by_phone(const Contact& lhs, const Contact& rhs)
{
	return lhs.phone < rhs.phone;
}

void print_contact(const Contact& c) {
    cout << c << endl;
}

template<class T>
T input()
{
    T t;
    cin >> t;
    return t;
}

void print(const vector<Contact>& contacts) {
    for_each(contacts.begin(), contacts.end(), print_contact);
}

int main()
{
    int n;
    cin >> n;
    vector<Contact> contacts(n);
    generate(contacts.begin(), contacts.end(), input<Contact>);
    print(contacts);
    print(contacts);

    return 0;
}
