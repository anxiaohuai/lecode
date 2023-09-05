#include<iostream>
#include <thread>
#include <vector>
#include <functional>
#include <chrono>
using namespace std;

void mergeCount(vector<int> a,int L,int mid,int R) {
	int *tmp = new int[L+mid+R];
	int i=L;
	int j=mid+1;
	int k=0;
	while( i<=mid && j<=R ) {
		if(a[i] < a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	}
	while( i<=mid )
		tmp[k++] = a[i++];
	while( j<=R)
		tmp[k++] = a[j++];
	for(int p=0; p<k; ++p)
		a[L+p] = tmp[p];
	delete tmp;
}
void mergeSort(vector<int> a,int L,int R) {
	if( L>=R ) { return; }
	int mid = (R + L)/2;
	// mergeSort(a,L,mid);
	// mergeSort(a,mid+1,R);
	// mergeCount(a,L,mid,R);
	thread t1(std::bind(mergeSort,std::ref(a),L,mid));
    thread t2(std::bind(mergeSort,std::ref(a),mid+1,R));
    t1.join();
    t2.join();
    mergeCount(a,L,mid,R);
	
}

int main() {
	vector<int> a = {34,66,2,5,95,4,46,27,1}
	// vector<int> a;
	// for(int i = 0;i<100000000/2;++i){
	// 	a.push_back(i%501);
	// }
	// auto start = chrono::high_resolution_clock::now();
	mergeSort(a, 0, sizeof(a)/sizeof(int));
	// auto end = chrono::high_resolution_clock::now();
	// auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	// cout << "执行时间: " << duration.count() << " 微秒" << endl;
	for(int i=0; i<a.size(); ++i) {
		std::cout<<a[i]<<" "; // print => 0 2 4 5 27 34 46 66 95
	}
	return 0;
}
