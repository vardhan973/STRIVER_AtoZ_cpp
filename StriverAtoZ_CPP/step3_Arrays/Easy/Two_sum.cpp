#include <bits/stdc++.h>
using namespace std;

vector<int> twoSumBrute(vector<int>& nums, int target) {
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

vector<int> twoSumBetter(vector<int>& nums, int target) {
    vector<pair<int, int>> arr;
    for(int i = 0; i < nums.size(); i++) {
        arr.push_back({nums[i], i});
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = arr.size() - 1;
    while(l < r) {
        int sum = arr[l].first + arr[r].first;
        if(sum == target) return {arr[l].second, arr[r].second};
        else if(sum < target) l++;
        else r--;
    }
    return {-1, -1};
}

vector<int> twoSumOptimal(vector<int>& nums, int target) {
    unordered_map<int, int> mpp;
    for(int i = 0; i < nums.size(); i++) {
        int rem = target - nums[i];
        if(mpp.count(rem)) return {mpp[rem], i};
        mpp[nums[i]] = i;
    }
    return {-1, -1};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans1 = twoSumBrute(nums, target);
    vector<int> ans2 = twoSumBetter(nums, target);
    vector<int> ans3 = twoSumOptimal(nums, target);

    return 0;
}
