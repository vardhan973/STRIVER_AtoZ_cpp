#include <iostream>
#include <vector>   // for vector
#include <climits>  // for INT_MIN
using namespace std;

int main() {
    vector<int> a = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = a.size();

    int sum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        sum += a[i];

        if (sum > maxSum) {
            maxSum = sum;   // update max
        }

        if (sum < 0) {
            sum = 0;        // reset if negative
        }
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;
    return 0;
}
