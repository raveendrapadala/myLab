/*
 * @Description: when an exception is thrown, control is transferred to the NEAREST (catch) handler with a matching type.
 * @Level: Basic
 */

#include <iostream>
using namespace std;

/*
 * @Brief: Function is used to throw an integer exception
 */
void raiseExceptionFun(int i)
{
    throw i;
}

/*
 * @Brief: Detection of exception happens in try block 
 */
void catchExceptionFun(int i)
{
   //Trying to detect ANY exception that occurs inside ANY statement within this block
    try{
        raiseExceptionFun(i);
    }catch(int x){
	    std::cout<< "myExceptionFun";
	}
}

int main() {
	std::cout<< "During exception, nearest handler is called"
	try{
	    raiseExceptionFun(2);
	}catch(int x){
	    std::cout<< "main";
	}
	return 0;
}
