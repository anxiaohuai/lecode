#include<iostream>
#include<vector>

using namespace std;
int HoareSort(vector<int>& a, int begain, int end)
{
	int key = begain;
	int left = begain, right = end;
	while (left < right)
	{
		while (left < right && a[right] >= a[key])
			right--;
		while (left < right && a[left] <= a[key])
			left++;
		swap(a[right], a[left]);
	}
	int meeti = left;
	swap(a[meeti], a[key]);
	return meeti;
}
void QuickSort(vector<int>& a, int begain, int end)
{
	if (begain >= end)
		return;
	int meeti = HoareSort(a, begain, end);
	QuickSort(a, begain, meeti - 1);
	QuickSort(a, meeti + 1, end);
}
int main(){
	vector<int> shuru = {3,9,4,2,1,6,4,12,43,65,21,0,8,7,5};
	QuickSort(shuru,0,shuru.size()-1);
	for(auto a:shuru){
		cout<<a<<" ";
	}
}
