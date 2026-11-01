class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        stack<int>temp;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    temp.push(i);
                    temp.push(j);
                }
            }
        }

        int run=temp.size();
        run=run/2;
        while(run--){
            for(int i=0;i<matrix.size();i++){
                int index=temp.top();
                matrix[i][index]=0;
            }
            temp.pop();
            for(int j=0;j<matrix[0].size();j++){
                int index=temp.top();
                matrix[index][j]=0;
            }
            temp.pop();
        }
    }
};