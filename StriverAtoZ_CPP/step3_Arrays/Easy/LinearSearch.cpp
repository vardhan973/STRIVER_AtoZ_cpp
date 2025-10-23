#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int target) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 30;

    int index = linearSearch(arr, target);

    if(index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
