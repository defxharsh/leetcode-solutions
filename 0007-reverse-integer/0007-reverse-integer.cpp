class Solution {
public:
    int reverse(int x) {
        long long digit=0;
        int i=0;
        long long xi=x;
        if(x<0){
            xi=(-1)*xi;
        }
        while(xi>0){
            int aank=xi%10;
            digit=digit*10+aank;
            i++;
            xi/=10;
        }

        if(x<0){
            digit=(-1)*digit;
        }
        if(digit > INT_MAX || digit < INT_MIN){
            return 0;
        }
        return digit;
    }
};