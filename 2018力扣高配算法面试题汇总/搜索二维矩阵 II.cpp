/*
搜索二维矩阵 II

编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//这是别人的答案，我的答案多考虑了往横向后走的情况，其实这是不用考虑的
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
	    if(matrix.empty() || matrix[0].empty()) return false;
	    int m=matrix.size();
	    int n=matrix[0].size();
	    int i=0,j=n-1;
	    while(i<m&&j>=0)
	    {
	        if(target>matrix[i][j]) i++;
	        else if(target<matrix[i][j]) j--;
	        else return true;
	    }
	    return false;
	}
	/*这是我的答案
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		return HorizontalSearch(matrix, target, 0, 0, true);
	}
	bool HorizontalSearch(vector<vector<int>>& matrix, int target, int row, int col, bool forward) {
		int rowsize = matrix.size();
		if (row >= rowsize)
			return false;
		int colsize = matrix[row].size();
		int tmp = 0;
		if(forward)
		{
			for (int i = col; i < colsize; ++i)
			{
				tmp = matrix[row][i];
				if(tmp == target)
					return true;
				else if (tmp > target)
					return VerticalSearch(matrix, target, row+1, i);
				else if( i + 1 == colsize)
					return VerticalSearch(matrix, target, row+1, i);
				else
					continue;
			}
		}
		else
		{
			for (int i = col; i >= 0; --i)
			{
				tmp = matrix[row][i];
				if(tmp == target)
					return true;
				else if (tmp > target)
					continue;
				else
					return VerticalSearch(matrix, target, row+1, i);
			}
		}
		return false;
	}
	
	bool VerticalSearch(vector<vector<int>>& matrix, int target, int row, int col) {
		if (row >= matrix.size())
			return false;
		int tmp = matrix[row][col];
		if(tmp == target)
			return true;
		else if (tmp < target)
			return HorizontalSearch(matrix, target, row, col, true);
		else
			return HorizontalSearch(matrix, target, row, col, false);
	}
	*/
};

int main()
{
	vector<vector<int>> matrix = {
		{1,4,7,11,15},
		{2,5,8,12,19},
		{3,6,9,16,22},
		{10,13,14,17,24},
		{18,21,23,26,30},
	};
	Solution s;
	int a=0;
	while(a != -1)
	{
		cin>>a;
		if (s.searchMatrix(matrix, a))
			cout<<"true";
		else
			cout<<"false";
	}
	system("pause");
	return 0;
}

