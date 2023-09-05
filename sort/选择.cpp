#include <iostream>
#include <vector>
void selectionSort(std::vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}
int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(arr);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
