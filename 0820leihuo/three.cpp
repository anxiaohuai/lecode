#include <iostream>
#include <vector>
#include <string>

using namespace std;
// 6 6 1 2
// 1 1
// 2 2 3
// 5 3 3 3 4 2
// 3 4 5 6
// 1 1
// 1 2

class Team{
public:
    int id,size;
    bool hasA,hasB;
    Team(int id,int size,bool hasA,bool hasB) :id(id),size(size),hasA(hasA),hasB(hasB){}
};
int n,m,a,b;
bool backtrack(int& idx, int& cursize,bool& incA,bool& incB,vector<int>& res1, vector<bool>& flag,vector<Team>& teams){
    if(cursize == m && incA && incB){
        return true;
    }
    // cout<<idx<<"--"<<endl;
    if(idx >= n) return false;
    Team team = teams[idx];
    if(cursize + team.size <= m){
        // cout<<"t1 "<<cursize + team.size<<endl;
        if(((!incA && team.hasA) || (!incB && team.hasB) || (!team.hasA && !team.hasB)) && flag[idx] == false){
            res1.push_back(team.id);
            flag[idx] = true;
            int idt = idx+1;
            int st = cursize+team.size;
            bool ba = incA || team.hasA;
            bool bb = incB || team.hasB;
            if(backtrack(idt,st,ba,bb,res1,flag,teams)){
                return true;
            }
            res1.pop_back();
            flag[idx] = false;
        }
    }else{
        int idt = idx+1;
        return backtrack(idt,cursize,incA,incB,res1,flag,teams);
    }
    return false;
    
    // return false;
}

int main() {

    cin>>n>>m>>a>>b;
    vector<Team> teams;
    vector<int> res1;
    vector<int> res2;
    vector<vector<int>> res;
    int l1,l2;
    string line;
    vector<bool> flag(n,false);
    for(int i  = 1;i <= n;++i){
        int t;
        cin>>t;
        bool hasA = false,hasB = false;
        for(int j = 0;j<t;++j){
            int prof;
            cin>>prof;
            if(prof == a) hasA = true;
            if(prof == b) hasB = true;
        }
        teams.push_back(Team(i,t,hasA,hasB));
    }
    // int a1 =0,b1 = 0,c1 = 0,d1 = 0;
    // bool aa1 = false,bb1 = false,cc1=false,dd1=false;
    for(int i = 0;i<n;++i){
        vector<int> tmp;
        int a1 =i,b1 = 0,c1 = 0,d1 = 0;
        bool aa1 = false,bb1 = false,cc1=false,dd1=false;
        if(backtrack(a1,b1,aa1,bb1,tmp,flag,teams)){
            res.push_back(tmp);
        }

    }

    if(res.size() == 0 || a==b || n<1||n>1000 || m<6||m>24 || a<1||a>8||b<1||b>8){
        return 0;
    }

    for(int i = 0;i<res.size();++i){
        for(int j = 0;j<res[i].size();++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }


}
