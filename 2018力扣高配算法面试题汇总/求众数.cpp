/*
求众数
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:
输入: [3,2,3]
输出: 3

示例 2:
输入: [2,2,1,1,1,2,2]
输出: 2
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		std::map<int, int> flag_map;
		std::map<int, int>::iterator map_iter;
		int max = 0;
		int tmp = 0;
		int index = 0;
		int size = nums.size();
		for (int i = 0; i < size; ++i)
		{
			map_iter = flag_map.find(nums[i]);
			if(map_iter != flag_map.end())
			{
				map_iter->second++;
				tmp = map_iter->second;
			}
			else
			{
				flag_map[nums[i]] = 1;
				tmp = 1;
			}
			if (tmp > max)
			{
				max = tmp;
				index = nums[i];
			}
		}
		return index;
	}
};

int main()
{
	Solution s;
	std::vector<int> v = {2,2,1,1,1,2,2};

	cout<<s.majorityElement(v)<<endl;
	getchar();
	return 0;
}