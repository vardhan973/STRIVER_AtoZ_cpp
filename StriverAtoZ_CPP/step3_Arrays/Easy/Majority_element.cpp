#include <bits/stdc++.h>
using namespace std;

int majorityElementBrute(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) {
                count++;
            }
        }
        if (count > n / 2) {
            return nums[i];
        }
    }
    return -1;
}

int majorityElementBetter(vector<int>& nums) {
    unordered_map<int, int> mpp;
    int n = nums.size();
    for (int x : nums) {
        mpp[x]++;
    }
    for (auto& p : mpp) {
        if (p.second > n / 2) {
            return p.first;
        }
    }
    return -1;
}

int majorityElementOptimal(vector<int>& nums) {
    int el;
    int count = 0;
    for (int x : nums) {
        if (count == 0) {
            el = x;
        }
        if (x == el) {
            count++;
        } else {
            count--;
        }
    }
    int c = 0;
    for (int x : nums) {
        if (x == el) {
            c++;
        }
    }
    if (c > nums.size() / 2) {
        return el;
    }
    return -1;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    vector<int> nums1 = nums;
    vector<int> nums2 = nums;
    vector<int> nums3 = nums;

    majorityElementBrute(nums1);
    majorityElementBetter(nums2);
    majorityElementOptimal(nums3);

    return 0;
}
