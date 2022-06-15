class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstcol=false;
        
        
        for(int x=0;x<matrix.size();x++)
        {
            if(matrix[x][0]==0)
                firstcol=true;
            for(int y=1;y<matrix[0].size();y++)
            {
                if(matrix[x][y]==0)
                {
                    matrix[x][0]=0;
                    matrix[0][y]=0;
                }
            }
        }
        
        for(int x=1;x<matrix.size();x++)
        {
            for(int y=1;y<matrix[0].size();y++)
            {
                if(matrix[x][0]==0 || matrix[0][y]==0)
                    matrix[x][y]=0;
            }
        }
        
        if(matrix[0][0]==0)
        {for(int x=0;x<matrix[0].size();x++)
                matrix[0][x]=0;}
        
        if(firstcol)
        {
            for(int x=0;x<matrix.size();x++)
                matrix[x][0]=0;
        }
        
        
    }
};