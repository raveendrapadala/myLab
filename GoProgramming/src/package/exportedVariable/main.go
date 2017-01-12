package winniepooh

// MyName will be exported because it starts with a capital letter.
var BearName = "Pooh"

package main

import (
	"fmt"
	"github.com/GoesToEleven/GolangTraining/02_package/stringutil"
	"github.com/GoesToEleven/GolangTraining/02_package/icomefromalaska"
	//someAlias "github.com/GoesToEleven/GolangTraining/02_package/icomefromalaska"
)

func main() {
	fmt.Println(stringutil.Reverse("!oG ,olleH"))
	fmt.Println(stringutil.MyName)
	fmt.Println(winniepooh.BearName)
}
