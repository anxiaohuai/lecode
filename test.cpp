#include <iostream>
#include <cmath>

int maxNumbersInSet(int a, int d, int n) {
    int x = ceil(static_cast<double>(n - (a % 2)) / 2);
    return 2 * x;
}

int main() {
    int a, d, n;
    std::cout << "请输入等差数列的首项a、公差d和长度n：" << std::endl;
    std::cin >> a >> d >> n;
    
    int result = maxNumbersInSet(a, d, n);
    
    std::cout << "最多能有 " << result << " 个数在集合中。" << std::endl;
    
    return 0;
}
