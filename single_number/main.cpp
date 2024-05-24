#include <vector>
#include <iostream>
using namespace std;


int singleNumber(vector<int>& nums) {
	int single = -1;
	bool isSingle = true;
	
	for (int i = 0; i < nums.size(); i++){
		for (int j = 0; j < nums.size(); j++){
			if(i != j){
				if(nums[i] == nums[j]){
					isSingle = false;
				}
			}
		}
		if(isSingle){
			single = nums[i];
		}
		isSingle = true;
	}	
	
	return single;
}

int main(){
	
	vector <int> nums = {2,2,1};
	cout << singleNumber(nums);
	
	
	return 0;
}