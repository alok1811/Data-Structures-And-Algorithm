#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void func(int ind, int sum, vector<int> &list, vector<int> &arr, vector<vector<int>> &ans){
        if(sum == 0){
            ans.push_back(list);
            return;
        }
        if(sum < 0 || ind == arr.size())return;
        list.push_back(arr[ind]);
        func(ind + 1, sum - arr[ind], list, arr, ans);
        list.pop_back();

        for(int i = ind + 1; i < arr.size(); i++){
            if(arr[i] != arr[ind]){
                func(i, sum, list, arr, ans);
                break;
            }

        }
    }
    public:
    vector<vector<int>> CombinationSum2(vector<int> &candidates, int target){
        vector<vector<int>> ans;
        vector<int> list;

        sort(candidates.begin(),candidates.end());

        func(0, target, list, candidates, ans);

        return ans;
    }
};

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> candidates(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    Solution obj;
    vector<vector<int>> result = obj.CombinationSum2(candidates, target);

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


