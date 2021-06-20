/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://leetcode.com/problems/3sum/
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>>ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++){
			int z = -nums[i];
			int x = i + 1, y = nums.size() - 1;
			while (x < y){
				int sum = nums[x] + nums[y];
				if (sum > z)
					y--;
				else if (sum < z)
					x++;
				else{
					vector<int> tmp = { nums[x], nums[y], nums[i] };
					ans.push_back(tmp);
					while (x < y && nums[x] == tmp[0]) x++;
					while (x < y && nums[y] == tmp[1]) y--;
				}
			}
			while (i + 1 < nums.size() && nums[i + 1] == nums[i])
				i++;
		}
		return ans;
	}
};
