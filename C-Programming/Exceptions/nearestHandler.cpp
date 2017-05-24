#include <iostream>
using namespace std;

void f(int i)
{
    throw i;
}

void myExceptionFun(int i)
{
    try{
        f(i);
    }catch(int x){
	    std::cout<< "myExceptionFun";
	}
}

int main() {
	// your code goes here
	try{
	    myExceptionFun(2);
	}catch(int x){
	    std::cout<< "main";
	}
	return 0;
}
