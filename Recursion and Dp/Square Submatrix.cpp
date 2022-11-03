//Count Square Submatrices with All ones in a binary matrix

int countSquares(vector<vector<int>>& matrix) {
		int ans =0;
                
		for(int i=0;i<matrix.size();++i)
                    for(int j=0;j<matrix[0].size();++j)
		        if(i!=0 && j!=0 && matrix[i][j]==1)  
			   matrix[i][j] = 1 + min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1]));  // if this index is 1 then squares in which this is a part = min(left,up,diagonal up) + 1
                             
			ans +=matrix[i][j];   // Add all squares associated with each index
	                   //For max area square submatrix with all ones : ans = max(matrix[i][j], ans);
        
		return ans;
}
