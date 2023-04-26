#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	multimap<char,vector<int> > shu;
	for(int i = 0;i<n;++i){
		char c;
		cin>>c;
		if(c == 'b'){
			vector<int> v(1);
			cin>>v[0];
			shu.insert(make_pair(c,v));
		}else{
			vector<int> v(2);
			cin>>v[0]>>v[1];
			shu.insert(make_pair(c,v));
		}
	}
	
	for(auto a:shu){
		cout<< a.first<<" ";
		for(auto b:a.second){
			cout<<b;
		}
	}
	
}
/*
5 2
b 1
b 2
m 1 10
m 2 20
m 2 30

*/
