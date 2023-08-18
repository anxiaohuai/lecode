#include <iostream>
#include <vector>
#include <list>
#include <deque>


using namespace std;

int main() {
    vector<int> testv;
    testv.shrink_to_fit();
    cout<<testv.size()<<endl;
    cout<<testv.capacity()<<endl;
    cout<<sizeof(testv)<<endl;
    cout<<sizeof(int)<<endl;
    cout<<sizeof(int*)<<endl;
    cout<<"-=-------------------------"<<endl;
    list<int> testl;
    cout<<sizeof(testl)<<endl;
    deque<int> testd;
    cout<<sizeof(testd)<<endl;;     
}
