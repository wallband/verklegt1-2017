#include "invalidageofcarexception.h"

InvalidAgeOfCarException::InvalidAgeOfCarException(string message)
{
    this->message = message;
}

string InvalidAgeOfCarException::getMessage()
{
    return this->message;
}
