//Standalone executable program must start with main package declaration.main is the package you are creating.
// if the package name is otherthan main then it means we are making a shared library/dynamic library
package main
//import keyword is how we include code from other packages to use with our program.
import "fmt"

/**
 * This function prints the ascii table
 *  Here %q represents character surrounded by single quotes
**/
func printASCIIValues()(){
  fmt.Printf("Decimal,Binary,HexDecimal,character\n",)
  for itrCount := 0; itrCount < 122; itrCount++  {
	fmt.Printf("%d \t %b \t %x \t %q \n", itrCount, itrCount, itrCount, itrCount)
  }
}

func main()(){
  printASCIIValues()
}


//Go Programming language Specification: https://golang.org/ref/spec
//For examples, Refer: https://gobyexample.com
//To understand about packages refer, https://golang.org/pkg/
