
#include<iostream>
using namespace std;
class
Solution{
    private:
    double power(double x, long n){
        if(n == 0) return 1.0;
        if(n == 1) return x;
        if(n % 2 == 0){
            return power(x * x, n / 2);
        }
        return x * power(x,n-1);
    }
    public:
    double mypow(double x, long n){
        long long num = n;
        if(num < 0){
            num = - num;
            return (1.0/power(x,num));
        }
        else{
            return power(x,num);
        }
    }
};
int main() {
    Solution s;
    
    double x;
    long n;

    cout << "Enter base (x): ";
    cin >> x;

    cout << "Enter exponent (n): ";
    cin >> n;

    cout << "Result: " << s.mypow(x, n) << endl;

    return 0;
}