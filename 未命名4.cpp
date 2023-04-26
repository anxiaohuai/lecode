#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

// ���������������������߳�ͬ��
mutex mtx;
condition_variable cv;

int count = 0; // ���ڼ�¼��ǰ�Ѿ���ӡ����
const int max_count = 20; // ����ӡ��

void print_odd() {
    while (count < max_count) {
        unique_lock<mutex> lock(mtx);
        // �����ǰcount��ż������Ҫ�ȴ���������
        cv.wait(lock, []() { return (count % 2) == 1; });
        cout << "odd thread: " << count++ << endl;
        // ֪ͨż���߳�
        cv.notify_one();
    }
}

void print_even() {
    while (count < max_count) {
        unique_lock<mutex> lock(mtx);
        // �����ǰcount����������Ҫ�ȴ���������
        cv.wait(lock, []() { return (count % 2) == 0; });
        cout << "even thread: " << count++ << endl;
        // ֪ͨ�����߳�
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
