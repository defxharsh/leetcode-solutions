class Solution {
    void generatebhai(vector<int>&nums,int index,vector<int>&data,vector<vector<int>>&result){
        if(index==nums.size()){
            result.push_back(data);
            return;
        }
        data.push_back(nums[index]);
        generatebhai(nums,index+1,data,result);
        data.pop_back();
        int idx=index;
        while(idx<nums.size()&&nums[index]==nums[idx]){
            idx++;
        }
        generatebhai(nums,idx,data,result);

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>data;
        vector<vector<int>>result;
        generatebhai(nums,0,data,result);
        return result;   
    }
};