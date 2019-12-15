package main

import (
	"fmt"
	"log"
	"net"
)

func handleConn(c net.Conn) {
	defer c.Close()
	log.Println("Linked ip:", c.RemoteAddr().String())
	for {
		data := make([]byte, 32768)
		len, err := c.Read(data)
		if err != nil {
			log.Println("Error to read message because of ", err)
			return
		}
		var str string = string(data[:len])
		log.Println("Received message length:", len)
		if str == "a" {
			log.Println("Connection from ", c.RemoteAddr().String(), " closed")
			return
		}
	}
}

func main() {
	fmt.Print("Please input port to listen:")
	var port string
	fmt.Scanln(&port)
	l, err := net.Listen("tcp", ":"+port)
	if err != nil {
		log.Println("error listen:", err)
		return
	}
	defer l.Close()
	log.Println("listen ok")

	for {
		c, err := l.Accept()
		if err != nil {
			log.Println("accept error:", err)
			return
		}
		go handleConn(c)
	}
}
