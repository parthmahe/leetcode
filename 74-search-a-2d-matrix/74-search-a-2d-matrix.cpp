class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target)
    {
        int row=0;
        int col=mat[0].size()-1;
        while(col>=0 && row<=mat.size()-1)
        {
            if(target==mat[row][col])
                return true;
            else if(target>mat[row][col])
                row++;
            else
                col--;
        }
        return false;
    }
};