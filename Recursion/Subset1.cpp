#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void func(int ind, int sum, vector<int> &nums, vector<int> &ans){
        if(ind == nums.size()){
            ans.push_back(sum);
            return;
        }
        func(ind + 1, sum + nums[ind], nums, ans);
        func(ind + 1, sum, nums, ans);

    }

    public:
    vector<int> Subset1(vector<int> &list){
        vector<int> ans;

        func(0, 0, list, ans);

        return ans;
    }
};
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> list(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    Solution obj;
    vector<int> result = obj.Subset1(list);

    sort(result.begin(), result.end()); // optional (LeetCode style)

    cout << "Subset sums are:\n";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
