#include <thread>
#include <iostream>
#include <assert.h>
using namespace std;

static thread_local int i = 0;

int main() {
    auto th = std::thread([]{
        i = 1;
    });
    th.join();
    cout<<i<<endl;
    
    assert(i == 0);
}