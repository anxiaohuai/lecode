#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

// 互斥量和条件变量用于线程同步
mutex mtx;
condition_variable cv;

int count = 0; // 用于记录当前已经打印的数
const int max_count = 20; // 最大打印数

void print_odd() {
    while (count < max_count) {
        unique_lock<mutex> lock(mtx);
        // 如果当前count是偶数，需要等待条件变量
        cv.wait(lock, []() { return (count % 2) == 1; });
        cout << "odd thread: " << count++ << endl;
        // 通知偶数线程
        cv.notify_one();
    }
}

void print_even() {
    while (count < max_count) {
        unique_lock<mutex> lock(mtx);
        // 如果当前count是奇数，需要等待条件变量
        cv.wait(lock, []() { return (count % 2) == 0; });
        cout << "even thread: " << count++ << endl;
        // 通知奇数线程
        cv.notify_one();
    }
}

int main() {
    thread t1(print_odd);
    thread t2(print_even);
    t1.join();
    t2.join();
    return 0;
}
