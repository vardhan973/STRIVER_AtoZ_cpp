#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroesBrute(vector<int>& nums) {
        // Time complexity -> O(n^2)
        // Space complexity -> O(1)
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                for(int j = i + 1; j < n; j++) {
                    if(nums[j] != 0) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }

    void moveZeroesBetter(vector<int>& nums) {
        // Time complexity -> O(n)
        // Space complexity -> O(n)
        int n = nums.size();
        vector<int> temp;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) temp.push_back(nums[i]);
        }
        int index = 0;
        for(int x : temp) nums[index++] = x;
        while(index < n) nums[index++] = 0;
    }

    void moveZeroesOptimized(vector<int>& nums) {
        // Time complexity -> O(n)
        // Space complexity -> O(1)
        int j = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {0,1,0,3,12};
    vector<int> nums2 = {1,0,5,2,0,6,2,0};
    vector<int> nums3 = {3,0,0,6,7,0,2,0,6,2,0,6};

    sol.moveZeroesBrute(nums1);
    sol.moveZeroesBetter(nums2);
    sol.moveZeroesOptimized(nums3);

    cout << "Brute Force: ";
    for(int x : nums1) cout << x << " ";
    cout << endl;

    cout << "Better Approach: ";
    for(int x : nums2) cout << x << " ";
    cout << endl;

    cout << "Optimized Approach: ";
    for(int x : nums3) cout << x << " ";
    cout << endl;

    return 0;
}
