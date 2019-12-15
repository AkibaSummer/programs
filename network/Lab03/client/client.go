package main

import (
	"fmt"
	"log"
	"net"
)

func main() {
	fmt.Print("Please input target address and port:")
	var target string
	fmt.Scanln(&target)
	conn, err := net.Dial("tcp", target)
	if err != nil {
		log.Println("Connection error:", err)
		return
	}
	defer conn.Close()
	log.Println("dial ok")

	for {
		fmt.Print("Please input message length to send(type \"1\" to quit):")
		var message int
		fmt.Scanln(&message)
		var data []byte = make([]byte, message)
		for i, _ := range data {
			data[i] = 'a'
		}
		_, err = conn.Write(data)
		if err != nil {
			log.Println("Error to send: ", err)
			return
		} else {
			log.Println("Sent message length", len(data))
		}
		if message == 1 {
			log.Println("Connection closed")
			break
		}
	}
}
