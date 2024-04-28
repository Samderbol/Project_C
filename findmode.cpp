#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

class Solution {

public:
     static int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        // maxNum 表示元素，maxCount 表示元素出现的次数
        int maxNum = 0, maxCount = 0;
        for (int num: nums) {
            int count = ++map[num];
            if (count > maxCount) {
                maxCount = count;
                maxNum = num;
            }
        }
        return maxNum;
    }
};

int main() {
    vector<int> test = {1, 1, 2, 2, 4, 2, 2,4,4,4,4};
   int maxNum = Solution::majorityElement(test);
    cout << "maxNum:" << maxNum << endl;
    return 0;
}