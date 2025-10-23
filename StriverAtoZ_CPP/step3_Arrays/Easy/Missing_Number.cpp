#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // TC -> O(n)
        // SC -> O(1)
        int n = nums.size();
        int ans = (n * (n + 1)) / 2;
        for(int i : nums){
            ans -= i;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 0, 1};
    int missing = sol.missingNumber(nums);
    cout << "Missing number is: " << missing << endl;
    return 0;
}
