/* Uniform initialization is a feature in C++ 11 that allows the usage of a consistent syntax to initialize variables and objects ranging from primitive type to aggregates. In other words, it introduces brace-initialization that uses braces ({}) to enclose initializer values. The syntax is as follows:
type var_name{arg1, arg2, ....arg n}*/

#include <iostream>// initialization of variables
#include <string> //string is not a fundamental datatype, means we need to include an additional header file in our source code: <string> and have access to the std namespace
using namespace std;
//Namespace must be out of main
namespace myNamespace
{
  int intVar = 5;
  double doubVar = 3.142;
}
void integerInitialization(void);
int main()
{
    integerInitialization();
    //Strings Initialization, parameterized Initialization
    string conString ("Constructor Initialized string");
    cout << "paramConstInit=" << conString << endl;
    string uniformInitString {"Uniform Initialized string"};
    cout << uniformInitString << endl;
    cout << "\nintVar=" << myNamespace::intVar << "\ndoubvar=" << myNamespace::doubVar<< endl;
    //Gracefull shutdown of any process is must for valgrind
    return 0;
 }

void integerInitialization(void)
{
 //Integers Initialization
    int a=5;
    /* constructor initialization, is done by enclosing the initial value
    between parentheses:*/
    int b(2);
    int result{3}; // Uniform Initializatio introduced in C++ 11
    int copyConst{result};
    //error: expected unqualified-id before ‘using’
    //int using = 10;
    cout<< "Init Var a=" << a << "\nConstructor Var b=" << b << "\nresult=" << result << "\ncopyConstFromResult" << copyConst << endl;
}
