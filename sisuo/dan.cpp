#include <iostream>
#include <mutex>
std::mutex mtx;
void func(int n) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Locked mutex, n = " << n << std::endl;
    if (n > 0) {
        func(n - 1);
    }
}
int main() {
    func(5);
    return 0;
}