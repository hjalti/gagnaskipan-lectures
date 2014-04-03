#ifndef HASHEXCEPTION_H
#define HASHEXCEPTION_H

#include <string>

using namespace std;

class HashException
{
	public:
		HashException();
		HashException(string msg) : message("HashException: " + msg) {};
		string getMessage() const {return message;};
	private:
		string message;
};

#endif // HASHEXCEPTION_H
