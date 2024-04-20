#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

// Function to check if the array is sorted
bool is_sorted(const std::vector<int>& arr) {
    return std::is_sorted(arr.begin(), arr.end());
}

// Function to perform bogosort
void bogosort(std::vector<int>& arr) {
    while (!is_sorted(arr)) {
        std::random_shuffle(arr.begin(), arr.end());
    }
}

int main() {
    std::cout << "Enter the number of elements: ";
    int size;
    std::cin >> size;

    std::vector<int> arr(size);
    std::cout << "Enter " << size << " numbers separated by spaces: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    bogosort(arr);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
