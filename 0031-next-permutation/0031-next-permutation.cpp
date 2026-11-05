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
    int greater(vector<int>&nums,int index){
        int min=INT_MAX;
        for(int i=index+1;i<nums.size();i++){
            if(nums[i]<min&&nums[i]>nums[index]){
                min=nums[i];
            }
        }
        for(int i=index+1;i<nums.size();i++){
            if(min==nums[i]){
                return i;
            }
        }
        return 0;
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
        sort(nums.begin()+pivot+1,nums.end());
    }
};