#include<iostream>
#include<thread>
#include<mutex>

using namespace std;
mutex mtx;
int count = 0;
int maxx = 2000;
void print_a(){
	while(count<maxx){
		unique_lock<mutex> lock(mtx);
		if(count < maxx && count%2==1){
			cout<< count++ <<endl;
			lock.unlock();
		}else{
			lock.unlock();
		}
	}

}

void print_b(){
	while(count < maxx){
		unique_lock<mutex> lock(mtx);
		if(count < maxx && count%2==0){
			cout<< count++ <<endl;
			lock.unlock();
		}else{
			lock.unlock();
		}
	}
	
}


int main(){
	thread t1(print_a);
	thread t2(print_b);
	t1.join();
	t2.join();
}
