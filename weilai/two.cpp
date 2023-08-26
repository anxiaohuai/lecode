#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main() {
    int k;
    cin>>k;
    string str;
    cin>>str;
    string res;
    string tmp;
    string hou = str;
    vector<string> vs(a.size()+1,a);
    for(int i = 0;i<;++i)
    for(int k = 1;k<str.size();++k){
        if(str.substr(0,k) == str.substr(str.size()-k,k)){
            cout<<"k = "<<k<<"   "<<str.substr(0,k)<<"   "<<str.substr(str.size()-k,k)<<endl;
            tmp = str.substr(0,k);
            hou = str.substr(k,str.size()-k);
            break;
        }
    }
    
    res = str;
    cout<<"111"<<hou<<endl;
    cout<<" 222"<<tmp<<endl;
    for(int i = 0;i<k-1;++i){
        res+=hou;
    }
    cout<<res;
    

}
// 64 位输出请用 printf("%lld")