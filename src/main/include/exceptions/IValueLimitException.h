#ifndef __VALUELIMITEXCEPTION_H__
#define __VALUELIMITEXCEPTION_H__

#include <exception>

class IValueLimitException : public std::exception
{
public:
    virtual const char *what(void *payloadType) throw() = 0;
};

#endif // __VALUELIMITEXCEPTION_H__