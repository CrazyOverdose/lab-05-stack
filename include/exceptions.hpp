//
// Created by absinthetoxin on 24.11.2019.
//

#ifndef TEMPLATE_EXCEPTIONS_H
#define TEMPLATE_EXCEPTIONS_H

#include <exception>
using namespace std;

class Exceptions : public exception
{
public:

    const char*what() const noexcept
    {
        return  "Error: Wrong input\n";
    }
};

#endif //TEMPLATE_EXCEPTIONS_H
