#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> op(n);
    map<string,bool> flag;
    for(int i = 0;i<n;++i){
        cin>>op[i];
        flag[op[i]] = false;
    }

    int res = 0;
    map<string,int> mp;
    for(int i = 0;i<n;++i){
        if(mp.find(op[i]) == mp.end()){
            mp.insert(pair<string,int>(op[i],1));
            if(mp[op[i]] > res && flag[op[i]] == false){
                res++;
                flag[op[i]] = true;
            }else{
                // cout<<op[i]<<" m = "<<mp[op[i]]<<"  "<<endl;
            }
        }else{
            mp[op[i]]++;
            if(mp[op[i]] > res && flag[op[i]] == false){
                res++;
                flag[op[i]] = true;
                // cout<<"fir "<<mp[op[i]]<<endl;
                // mp.erase(op[i]);
            }else{
                // mp[op[i]]++;
                // cout<<op[i]<<" m = "<<mp[op[i]]<<"  "<<endl;
            }
        }
    }
    cout<<res;

}