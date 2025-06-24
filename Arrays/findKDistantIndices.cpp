#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyIndices;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == key) {
                keyIndices.push_back(i);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            for (int j : keyIndices) {
                if (abs(i - j) <= k) {
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, 9, 1, 3, 9, 2};
    int key = 9;
    int k = 1;

    vector<int> result = sol.findKDistantIndices(nums, key, k);

    cout << "K-distant indices: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}