#include<iostream>
using namespace std;
void Heapify(int a[], int n, int i) {
	while (1) {
		int maxPos = i;
		if (i*2 <= n && a[i] < a[i*2]) { maxPos = i*2; }
		if (i*2+1 <= n && a[maxPos] < a[i*2+1]) { maxPos = i*2+1; }
		if (maxPos == i) break;
		std::swap(a[i], a[maxPos]);
		i = maxPos;
	}
}
void HeapSort(int a[], int n) {
	for(int i=n/2; i>0; --i) {
		Heapify(a, n, i);
	}
	int k = n;
	while( k > 1) {
		swap(a[1],a[k]);
		--k;
		Heapify(a,k,1);
	}
}
int main() {
	int a[] = {0,34,66,2,5,95,4,46,27};
	HeapSort(a,sizeof(a)/sizeof(int));
	for(int i=0; i<=8; ++i) {
		std::cout<<a[i]<<" "; // print => 0 2 4 5 27 34 46 66 95
	}
	std::cout<<endl;
	return 0;
}
