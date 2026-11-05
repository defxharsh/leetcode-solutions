class Solution {
    void combo(vector<int>&cnd,int target,vector<int>&data,vector<vector<int>>&req,int index){
        if(target==0){
            req.push_back(data);
            return ;
        }
        if(target<0){
            return ;
        }
        if(index>=cnd.size()){
            return ;
        }
        data.push_back(cnd[index]);
        combo(cnd,target-cnd[index],data,req,index+1);
        data.pop_back();

        int cnt=0;
        int idx=index;
        while(idx<cnd.size()&&cnd[index]==cnd[idx]){
            idx++;
            cnt++;
        }
        combo(cnd,target,data,req,idx);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>data;
        vector<vector<int>>req;
        combo(candidates,target,data,req,0);
        return req;
    }
};