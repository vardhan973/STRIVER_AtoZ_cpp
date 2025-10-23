#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        // TC -> O(n)
        // SC -> O(1)
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n])
                count++;
            if (count > 1)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << (sol.check(nums) ? "true" : "false");
    return 0;
}
