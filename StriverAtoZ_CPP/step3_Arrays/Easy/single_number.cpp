#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // optimal solution
        int x = 0;
        for (int i : nums) {
            x ^= i;
        }
        return x;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2, 2, 1};  
    int result = obj.singleNumber(nums);
    cout << "Single number is: " << result << endl;
    return 0;
}
