/*class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
        return;
    }
};*/



class Solution {
    public:
    int idx(vector<int>&nums){
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                return i;
            }
        }
        return -1;
    }
    int greater(vector<int>& nums, int index) {
        for(int i = nums.size()-1; i > index; i--) {
            if(nums[i] > nums[index]) {
                return i;
            }
        }
        return -1;
    }
public:
    void nextPermutation(vector<int>& nums) {

        int pivot=idx(nums);
        if(pivot==-1){
            for(int i=0;i<nums.size()/2;i++){
                int temp=nums[i];
                nums[i]=nums[nums.size()-1-i];
                nums[nums.size()-1-i]=temp;
            }
            return ;
        }
        int index=greater(nums,pivot);
        swap(nums[pivot],nums[index]);
        reverse(nums.begin()+pivot+1,nums.end());
    }
};