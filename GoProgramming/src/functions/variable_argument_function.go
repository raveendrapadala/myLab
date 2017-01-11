
/*
* Concept: Variadic functions
* Description: These are the functions that can be called with any number of trailing arguments.
* For example, fmt.Println is a common variadic function.
*/

package main

import "fmt"

/*
 * @brief find the maximum number among the list given in the input
 * @param variable number of integer parameters
 * @return none
 */
func maxValue(numbers ...int) int {
	var largest int
	for _, v := range numbers {
		if v > largest {
			largest = v
		}
	}
  /*For this code to also work with only negative numbers such as greatest := max(-200 -700)
    for i, v := range numbers {
	    if v > largest || i == 0 {
		    largest = v
	    }
    }
   */ 
	return largest
}

/*
 * @brief calculates sum of the input integer variables
 * @param variable number of integer parameters
 * @return none
 */
func sumOfIntegers(nums ...int) {
    fmt.Print(nums, " ")
    total := 0
    for _, num := range nums {
        total += num
    }
    fmt.Println(total)
}

func main() {
	/*Variadic functions can be called in the usual way with individual arguments.*/
	greatestNumber := maxValue(4, 7, 9, 123, 543, 23, 435, 53, 125)
	sumOfIntegers(1, 2)
    	sumOfIntegers(1, 2, 3)
	fmt.Println(greatestNumber)
		
	/*If you already have multiple args in a slice, apply them to a variadic function using func(slice...) like this.*/
	numbersInslice := []int{1, 2, 3, 4}
        sumOfIntegers(numbersInslice...)
}

/*
 * Note: What does that code do?
 * The first time through the range loop the index, i, will be zero. so largest will be set to the first number Originally largest is set to the zero value for an int, which is zero
 * Zero would be greater than any negative number if you only have negative numbers you need largest to be something less than zero
 */
