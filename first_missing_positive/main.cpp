#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int firstMissingPositive(vector<int>& nums){
	int size = nums.size();
	sort(nums.begin(), nums.end());
	for (size_t i = 0; i < nums[size-1]; i++){
		if(i != nums[0]){
			return i;
		}		
	}
	return 0;	
}

int main(){
	vector<int> nums = {1,2,0};
	cout << firstMissingPositive(nums);
	return 0;
}