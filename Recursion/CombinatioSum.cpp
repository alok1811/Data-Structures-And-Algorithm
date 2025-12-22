#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void func(int ind, vector<int> &list, int sum, vector<int> &arr, vector<vector<int>> &ans){
        if(sum == 0){
            ans.push_back(list);
            return;
        }
        if(sum < 0){
            return;
        }
        if(ind < 0){
            return;
        }
        func(ind - 1, list, sum, arr, ans);
        list.push_back(arr[ind]);
        func(ind, list, sum - arr[ind], arr, ans);
        list.pop_back();

    }
    public:
    vector<vector<int>> combinationSum(vector<int> arr, int target){
        vector<vector<int>> ans;
        vector<int> list;
        func(arr.size() - 1, list , target, arr, ans);
        return ans;
    }
};
int main() {
    Solution sol;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    vector<vector<int>> result = sol.combinationSum(arr, target);

    cout << "Combinations are:\n";
    for (auto &vec : result) {
        cout << "[ ";
        for (int x : vec) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
