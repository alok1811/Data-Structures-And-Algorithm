#include<iostream>
#include<vector>
using namespace std;

class
Solution
{
private:
    void func(int open, int close, int n, string s, vector<string> &ans){
        if(open == close && open + close == 2*n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            func(open + 1, close, n, s + '(', ans);
        }
        if(close < open){
            func(open, close + 1, n, s + ')', ans);
        }
      }
public:
    vector<string> GenerateParanthesis(int n){
        vector<string> ans;
        func(0, 0, n, "", ans);
        return ans;
    }
};

int main(){
    int n;
    cout << "Enter n:" ;
    cin >> n;
    Solution sol;
    vector<string> result = sol.GenerateParanthesis(n);

    cout << "All valid parenthesis combination : \n";
    for(string &s : result){
        cout << s << endl;
    }
    return 0;
}