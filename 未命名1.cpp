#include<iostream>
#include<set>
#include<unordered_set>
#include<typeinfo>
#include<map>

using namespace std;
int main(){
//	set<int> s;
//	s.insert(1);
//	s.insert(3);
//	s.insert(2);
//	s.insert(5);
//	s.insert(10);
//	s.insert(8);
//	s.insert(7);
//	s.insert(9);
//	for(auto a:s){
//		cout<<a<<" ";
//	}
//	cout<<endl;
//	cout<<typeid(s.insert(9)).name()<<"----";
//	cout<<endl;
//	
//	for(auto a:s){
//		cout<<a<<" ";
//	}

//	unordered_set<int> s;
//	s.insert(1);
//	s.insert(3);
//	s.insert(1);
//	s.insert(5);
//	s.insert(10);
//	s.insert(8);
//	s.insert(7);
//	s.insert(9);
//	for(auto a:s){
//		cout<<a<<" ";
//	}
//	cout<<endl;
////	cout<<typeid(s.insert(9)).name()<<"----";
//	cout<<endl;
//	
//	for(auto a:s){
//		cout<<a<<" ";
//	}

	map<int,int> s;
	
	s.insert(make_pair(1,1));
	s.insert(make_pair(3,3));
	s.insert(make_pair(4,4));
	s.insert(make_pair(5,5));
	s.insert(make_pair(10,10));
	s.insert(make_pair(8,8));
	s.insert(make_pair(9,9));
	s.insert(make_pair(7,7));
	for(auto a:s){
		cout<<a.first<<":"<<a.second<<" ";
	}
	cout<<endl;
	cout<<s.size()<<endl;
	s[0] = 156;
	(*s.begin()).second = 258;
	cout<<s[0]<<endl;
	cout<<endl;
	cout<<s.size()<<endl;
//	cout<<typeid(s.insert(9)).name()<<"----";
	cout<<endl;
	
//	for(auto a:s){
//		cout<<a<<" ";
//	}

}
