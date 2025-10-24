#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long, int> prefixMap;
        long long sum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum == k)
                maxLen = i + 1;

            if (prefixMap.find(sum - k) != prefixMap.end())
                maxLen = max(maxLen, i - prefixMap[sum - k]);

            if (prefixMap.find(sum) == prefixMap.end())
                prefixMap[sum] = i;
        }

        return maxLen;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;

    int result = obj.longestSubarray(arr, k);
    cout << "Length of the longest subarray with sum " << k << " is: " << result << endl;

    return 0;
}
