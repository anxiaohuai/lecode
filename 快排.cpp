#include<vector>
#include<iostream>

using namespace std;

void quick(vector<int>& a,int le,int ri){
	if(le + 1>= ri) return;
	
	int key = a[le],first = le,last = ri-1;
	while(first < last){
		while(a[last] >= key && first < last){
			last--;
		}
		a[first] = a[last];
		while(a[first] <= key &&first < last){
			first++;
		}
		a[last] =  a[first];
	}
	
	a[first] = key;
	quick(a,le,first);
	quick(a,first+1,ri);
	
}


int main(){
	vector<int> a = {2,7,3,4,1,0,5,67,23,534,32,12};
	quick(a,0,a.size());
	for(auto s:a){
		cout<<s<<" ";
	}
}
