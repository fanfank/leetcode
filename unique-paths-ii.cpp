class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int rw = obstacleGrid.size();
		int cl = obstacleGrid[0].size();
		int *res = new int[cl];
		memset(res, 0, sizeof(int) * cl);
		res[0] = 1;
		for(int i = 0; i < rw; i++)
		{
			if(obstacleGrid[i][0] == 1)
				res[0] = 0;
			else
				res[0] = res[0];
			for(int j = 1; j < cl; j++)
				if(obstacleGrid[i][j] == 1)
					res[j] = 0;
				else
					res[j] += res[j-1];
		}
		int tmp = res[cl-1];
		delete []res;
		return tmp;
    }
};
