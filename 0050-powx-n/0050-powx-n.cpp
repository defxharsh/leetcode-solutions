class Solution {
public:
    double myPow(double x, int n) {
        long long num=n;
        bool neg=false;
        if(n<0){
            neg=true;
            num=num*(-1);  // here if the n=n*(-1) and n is INT_MIN then it will overflow so use long long to compensate the overflow
        }
        double ans=1.00000;
        while(num>0){
            if(num%2){
                ans=x*ans;
                num=num-1;
            }
            num=num/2; //no need of the else as here it is obvious,else just increase the iteration.
            x=x*x;
        }
        if(neg){
            return 1/ans;
        }
        return ans;

    }
};