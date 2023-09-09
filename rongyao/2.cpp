#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;

int calculateVoiceCost(int duration, int rate) {
    int cost = 0;
    int tmpduration = duration - 60;
    bool flag = false;
    if(duration % 60 == 0) flag = true;

    if(flag){
         if (duration <= 60) {
            cost = 0; // 第1分钟免费
        }else if (duration <= 300) {
            cost = std::ceil((duration - 60) / 60 * rate * 1.5/10); // 2-5分钟按150%收费
        } else if (duration <= 600) {
            cost = std::ceil((duration - 300) / 60 * rate/10) + 120; // 6-10分钟按基础费率收费
        } else if (duration <= 1200) {
            cost = std::ceil((duration - 600) / 60 * rate * 0.5/10) + 220; // 11-20分钟按50%收费
        } else {
            cost = std::ceil(((duration - 1200) / 60) * rate * 0.2 / 10) + 320; // 21分钟及之后按20%收费
            cout<<duration<<endl;
        }
    }else{
        if (duration <= 60) {
            cost = 0; // 第1分钟免费
        }else if (duration <= 300) {
            cost = std::ceil(((duration - 60) / 60 +1)* rate * 1.5 /10); // 2-5分钟按150%收费
        } else if (duration <= 600) {
            cost = std::ceil(((duration - 300) / 60 +1)* rate / 10) + 120; // 6-10分钟按基础费率收费
        } else if (duration <= 1200) {
            cost = std::ceil(((duration - 600) / 60 +1)* rate * 0.5 / 10) + 220; // 11-20分钟按50%收费
        } else {
            cost = std::ceil((((duration - 1200) / 60) +1)* rate * 0.2 / 10) + 320; // 21分钟及之后按20%收费
            cout<<duration<<endl;
        }
    }

    return cost;
}
// 13666666666|1801|200|807936|3

int calculateDataCost(int usage, int rate) {
    int cost = 0;
    if(usage <= 100 * 1024){
        cost = usage * rate / 100;
    }else if (usage <= 125 * 1024) {
        cost = 100 * 1024 * rate / 100; 
    } else if (usage <= 225 * 1024) {
        cost = std::ceil((usage - 125 * 1024) * rate / 100) + 100 * 1024 * rate / 100; 
    }else if(usage <= 325 * 1024){
        cost = 200 * 1024 * rate / 100; 
    }else if(usage <= 625 * 1024)
    {
        cost = (usage - 325 * 1024) * rate / 100 + 200 * 1024 * rate / 100;
    }else if(usage <= 725 * 1024){
        cost = 500 * 1024 * rate / 100;
    }else
    {
        int n = (usage - 725*1024) / 200 / 1024;
        int yu = (usage - 500*1024) %(200 * 1024);
        if(yu == 0){
            cost = 500 * 1024 * rate / 100 + n*100*1024*rate/100;
        }else if(yu >= 100){
            cost = 500 * 1024 * rate / 100 + (n+1)*100*1024*rate/100;
        }else if(yu<100){
            cost = 500 * 1024 * rate / 100 + (n)*100*1024*rate/100 + yu*1024*rate/100;
        }
    }
    return cost;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    std::string phoneNumber;
    std::string tokn;
    vector<int> vd(4);

    std::getline(ss, phoneNumber, '|');
    int i = 0;
    while(std::getline(ss,tokn , '|')){
        vd[i] = stoi(tokn);
        i++;
    }
    int voiceDuration = vd[0], voiceRate = vd[1], dataUsage = vd[2], dataRate = vd[3];
    // cout<<phoneNumber<<" "<<vd[0]<<" "<<vd[1]<<" "<<vd[2]<<" "<<vd[3]<<endl;

    int voiceCost = calculateVoiceCost(voiceDuration, voiceRate);
    int dataCost = calculateDataCost(dataUsage, dataRate);

    int totalCost = voiceCost + dataCost;
    // std::cout<<voiceCost<<" "<<dataCost<<std::endl;
    std::cout << totalCost << std::endl;

    return 0;
}
