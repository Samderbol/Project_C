#include <iostream>
#include <vector>
#include <algorithm>

int findSmallestMissingPositive(std::vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        if (nums[i] <= 0 || nums[i] > n) {
            nums[i] = 0;
        }
    }//替换负数为0

    for (int i = 0; i < n; ++i) {
        int num = std::abs(nums[i]);
        if (num > 0 && num <= n) {
            if (nums[num - 1] > 0) {//防止重复标记
                nums[num - 1] = -nums[num - 1]; //
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {
    std::vector<int> nums1 = {-5, 1, 4, 3};
    std::cout << "最小未出现的整数是: " << findSmallestMissingPositive(nums1) << std::endl;


    return 0;
}
