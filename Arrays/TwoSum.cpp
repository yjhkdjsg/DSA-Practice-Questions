#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sol;
        for (int i = 0; i < nums.size(); i++) {
            int num = target - nums[i];
            if (sol.find(num) != sol.end()) {
                return {sol[num], i};
            }
            sol[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = solution.twoSum(nums, target);

    for (int index : result) {
        cout << index << " ";
    }

    return 0;
}
