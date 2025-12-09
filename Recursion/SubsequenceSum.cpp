#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool func(int ind, int sum, vector<int> & nums){
        if(sum == 0){
            return true;

        }
        if(sum < 0 || ind == nums.size()){
            return false;
        }
        return func(ind + 1, sum - nums[ind], nums) | func(ind + 1, sum, nums);
    }
    public:
    bool checkSubsequenceSum(vector<int> &nums, int k){
        return func(0, k, nums);
    }
};
int main() {
    int n, k;
    
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    Solution sol;
    bool result = sol.checkSubsequenceSum(nums, k);

    if(result)
        cout << "Yes, a subsequence with sum " << k << " exists.\n";
    else
        cout << "No, such a subsequence does not exist.\n";

    return 0;
}