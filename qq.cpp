#include <iostream>
#include <vector>
#include <string>
using namespace std;

    string red = "red";
    bool isa(string str){
        bool flag = false;
        bool f1 = false,f2=false,f3 = false;
        int a=0,b=0,c=0;
        for(int i = 0;i<str.size();++i){
            if(str[i] == 'r'){
                f1 = true;
                a = min(i,a);
            }else if(str[i] == 'd'){
                f3 = true;
                c = max(c,i);
            }else{
            }
        }
        for(int i = a;i<=c;++i){
            if(str[i] == 'e' && c-a >2){
                flag = true;
            }
        }
        return flag;
    }

    int di(string str,int& n, int& r){
        if(str.size()>=n){
            return r;
        }
        for(int i = 0;i<3;++i){
            string tmp = str+red[i];
            if(tmp.size()<=3){
                r = di(tmp,n,r);
                continue;
            }else if(tmp.substr(tmp.size()-3,3) == "red"){
                r = di(tmp,n,r);
                continue;
            }else if(tmp.substr(tmp.size()-3,3) != "red" && isa(tmp)){
                int it = r+1;
                r = di(tmp,n,it);
                continue;
            }
        }
        cout<<"aaaaaaaaaaaaaaaaa"<<endl;
        return r;
    }
    int kawaiiStrings(int n) {
        // write code here
        int res = 0;
        int MOD = 1000000007;
        if(n<=3) return 0;
        vector<int> dp(n+1,0);
        int s1 = 0,s2 = 0,s3 = 0;
        int a = di("r",n,s1);
        int b = di("e",n,s2);
        int c = di("d",n,s3);
        res = (a+b+c) % MOD;
        return res;
    }
    int main(){
        int n = 4;
        int rr = kawaiiStrings(n);
        cout<<rr<<endl;
    }
