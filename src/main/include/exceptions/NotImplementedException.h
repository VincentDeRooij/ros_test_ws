#ifndef __NOTIMPLEMENTEDEXCEPTION_H__
#define __NOTIMPLEMENTEDEXCEPTION_H__

#include <exception>

class NotImplementedException : public std::exception
{
    const char *what() const throw()
    {
        return "Implementation not implemented, or not necessary at this moment!";
    }
};

#endif // __NOTIMPLEMENTEDEXCEPTION_H__