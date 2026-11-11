/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second>((nums.size())/2)){
                return it.first;
            }
        }
        return -1;
    }
};*/




// Boyer–Moore Majority Voting Algorithm 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=nums[0];
        for(int i=0;i<nums.size();i++){
            if(count==0&&i!=0){
                candidate=nums[i];
            }
            if(nums[i]==candidate){
                count++;
            }
            else{
                count--;
            }
        }
        int cnt=0;
        if(count!=0){
            for(int i=0;i<nums.size();i++){
                if(candidate==nums[i]){
                    cnt++;
                }
            }
            if(cnt>nums.size()/2){
                return candidate;
            }
            return -1;
        }
        return -1;
    }
};