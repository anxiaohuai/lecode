#include <iostream>
#include <string>
using namespace std;

int findBitBlockCountAndPosition(int num,int& p) {
    std::string binaryStr = "";
    while (num > 0) {
        binaryStr = std::to_string(num % 2) + binaryStr;
        num /= 2;
    }

    std::string targetBlock = "101";
    int count = 0;
    int position = -1;
    int index = 0;

    while (index < binaryStr.length()) {
        index = binaryStr.find(targetBlock, index);
        if (index != std::string::npos) {
            count++;
            if (position == -1) {
                position = index;
            }
            p = index+2;
            index++;
        }
    }
    p = binaryStr.size() - p - 1;

    return count * (position != -1); // 如果没有找到块，则次数为0，否则为count
}

int main() {
    int inputNum;
    std::cin >> inputNum;
    int p = -1;

    int count = findBitBlockCountAndPosition(inputNum,p);

    std::cout << count << " " << p << std::endl;

    return 0;
}
