package main

import "fmt"

func main() {
    usingdeferUnamedAndRecoverFunction()
    fmt.Println("Returned normally from usingdeferUnamedAndRecoverFunction.")
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
