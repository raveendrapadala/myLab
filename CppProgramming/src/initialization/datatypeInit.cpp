// initialization of variables
#include <iostream>

//string is not a fundamental datatype, means we need to include an 
//additional header file in our source code: <string> and have access 
//to the std namespace
#include <string>
using namespace std;

int main()
{
 //Integers Initialization
 int a=5; // initial value = 5
 // constructor initialization, is done by enclosing the initial value
 //between parentheses (()):
 int b(2);
 int result; // initial value undetermined
 cout<< a << b << result << endl;
 
 //Strings Initialization
 string mystring;
 mystring = "This is the initial string content";
 cout << mystring << endl;
 mystring = "This is a different string content";
 cout << mystring << endl;
 
 //Gracefull shutdown of any process is must for valgrind
 return 0;
 }
