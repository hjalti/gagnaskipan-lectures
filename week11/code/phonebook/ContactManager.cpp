#include "ContactManager.h"
#include <algorithm>

void ContactManager::add(Contact contact)
{
	if(phone_map.count(contact.phone)) {
		throw DuplicatePhoneException();
	}
	if(name_map.count(contact.name)) {
		throw DuplicateNameException();
	}
    phone_map[contact.phone] = contact;
    name_map[contact.name] = contact;
}

void ContactManager::remove(string name)
{
    if(!name_map.count(name)) {
        return;
    }
    Contact c = name_map[name];
    name_map.erase(name_map.find(c.name));
    phone_map.erase(phone_map.find(c.phone));
}

void ContactManager::update_phone(string name, string new_number)
{
    if(!name_map.count(name)) {
        throw ContactMissingException();
    }
    Contact& c = name_map[name];
    string old_number = c.phone;
    c.phone = new_number;

    phone_map.erase(phone_map.find(old_number));
    phone_map[c.phone] = c;

}

void ContactManager::update_email(string name, string new_email)
{
    if(!name_map.count(name)) {
        throw ContactMissingException();
    }
    Contact& c = name_map[name];
    c.email = new_email;
    phone_map[c.phone].email =  c.email;
}

bool ContactManager::name_exists(string name)
{
    return name_map.count(name);
}

bool ContactManager::phone_exists(string phone)
{
    return phone_map.count(phone);
}

Contact ContactManager::get_contact_by_name(string name)
{
    if(!name_exists(name)) {
        throw ContactMissingException();
    }
    return name_map[name];
}

Contact ContactManager::get_contact_by_phone(string phone)
{
    if(!phone_exists(phone)) {
        throw ContactMissingException();
    }
    return phone_map[phone];
}

vector<Contact> ContactManager::get_contacts_by_name_prefix(string name_prefix)
{
    vector<Contact> v;
    for(map<string, Contact>::iterator it = name_map.begin(); it != name_map.end(); it++) {
        if(it->first.find(name_prefix) == 0) {
            v.push_back(it->second);
        }
    }
    return v;
}

vector<Contact> ContactManager::get_contacts_by_phone_prefix(string phone_prefix)
{
    vector<Contact> v;
    for(map<string, Contact>::iterator it = phone_map.begin(); it != name_map.end(); it++) {
        if(it->first.find(phone_prefix) == 0) {
            v.push_back(it->second);
        }
    }
    return v;
}

ostream& operator<< (ostream& out, ContactManager& manager)
{
    for(map<string, Contact>::iterator it = manager.name_map.begin(); it != manager.name_map.end(); it++) {
        out << it->second << endl;
    }
    out << endl;

    for(map<string, Contact>::iterator it = manager.phone_map.begin(); it != manager.phone_map.end(); it++) {
        out << it->second << endl;
    }
    return out;
}
