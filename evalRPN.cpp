#include <iostream>
#include <stack>
#include <string>
using namespace std;
//driver code
class Solution {
public:
    static int evalRPN(vector<string> &tokens) {
        stack<int> nums;
        int n = (int) tokens.size();
        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                if (tokens[i] == "+") nums.push(num1 + num2);
                if (tokens[i] == "-") nums.push(num1 - num2);
                if (tokens[i] == "*") nums.push(num1 * num2);
                if (tokens[i] == "/") nums.push(num1 / num2);
            } else
                nums.push(std::stoi(tokens[i]));
        }
        return nums.top();
    }
};

int main() {
    vector<string> test = {"2", "1", "+", "3", "*"};


    // Function call
    int eval = Solution::evalRPN(test);
    cout << eval << endl;

    return 0;
}