/*
 * @file callback_function.go
 * @author Raveendra Reddy P
 * @brief 
 *  Concept: callback
 *  Description: passing a func as an argument
 * @bug:
 */
 
 package main

import "fmt"

func visit(numbers []int, callback func(int)) {
	for _, n := range numbers {
		callback(n)
	}
}

func filter(numbers []int, callback func(int) bool) []int {
	var xs []int
	for _, n := range numbers {
		if callback(n) {
			xs = append(xs, n)
		}
	}
	return xs
}

func main() {
	visit([]int{1, 2, 3, 4}, func(n int) {
		fmt.Println(n)
	})
  
  xs := filter([]int{1, 2, 3, 4}, func(n int) bool {
		return n > 1
	})
	fmt.Println(xs) // [2 3 4]
}
