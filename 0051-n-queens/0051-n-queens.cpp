class Solution {
    void solve(int col,int n,vector<string>&board,vector<vector<string>>&ans,vector<int>&lowerdia,vector<int>&upperdia,vector<int>&backrow){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++){
            if(lowerdia[col+row]==0&&backrow[row]==0&&upperdia[col-row+n-1]==0){
                board[row][col]='Q';
                lowerdia[col+row]=1;
                backrow[row]=1;
                upperdia[col-row+n-1]=1;
                solve(col+1,n,board,ans,lowerdia,upperdia,backrow);
                board[row][col]='.';
                lowerdia[col+row]=0;
                backrow[row]=0;
                upperdia[col-row+n-1]=0;
            
            }

        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string str(n,'.');
        vector<string>board(n);
        for(int i=0;i<n;i++){
            board[i]=str;
        }
        vector<int>lowerdia(2*n-1,0);
        vector<int>upperdia(2*n-1,0);
        vector<int>backrow(n,0);
        solve(0,n,board,ans,lowerdia,upperdia,backrow);
        return ans;
    }
};