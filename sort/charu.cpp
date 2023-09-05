#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int>& arr, int size) {
    int i, j;
	for (i = 1; i < size; i++) {
		int temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int size = arr.size();
    insertionSort(arr, size);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
