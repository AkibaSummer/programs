package main

import (
	"container/list"
	"log"
	"math/rand"
	"time"
)

const (
	_ = iota
	//SENDER type
	SENDER
	//RECEIVER type
	RECEIVER
)

const (
	// WIN max window size
	WIN = 4
)

//Frame struct of frame
type Frame struct {
	frameType string
	id        int
}

//PhysicalLayer struct of physical layer
type PhysicalLayer struct {
	RS, SR *list.List
}

func (phy PhysicalLayer) sendFrame(frame Frame, sender int) {
	time.Sleep(time.Duration(rand.Int31n(2000)) * time.Millisecond)
	if rand.Intn(10) == 0 { // 10% error
		frame.frameType = "ERR"
	}
	if sender == SENDER {
		if rand.Intn(10) == 0 { // 10% lost
			log.Println("Sender lost message ", frame)
			return
		}
		log.Println("Sender sent message ", frame)
		phy.SR.PushBack(frame)
	} else {
		if rand.Intn(10) == 0 { // 10% lost
			log.Println("Receiver lost message ", frame)
			return
		}
		log.Println("Receiver sent message ", frame)
		phy.RS.PushBack(frame)
	}
}

func (phy PhysicalLayer) hasFrame(receiver int) bool {
	if receiver == SENDER {
		return phy.RS.Len() > 0
	}
	return phy.SR.Len() > 0
}

func (phy PhysicalLayer) receiveFrame(receiver int) Frame {
	time.Sleep(time.Duration(rand.Int31n(500)) * time.Millisecond)
	if receiver == SENDER {
		front := phy.RS.Front()
		ret := front.Value.(Frame)
		log.Println("Sender received message ", ret)
		phy.RS.Remove(front)
		return ret
	}
	front := phy.SR.Front()
	ret := front.Value.(Frame)
	log.Println("Receiver received message ", ret)
	phy.SR.Remove(front)
	return ret
}

func sender(phy PhysicalLayer) {
	var s, swl int
	swl = 0
	for {
		s = swl
		for s < swl+WIN {
			phy.sendFrame(Frame{"MSG", s}, SENDER)
			s = s + 1
			if rand.Intn(3) == 0 { //not continue to send message
				break
			}
		}

		if phy.hasFrame(SENDER) {
			received := phy.receiveFrame(SENDER)
			if received.frameType == "ACK" {
				if swl <= received.id && received.id < swl+WIN {
					swl = received.id
				}
			}
		}
	}
}

func receiver(phy PhysicalLayer) {
	var es int
	es = 0
	for {
		if phy.hasFrame(RECEIVER) {
			received := phy.receiveFrame(RECEIVER)
			if received.frameType == "MSG" {
				if received.id == es {
					log.Println("Information ", es, " transmitted successfully")
					es = es + 1
				}
				phy.sendFrame(Frame{"ACK", es}, RECEIVER)
			} else {
				phy.sendFrame(Frame{"ACK", es}, RECEIVER)
			}
		}
	}
}

func main() {
	phy := PhysicalLayer{
		RS: list.New(),
		SR: list.New(),
	}
	go sender(phy)
	receiver(phy)
}
