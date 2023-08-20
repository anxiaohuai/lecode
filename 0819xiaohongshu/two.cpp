#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;


bool so(string str,set<char> se){
    bool res = false;
    int left = 0;
    int len = str.size();
    int right = len - 1;
    while(left < right){
        if(se.find(str[left]) == se.end() && se.find(str[right]) == se.end() && str[left] != str[right]){
            return false;
        }else if(str[left] == str[right]){
            left++;
            right--;
            continue;
        }else if((se.find(str[left]) != se.end() ||  se.find(str[right]) != se.end()) && str[left] != str[right]){
            if(str[left] == 'w' && str[right] == 'v'){
                str[left] = 'v';
                right--;
            }else if(str[right] == 'w' && str[left] == 'v'){
                str[right] = 'v';
                left++;
            }else if(str[left] == 'm' && str[right] == 'n'){
                str[left] = 'n';
                right--;
            }else if(str[right] == 'm' && str[left] == 'n'){
                str[right] = 'n';
                left++;
            }else if( (str[left] == 'b' && (str[right] == 'd' || str[right] == 'q' || str[right] == 'p')) || (str[left] == 'd' && (str[left] == 'b' || str[left] == 'q' || str[right] == 'p')) || (str[left] == 'q' && (str[right] == 'd' || str[right] == 'b' || str[right] == 'p')) || (str[left] == 'p' && (str[right] == 'd' || str[right] == 'b' || str[right] == 'q'))){
                left++;
                right--;
            }else if((str[left] == 'n' && str[right] == 'u') || (str[left] == 'u' && str[right] == 'n')){
                left++;
                right--;
            }else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    vector<string> res;
    set<char> se = {'w','b','d','q','n','v','m','p'};
    for(int i = 0 ;i<t;++i){
        string str;
        cin>>str;
        if(so(str,se)){
            res.push_back("YES");
        }else{
            res.push_back("NO");
        }
    }
    for(int i = 0;i<t;++i){
        cout<<res[i]<<endl;
    }
}