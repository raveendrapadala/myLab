package main

import (
	"fmt"
	"reflect"
)

func main() {
	//To print const integer 42 in decimal(%d), binary(%b), Hexadecimal(%x),
	// character (%q) formats
	fmt.Printf("%d \t %b \t %#X \n", 42, 42, 42)

	//For loop Example to print ascii characters
	for i := 60; i < 122; i++ {
		fmt.Printf("%d \t %b \t %#x \t %q\n", i, i, i, i)
	}

	a := 10
	b := "golang"
	c := 4.17
	d := true
	e := "Hello"
	f := `Do you like my hat?`
	g := 'M'

	fmt.Printf("%v \t %T \n", a, a)
	fmt.Printf("%v \t %T \n", b, b)
	fmt.Printf("%v \t %T \n", c, c)
	fmt.Printf("%v \t %T \n", d, d)
	fmt.Printf("%v \t %T \n", e, e)
	fmt.Printf("%v \t %T \n", f, f)
	fmt.Printf("%v \t %T \n", g, g)

	//Variable Declaration and prints associated to them
	var intvar int
	//declaration
	var stringvar string
	//Initialization
	stringvar = "This is string Variable"
	var floatvar float64
	var boolvar bool

	fmt.Println(intvar)
	fmt.Println(stringvar)
	fmt.Println(floatvar)
	fmt.Println(boolvar)

	//Printing an empty line
	fmt.Println()

	//declaring uninitialized variables multiple at once
	var intvar1, intvar2 int
	fmt.Printf("%d\t%d\n", intvar1, intvar2)

	//initializing many variables at once
	var intVar1, intVar2, intVar3 int = 1, 2, 3
	fmt.Printf("%d\t%d\t%d\n", intVar1, intVar2, intVar3)
	fmt.Println(intVar1, intVar2, intVar3)

	test := "my string"
	tst2 := 10
	tst3 := 1.2

	fmt.Println(reflect.TypeOf(tst))
	fmt.Println(reflect.TypeOf(tst2))
	fmt.Println(reflect.TypeOf(tst3))

}
