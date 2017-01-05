/**********************************************************************************************
* This example covers concepts like recursive function, defer,panic and recover keywords
* courtesy: https://blog.golang.org/defer-panic-and-recover
*
* The behavior of defer statements is straightforward and predictable. There are three simple rules:
*   1. A deferred function's arguments are evaluated when the defer statement is evaluated.
*   2. Deferred function calls are executed in Last In First Out order after the surrounding function returns.
*   3. Deferred functions may read and assign to the returning function's named return values.
*
* Panic is a built-in function that stops the ordinary flow of control and begins panicking. When the function F calls panic, execution * of F stops, any deferred functions in F are executed normally, and then F returns to its caller. To the caller, F then behaves like a * call to panic. The process continues up the stack until all functions in the current goroutine have returned, at which point the  *program crashes. Panics can be initiated by invoking panic directly. They can also be caused by runtime errors, such as out-of-bounds *array accesses.

*Recover is a built-in function that regains control of a panicking goroutine. Recover is only useful inside deferred functions. During *normal execution, a call to recover will return nil and have no other effect. If the current goroutine is panicking, a call to recover *will capture the value given to panic and resume normal execution.
*****************************************************************************************************/

package main

import "fmt"

func main() {
    currentValue := 0
    defer fmt.Println(currentValue)
    currentValue++
    usingdeferUnamedAndRecoverFunction()
    fmt.Println("Returned normally from usingdeferUnamedAndRecoverFunction.")
    defer fmt.Println(currentValue)
}

func usingdeferUnamedAndRecoverFunction() {
    defer func() {
        if r := recover(); r != nil {
            fmt.Println("Recovered in usingdeferUnamedAndRecoverFunction", r)
        }
    }()
    fmt.Println("Calling usingDeferPanicAndRecursiveFunction.")
    usingDeferPanicAndRecursiveFunction(0)
    fmt.Println("Returned normally from usingDeferPanicAndRecursiveFunction.")
}

func usingDeferPanicAndRecursiveFunction(iterCount int) {
    if iterCount > 3 {
        fmt.Println("Panicking!")
        panic(fmt.Sprintf("%v", iterCount))
    }
    defer fmt.Println("Defer in usingDeferPanicAndRecursiveFunction", iterCount)
    fmt.Println("Printing in usingDeferPanicAndRecursiveFunction", iterCount)
    usingDeferPanicAndRecursiveFunction(iterCount + 1)
}

/*
* Note: 
* 1. If we remove the deferred function from usingdeferUnamedAndRecoverFunction, the panic is not recovered and reaches the top of the *goroutine's call stack, terminating the program.
* 2.For a real-world example of panic and recover, see the json package from the Go standard library. It decodes JSON-encoded data with *a set of recursive functions. When malformed JSON is encountered, the parser calls panic to unwind the stack to the top-level function *call, which recovers from the panic and returns an appropriate error value (see the 'error' and 'unmarshal' methods of the decodeState *type in decode.go).
*/
