Few links for reference for interfaces: https://go-book.appspot.com/interfaces.html  https://research.swtch.com/interfaces  http://jordanorelli.com/post/32665860244/how-to-use-interfaces-in-go  https://www.youtube.com/watch?v=Ijp8vd85sYI



Functions Running Forever: package main

import (
	"log"
	"math/rand"
	"time"
	"runtime"
)

func init() {
	rand.Seed(time.Now().UnixNano())
}

func fA() {
	log.Print("fA started. Number of goroutines: ", runtime.NumGoroutine())
	time.Sleep(time.Second * time.Duration(rand.Intn(5)))
	panic("fA crashed.")
}

func fB() {
	log.Print("fB started. Number of goroutines: ", runtime.NumGoroutine())
	time.Sleep(time.Second * time.Duration(rand.Intn(5)))
	panic("fB crashed.")
}

func NeverExit(f func()) {
	defer func() {
		log.Print(recover()) // recover
		go NeverExit(f)      // restart
	}()
	
	f()
}

func main() {
	go NeverExit(fA)
	go NeverExit(fB)
	select{}
}
