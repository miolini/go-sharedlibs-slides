package main

import "math/rand"
import "log"
import "time"
import "C"

//export RandN
func RandN(n int64) int64 {
	return rand.Int63n(n)
}

func init() {
	rand.Seed(time.Now().UnixNano())
}

func main() {
	log.Printf("Hello, World")
}