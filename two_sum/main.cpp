#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> ris = {2,0};
	for (size_t i = 0; i < nums.size(); i++){
		for (size_t j = i+1; j < nums.size(); j++){
			if(nums[i] + nums[j] == target){
				ris[0] = i;
				ris[1] = j;
				return ris;
			}
		}
	}
	return ris;
}
	
int main(){
	vector<int> nums = {-1,-2,-3,-4,-5};
	int target = -8;
	
	vector<int> result = twoSum(nums, target);
	cout << result[0] << " " << result[1];
	
	return 0;
}