
#ifndef empty_stack_exception_H
#define empty_stack_exception_H

#include <stdexcept>
#include <string>
using namespace std;
class empty_stack_exception : public logic_error
{
 public:
   empty_stack_exception(string info) : logic_error(info) {}
};

#endif //empty_stack_exception_H