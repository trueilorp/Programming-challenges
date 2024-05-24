#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int singleNumber(vector<int>& nums) {
	
	sort(nums.begin(), nums.end());
	
	for (int i = 0; i < nums.size(); i=i+2){
		if(nums[i] != nums[i+1]){
			return nums[i];
		}
	}
	
	if(nums.size() % 2 != 0){
		return nums[nums.size()];
	}
	
	return -1;
}

int main(){
	
	vector <int> nums = {4,1,2,1,2};
	cout << singleNumber(nums);
	
	
	return 0;
}