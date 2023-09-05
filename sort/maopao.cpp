#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& arr, int size) {
    bool isSorted = false;
    for (int i = 0; i < size - 1; i++) {
        isSorted = true; // 假设数组已经有序
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j+1]
                std::swap(arr[j], arr[j + 1]);
                isSorted = false; // 如果有交换，则数组未有序
            }
        }
        if (isSorted) {
            // 数组已经有序，提前结束排序
            break;
        }
    }
}
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    bubbleSort(arr, arr.size());
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
