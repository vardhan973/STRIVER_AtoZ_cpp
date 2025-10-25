#include <bits/stdc++.h>
using namespace std;

void sortColorsBrute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}

void sortColorsBetter(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0;
    for (int x : nums) {
        if (x == 0) count0++;
        else if (x == 1) count1++;
        else count2++;
    }
    int i = 0;
    while (count0--) nums[i++] = 0;
    while (count1--) nums[i++] = 1;
    while (count2--) nums[i++] = 2;
}

void sortColorsOptimal(vector<int>& nums) {
    // Dutch National flag algorithm
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1) mid++;
        else swap(nums[mid], nums[high--]);
    }
}

int main() {
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    vector<int> nums2 = nums1;
    vector<int> nums3 = nums1;

    sortColorsBrute(nums1);
    sortColorsBetter(nums2);
    sortColorsOptimal(nums3);

    return 0;
}
