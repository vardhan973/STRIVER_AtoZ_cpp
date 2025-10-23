#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateBruteForce(vector<int>& nums, int k) {
        // Time complexity -> O(n*k)
        // Space complexity -> O(1)
        int n = nums.size();
        k = k % n;
        for (int i = 0; i < k; i++) {
            int last = nums[n - 1];
            for (int j = n - 1; j > 0; j--) {
                nums[j] = nums[j - 1];
            }
            nums[0] = last;
        }
    }

    void rotateBetterApproach(vector<int>& nums, int k) {
        // Time complexity -> O(n)
        // Space complexity -> O(n)
        int n = nums.size();
        k = k % n;
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;
    }

    void rotateReversal(vector<int>& nums, int k) {
        // Time complexity -> O(n)
        // Space complexity -> O(1)
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    sol.rotateBruteForce(nums, k);
    for (int x : nums) cout << x << " ";
    cout << endl;

    nums = {1, 2, 3, 4, 5, 6, 7};
    sol.rotateBetterApproach(nums, k);
    for (int x : nums) cout << x << " ";
    cout << endl;

    nums = {1, 2, 3, 4, 5, 6, 7};
    sol.rotateReversal(nums, k);
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}
