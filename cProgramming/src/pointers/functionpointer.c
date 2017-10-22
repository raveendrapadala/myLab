#include <stdio.h>

int intSum (int num1, int num2)
{
    return num1+num2;
}

int intSub (int num1, int num2)
{
 int result =0;
 
 if((num1 < 0) || (num2 < 0))
   {
     result=-1;
   }
// return result = (num1>num2?num1-num2:num2-num1);
 return result = (num1>num2)?num1-num2:num2-num1;
}

int main()
{

    /* The following two lines can also be written in a single
     * statement like this: void (*fun_ptr)(int) = &fun;
     */
    int (*integerFunPointer) (int, int);
	
    integerFunPointer = intSum;
    //Calling function using function pointer
    int op1 = integerFunPointer(10, 13);

    integerFunPointer = intSub;
    //Calling function using function pointer
    int op2 = integerFunPointer(10, 13);
    //Calling function in normal way using function name
    //int op2 = sum(10, 13);

    printf("Addition using function pointer: %d",op1);
    printf("Substraction using function name: %d", op2);

    return 0;
}
