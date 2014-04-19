#ifndef QUEUEEXCEPTION_H
#define QUEUEXCEPTION_H
#include <string>

using namespace std;

class QueueException
{
	public:
		QueueException(string str) : message("QueueException: " + str) {};
		string getMessage() const {return message;};
	private:
		string message;
};
#endif // QUEUEEXCEPTION_H
