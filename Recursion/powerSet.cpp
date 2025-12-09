#include<iostream>
#include<vector>

using namespace std;
class Solution{
    private:

    void func(int ind, vector<int> &list, vector<vector<int>> &ans, vector<int> &nums){
        if(ind == nums.size()){
            ans.push_back(list);
            return;
        }
        // if we take the path
        list.push_back(nums[ind]);
        func(ind + 1, list, ans, nums);
        list.pop_back();

        // if we do not take the path
        func(ind + 1, list, ans, nums);
    }
    public:
    vector<vector<int>> subsets(vector<int> &nums){
        vector<vector<int>> ans;
        vector<int> list;
        func(0, list, ans, nums);
        return ans;

    }
};


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<vector<int>> result = sol.subsets(nums);

    cout << "All subsets:\n";
    for (auto &subset : result) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}