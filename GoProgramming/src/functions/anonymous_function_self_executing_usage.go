/*
 * Anonymous function and self executing function.
 */
package main

import "fmt"

func main() {
	func() {
		fmt.Println("I'm driving!")
	}()
}
