#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Time complexity -> O(n)
        // Space complexity -> O(1)
        int k = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] != nums[i]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};
    int k = sol.removeDuplicates(nums);

    cout << "k = " << k << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
