#ifndef INTERACTIVEPHONEBOOK_H
#define INTERACTIVEPHONEBOOK_H value

#include "ContactManager.h"

class InteractivePhoneBook {
	public:
		// Starts the interactive phone book application.
		void start();

	private:
		ContactManager contact_manager;

		// Prints welcome message
		void welcome();

		// Prints help menu.
		void help();

		// Starts the read-evaluate-print loop.
		void repl();

		// Writes all contacts to the standard output.
		void list();

		// Reads an integer 'n' from in and subsequently inputs 'n' contacts
		// and adds them to the manager.
		void add_contacts(istream& in);

		// Inputs a file name and adds contacts from that file.
		void add_contacts_from_file();

		// Reads a contact name from the standard input and outputs the contact
		// info.
		void get_contact_by_name();

		// Reads a contact name from the standard input into 'name'. Returns
		// true if and only if the contact is present in the contact manager.
		bool get_contact_by_name(string& name);

		// Reads a phone number from the standard input and outputs the contact
		// info for that phone number.
		void get_contact_by_phone();

		// Inputs a prefix string and outputs all contacts with names beginning
		// with that prefix.
		void search_by_name();

		// Inputs a prefix string and outputs all contacts with phone numbers
		// beginning with that prefix.
		void search_by_phone();

		// Prints the contact info of the specified contacts to the standard
		// output.
		void print_contacts(vector<Contact>& contacts);

		// Reads a name from the standard input. If that contact exists, a new
		// phone number is input and that contact's phone number is updated.
		void update_phone();

		// Reads a name from the standard input. If that contact exists, a new
		// email address is input and that contact's email address is updated.
		void update_email();

		// Reads a name from the standard input and removes the contact with
		// that name from the contact manager.
		void remove();

		// Inputs the parameters of the specified command and executes it.
		// Returns true if and only if the repl should continue.
		bool execute_command(string command);
};

#endif
