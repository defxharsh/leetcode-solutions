class Solution {
    public:
    void data(int num,vector<vector<int>>&result){
        result[0].push_back(1);
        for(int i=1;i<num;i++){
            result[i].push_back(1);
            for(int j=1;j<i;j++){
                result[i].push_back(result[i-1][j-1]+result[i-1][j]);
            }
            result[i].push_back(1); 
        }
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result(numRows);
        data(numRows,result);
        return result;
    }
};