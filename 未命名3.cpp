#include<iostream>
#include<vector>

using namespace std;

int ss = 0;
vector<int> res(2);
vector<int> so(int n,vector<vector<int>>& fen){
	
	
//	vector<vector<int>> fen;
//	vector<int> fz;
//	for(int i = 0;i<n;++i){
//		if(shu[i] != 0){
//			fz.push_back(shu[i]);
//			if(i == n-1){
//				fen.push_back(fz);
//				break;
//			}
//		}else if(shu[i] == 0){
//			fen.push_back(fz);
//			fz.clear();
//		}else if(shu[i] == 0 && i == 0){
//			continue;
//		}
//	}
//	for(auto a:fen){
//		for(auto b:a){
//			cout<<b<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	for(auto a:fen){
		if(a.empty()){
			continue;
		}
		vector<int> qian;
		qian.push_back(a[0]);
		for(int i = 1;i<n;++i){
			qian.push_back(a[i]*qian[i-1]);
		}
		
		for(int i =0;i<n;++i){
			int l = 0,r = i;
			while(l<r){
				if(qian[l] == 0){
					l++;
					continue;
				}
				
				if(l == 0){
					if(qian[r] > ss){
						res[0] = l;
						res[1] = r;
						ss = qian[r];
					}
						l++;
						continue;
				}else if(l == r){
					if(a[r] > ss){
						res[0] = l;
						res[1] = r;
						ss = a[r];
						break;
					}
				}
				
				int t = qian[r] / qian[l];
				if(t>ss){
					res[0] = l;
					res[1] = r;
					ss = t;
				}
				l++;
			}
		}	
	}
	
	return res;
}

int main(){
	int n;
	cin>>n;
	vector<int> shu(n);
	
	for(int i = 0;i<n;++i){
		cin>>shu[i];
	}
	vector<int> res;
	
	
	vector<vector<int>> fen;
	vector<int> fz;
	for(int i = 0;i<n;++i){
		if(shu[i] != 0){
			fz.push_back(shu[i]);
			if(i == n-1){
				fen.push_back(fz);
				break;
			}
		}else if(shu[i] == 0){
			fen.push_back(fz);
			fz.clear();
		}else if(shu[i] == 0 && i == 0){
			continue;
		}
	}
	
	res = so(n,fen);
	
	for(auto a:res){
		cout<<a<<" ";
	}
	
}
