package main

import "fmt"
import "github.com/miolini/dl"

func main() {
	lib, err := dl.Open("librandn.so", 0)
	if err != nil {
		panic(err)
	}
	defer lib.Close()
	var randn func(int64) int64
	if err := lib.Sym("RandN", &randn); err != nil {
		panic(err)
	}
	fmt.Printf("randn(100) = %d\n", randn(100))
}