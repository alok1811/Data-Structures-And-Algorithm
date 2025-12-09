#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int func(int ind, int sum, vector<int> &nums){
        if(sum == 0){
            return 1;
        }
        if(sum < 0 || ind == nums.size()){
            return 0;
        }
        return func(ind + 1, sum - nums[ind], nums) + func(ind + 1, sum, nums);
    }
    public:
    int countSubsequence(vector<int> & nums, int sum){
        return func(0, sum, nums);
    }
};

int main() {
    int n, sum;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << "Enter target sum: ";
    cin >> sum;

    Solution sol;
    int count = sol.countSubsequence(nums, sum);

    cout << "Number of subsequences whose sum is " << sum << " = " << count << endl;

    return 0;
}