#include<vector>
#include<iostream>
#include<deque>
#include<unordered_set>

using namespace std;

int main(){
	int start, end;
	cin>>start>>end;
	int n;
	cin>>n;
	vector<vector<int>> cao(n,vector<int>(2));
	for(int i = 0;i<n;++i){
		cin>>cao[i][0]>>cao[i][1];
	}
	
	int res = 0;
	
	deque<int> free;
	map<int,bool> mp;
	
	for(int i = start;i<=end;++i){
		free.push_back(i);
		mp[i] = true;
	}
	for(int i = 0;i<n;++i){
		int op = cao[i][0];
		int id = cao[i][1];
		if(op == 1){
			for(int j = 0;j<id;++j){
				int tmp = free.front();
				mp[tmp] = false; 
				free.pop_front();
			}
		}else if(op == 2){
			for(auto it = free.begin();it!=free.end();++it){
				if(*it == id){
					free.erase(it);
					break;
				}
			}
			mp[tmp] = false;
		}else{
			free.push_back(id);

		}
	}
	cout<<free[0];
}



/*
1 3
3
2 2
3 2
1 1

1 3
2
1 1
3 1


*/
