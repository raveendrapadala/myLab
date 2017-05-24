/*
 * @Description: Raising an exception through Object,
 * A ‘throw’ expression could initialize a ‘temporary’ object. This temporary object is used to initialize the variable named in the matching ‘catch’ handler.
 * @Level: Basic
 */

#include <iostream>
using namespace std;

struct myExceptionObject {
  myExceptionObject() { std::cout << "myExceptionObject base constructor\n"; }
  myExceptionObject(const myExceptionObject& rhs) { std::cout << "myExceptionObject copy constructor\n"; }
};

int main() {
  try {
    myExceptionObject e1;
    //copy of the object is thrown by creating a temporary object.
    throw e1; 
  } catch (myExceptionObject e3) {
    std::cout << "Exception is Caught\n";
  }
  return 0;
}

/* LEARNINGS
 * Que: How many times do you think the constructors are called in the code below ?
 * Ans: Possibly 3 times, 1 Base constructor and 2 copy constructors. 
 * if the compiler optimizes then object e1 will be used directly in catch handler exception specification instead of new one.
 * 
 * Que: what is the output of this function?
 * Ans: myExceptionObject base constructor
 * myExceptionObject copy constructor
 * myExceptionObject copy constructor
 * Exception is Caught
 */
