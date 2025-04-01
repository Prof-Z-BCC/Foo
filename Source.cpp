#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

void radixSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int max_num = *max_element(arr.begin(), arr.end());
    int max_digits = static_cast<int>(log10(max_num) + 1);

    std::vector<std::queue<int>> queues(10);

    for (int digit = 0; digit < max_digits; digit++) {
        for (int num : arr) {
            int dig_val = (num / static_cast<int>(pow(10, digit))) % 10;
            queues[dig_val].push(num);
        }

        int index = 0;
        for (auto& queue : queues) {
            while (!queue.empty()) {
                arr[index++] = queue.front();
                queue.pop();
            }
        }
    }
}

int main()
{
    std::vector<int> arr{ 170, 245, 315, 174, 326, 32, 17, 26 };
    radixSort(arr);

    std::cout << "Sorted" << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    return 0;
}