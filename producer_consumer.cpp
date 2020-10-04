#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

#define BUFF_SIZE 25

std::mutex mtx;
std::condition_variable cv;
std::queue<int> buffer;

unsigned int to_produce = 30;

void producer(int val) {
    while(val) {
        {
            std::unique_lock<std::mutex> lock(mtx); // try and acquire the mutex
            // release the mutex if `buffer` size is > `BUFF_SIZE`
            // if `buffer` size is <= `BUFF_SIZE`, produce more!
            cv.wait(lock, []() {
                return buffer.size() <= BUFF_SIZE;
            });
            std::cout << "Produced: " << val << std::endl;
            buffer.push(val);
            val--;
        }
        cv.notify_all();
    }
}

void consumer() {
    while (to_produce)
    {
        std::unique_lock<std::mutex> lock(mtx); // acquire the lock
        cv.wait(lock, []() {
            return buffer.size() > 0; // ONLY move forward when you can read from buffer
                                      // otherwise, release the lock.
        });
        std::cout << "Consumed: " << buffer.front() << std::endl;
        buffer.pop();
        to_produce--;
        cv.notify_all();
    }
}

int main(int argc, char const *argv[])
{
    std::thread t1(producer, to_produce);
    std::thread t2(consumer);

    t1.join();
    t2.join();
    return 0;
}
