package main

import (
    "fmt"
    "time"
)

func f(from string) {
    for i := 0; i < 3; i++ {
        fmt.Println(from, ":", i)
    }
}

func main_1() {

    f("direct") // 同步调用 f 函数 

    go f("goroutine")
    // 使用 go f(s) 在一个协程中调用这个函数。 这个新的 Go 协程将会 并发地 执行这个函数。

    go func(msg string) {
        fmt.Println(msg)
    }("going")
    // 你也可以为匿名函数启动一个协程。

    time.Sleep(time.Second)
    fmt.Println("done")
    // 现在两个协程在独立的协程中 异步地 运行， 然后等待两个协程完成（更好的方法是使用 WaitGroup）。
}

// Go runtime 是以并发的方式运行协程的。
