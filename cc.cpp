#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> fu(n-1);
    for(int i = 0;i<n-1;++i){
        cin>>fu[i];
    }
    vector<int> se(n);
    for(int i = 0;i<n;++i){
        cin>>se[i];
    }
    int MOD = 1000000007;
    int res = 0;
    vector<int> val(n,1);
    for(int i = n-1;i>0;i-=2){
        if(se[fu[i]] == 1)
            val[fu[i]] = val[i] + val[i-1];
        else
            val[fu[i]] = val[i] * val[i-1];
        // --i;
    }
    if(val[0] == 1){
        res = val[1] + val[2];
    }else{
        res = val[1] * val[2];
    }
    // for(auto a:val)
    //     cout<<a<<" ";
    
    
    cout<<res % MOD;
}