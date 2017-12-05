#ifndef INVALIDAGEOFCAREXCEPTION_H
#define INVALIDAGEOFCAREXCEPTION_H
#include <string>
using namespace std;

class InvalidAgeOfCarException
{
    public:
        InvalidAgeOfCarException(string message);
        string getMessage();

    private:
        string message;
};

#endif // INVALIDAGEOFCAREXCEPTION_H
