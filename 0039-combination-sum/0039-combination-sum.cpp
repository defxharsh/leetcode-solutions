class Solution {
    void combo(vector<int>cnd,int target,vector<vector<int>>&result,int index,vector<int>&data){
        if(target==0){
            result.push_back(data);
            return ;
        }
        if(target<0){
            return ;
        }
        if(index>=cnd.size()){
            return ;
        }
        data.push_back(cnd[index]);
        combo(cnd,target-cnd[index],result,index,data);
        data.pop_back();

        combo(cnd,target,result,index+1,data);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>data;
        vector<vector<int>>result;
        combo(candidates,target,result,0,data);
        return result;
    }
};