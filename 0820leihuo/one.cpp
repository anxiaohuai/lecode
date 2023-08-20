#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int a;
    cin>>a;
    vector<int> op(a);
    for(int i = 0;i<a;++i){
        cin>>op[i];
    }
    vector<string> res;
    int left = 1,right = 1000,target = op[a-1];
    for(int i = 0;i<a;++i){
        if(op[i] < target && op[i] > left){
            res.push_back("It's too small,please keep guessing!");
            left = op[i];
        }else if(op[i] > target && op[i] < right){
            res.push_back("It's too big,please keep guessing!");
            right = op[i];
        }else if(op[i] == target){
            res.push_back("Congratulations!You guessed it right!");
            break;
        }else if(op[i] <= left || op[i] >= target){
            res.push_back("Are you kidding me?");
        }
    }
    for(int i = 0;i<res.size();++i){
        // cout<<res[i]<<endl;
        printf("%lld\n",res[i]);
    }

    
}
// 64 位输出请用 printf("%lld")