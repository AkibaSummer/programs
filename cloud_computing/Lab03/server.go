package main

import (
	"fmt"
	"net/http"
)

var id string

func myWeb(w http.ResponseWriter, r *http.Request) {
	fmt.Fprint(w, "<h1>This is a server in docker. </h1>\n")
}

func main() {
	http.HandleFunc("/", myWeb)
	fmt.Println("Server started.")

	err := http.ListenAndServe(":8080", nil)
	if err != nil {
		fmt.Println("Server error: ", err)
	}
}
