#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <vector>

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

// Reads contact information in CSV-format (using ';' as delimiter).
istream& operator>> (istream& out, Contact& contact);

// Returns true if and only if the name of 'lhs' is lexicographically smaller
// than the name of 'rhs'
bool compare_contacts_by_name(const Contact& lhs, const Contact& rhs);

// Returns true if and only if the phone of 'lhs' is lexicographically smaller
// than the phone of 'rhs'
bool compare_contacts_by_phone(const Contact& lhs, const Contact& rhs);


#endif
