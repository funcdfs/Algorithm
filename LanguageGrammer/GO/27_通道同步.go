package main

import (
    "fmt"
    "time"
)

func worker(done chan bool) {
    fmt.Print("working...")
    time.Sleep(time.Second)
    fmt.Println("done")

    done <- true
}

func main_通道同步() {

    done := make(chan bool, 1)
    go worker(done)

    <-done
}

// 程序将一直阻塞，直至收到 worker 使用通道发送的通知。

