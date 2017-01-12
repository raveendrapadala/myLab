/***********************************************
This example explains the various ways of using 
switch
************************************************/

package main

import (
	"fmt"
	"time"
	)

func basicSwitchUsage()(){
    i := 2
    fmt.Print("Write ", i, " as ")
    switch i {
    case 1:
        fmt.Println("one")
    case 2:
        fmt.Println("two")
    case 3:
        fmt.Println("three")
    }

}

func commaSeparatedSwitch()(){
  // You can use commas to separate multiple expressions
    // in the same `case` statement. We use the optional
    // `default` case in this example as well.
    switch time.Now().Weekday() {
    case time.Saturday, time.Sunday:
        fmt.Println("It's the weekend")
    default:
        fmt.Println("It's a weekday")
    }
}

/*`switch` without an expression is an alternate way
  to express if/else logic. Here we also show how the
  `case` expressions can be non-constants.
*/
func switchWithOutCondition()(){

    t := time.Now()
    switch {
    case t.Hour() < 12:
        fmt.Println("It's before noon")
    default:
        fmt.Println("It's after noon")
    }

}

/* A type `switch` compares types instead of values.  You
  can use this to discover the the type of an interface
  value.  In this example, the variable `t` will have the
  type corresponding to its clause.
*/
func switchWithDataTypes()(){
    getInterfaceDatatype := func(i interface{}) {
        switch t := i.(type) {
        case bool:
            fmt.Println("I'm a bool")
        case int:
            fmt.Println("I'm an int")
        default:
            fmt.Printf("Don't know type %T\n", t)
        }
  }
    getInterfaceDatatype(true)
    getInterfaceDatatype(1)
    getInterfaceDatatype("hey")
    getInterfaceDatatype(2.0)
}

func main() {
	fmt.Println("Usage Example 1: Basic usage of switch")
	basicSwitchUsage()
	fmt.Println("Usage Example 2: Comman separated usage of switch")
	commaSeparatedSwitch()
	fmt.Println("Usage Example 3: switch without condition")
	switchWithOutCondition()
	fmt.Println("Usage Example 4: switch with datatypes")
	switchWithDataTypes()	
}
