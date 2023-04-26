/*
归并 && 多线程归并 
*/

#include<iostream>
#include <thread>
#include <vector>
#include <functional>
using namespace std;

void mergeCount(int a[],int L,int mid,int R) {
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
	///判断哪个?数组中有剩余的数据
	while( i<=mid )
		tmp[k++] = a[i++];
	while( j<=R)
		tmp[k++] = a[j++];
	/// 将 tmp 中的数组拷?回 A[p...r]
	for(int p=0; p<k; ++p)
		a[L+p] = tmp[p];
	delete tmp;
}

void mergeSort(int a[],int L,int R) {
	if( L>=R ) { return; }
	int mid = L + (R - L)/2;
//	mergeSort(a,L,mid);
//	mergeSort(a,mid+1,R);
//	mergeCount(a,L,mid,R);
	thread t1(std::bind(mergeSort,std::ref(a),L,mid));
    thread t2(std::bind(mergeSort,std::ref(a),mid+1,R));
    t1.join();
    t2.join();
    mergeCount(a,L,mid,R);
	
}

int main() {
	int a[] = {0,34,66,2,5,95,4,46,27};
	mergeSort(a, 0, sizeof(a)/sizeof(int));
	for(int i=0; i<=8; ++i) {
		std::cout<<a[i]<<" "; // print => 0 2 4 5 27 34 46 66 95
	}
	std::cout<<endl;
	return 0;
}
