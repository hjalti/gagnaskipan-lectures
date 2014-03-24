#include <iostream>
#include <vector>
#include <fstream>
#include "InteractivePhoneBook.h"

using namespace std;

void InteractivePhoneBook::welcome()
{
    cout << "Welcome to the Contact Manager v1.337" << endl;
    cout << "Type 'help' for help and 'quit' to quit" << endl << endl;
}

void InteractivePhoneBook::help()
{
    cout << "The following commands are available" << endl
         << "help:             Prints this help menu" << endl
         << "ls:               List all the contacts in the Contact Manager" << endl
         << "add 'n':          Adds 'n' contacts to the Contact Manager." << endl
         << "                  The contacts should be in CSV format" << endl
         << "file 'file':      Adds contacts to the Contact Manager from 'file'. " << endl
         << "                  The contacts should be in CSV format, and the number of" << endl
         << "                  contacts should be the first line of the file." << endl
         << "get 'name':       View contact with the name 'name'" << endl
         << "getp 'phone':     View contact with the phone number 'phone'" << endl
         << "rm 'name':        Remove the contact with the name 'name'" << endl
         << "search 'name':    View all contacts whose name starts with 'name'" << endl
         << "searchp 'phone':  View all contacts whose phone number starts with 'phone'" << endl
         << "upde 'name':      Updates the email of the contact with name 'name'." << endl
         << "updp 'name':      Updates the phone number of the contact with name 'name'." << endl
         << "quit:             Quits the Contact Manager" << endl;
}

void InteractivePhoneBook::list()
{
    cout << contact_manager << endl;
}

void InteractivePhoneBook::add_contacts(istream& in)
{
    int count;
    in >> count;
    ws(in);
    for(int i = 0; i != count; i++) {
        Contact c;
        in >> c;
		if(contact_manager.name_exists(c.name)) {
			cout << "Contact already exists with the name " << c.name << endl;
			continue;
		}
		if(contact_manager.phone_exists(c.phone)) {
			cout << "Contact already exists with the phone number " << c.phone << endl;
			continue;
		}
        contact_manager.add(c);
    }
}

void InteractivePhoneBook::add_contacts_from_file()
{
    ifstream in;
    string filename;
    cin >> filename;
    in.open(filename.c_str());
    if(in.fail()) {
        cout << "Error opening file '" << filename << "'" << endl;
    }
    add_contacts(in);
}

void InteractivePhoneBook::get_contact_by_name()
{
    string unused;
    get_contact_by_name(unused);
}

bool InteractivePhoneBook::get_contact_by_name(string& name)
{
    getline(cin, name);
    if(contact_manager.name_exists(name)) {
        cout << contact_manager.get_contact_by_name(name) << endl;
        return true;
    } else {
        cout << "No contact exists with the name '" << name << "'" << endl;
        return false;
    }
}

void InteractivePhoneBook::get_contact_by_phone()
{
    string phone;
    cin >> phone;
    if(contact_manager.phone_exists(phone)) {
        cout << contact_manager.get_contact_by_phone(phone) << endl;
    } else {
        cout << "No contact exists with the phone number '" << phone << "'" << endl;
    }
}

void InteractivePhoneBook::remove()
{
    string name;
    getline(cin, name);
    contact_manager.remove(name);
}

void InteractivePhoneBook::search_by_name()
{
    string name;
    getline(cin, name);
    vector<Contact> v = contact_manager.get_contacts_by_name_prefix(name);
    print_contacts(v);
}

void InteractivePhoneBook::search_by_phone()
{
    string phone;
    cin >> phone;
    vector<Contact> v = contact_manager.get_contacts_by_phone_prefix(phone);
    print_contacts(v);
}

void InteractivePhoneBook::update_phone()
{
    string name;
    if(get_contact_by_name(name)) {
        cout << "New phone number: ";
        string phone;
        cin >> phone;
        contact_manager.update_phone(name, phone);
    }
}

void InteractivePhoneBook::update_email()
{
    string name;
    if(get_contact_by_name(name)) {
        cout << "New email: ";
        string email;
        cin >> email;
        contact_manager.update_email(name, email);
    }
}

void InteractivePhoneBook::print_contacts(vector<Contact>& contacts) {
    for(size_t i = 0; i < contacts.size(); i++) {
        cout << contacts[i] << endl;
    }
}

bool InteractivePhoneBook::execute_command(string command)
{
    if(command == "help") {
        help();
    } else if(command == "ls") {
        list();
    } else if(command == "add") {
        ws(cin);
        add_contacts(cin);
    } else if(command == "file") {
        ws(cin);
        add_contacts_from_file();
    } else if(command == "get") {
        ws(cin);
        get_contact_by_name();
    } else if(command == "getp") {
        ws(cin);
        get_contact_by_phone();
    } else if(command == "rm") {
        ws(cin);
        remove();
    } else if(command == "search") {
        ws(cin);
        search_by_name();
    } else if(command == "searchp") {
        ws(cin);
        search_by_phone();
    } else if(command == "updp") {
        ws(cin);
        update_phone();
    } else if(command == "upde") {
        ws(cin);
        update_email();
    } else if(command == "quit") {
        return false;
    } else {
        cout << "Unknown command '" << command << "'" << endl;
    }
    return true;
}

void InteractivePhoneBook::repl()
{
    string command;
    do {
        cout << "ContactManager> ";
    } while(cin >> command && execute_command(command));
    cout << endl << "Exiting. Goodbye :(" << endl;
}

void InteractivePhoneBook::start()
{
    welcome();
    repl();
}
