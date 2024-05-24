def single_number(nums):
	if(len(nums) == 1):
		return nums[0]
	
	nums.sort()

	for i in range(0, len(nums) // 2, 2):
		if nums[i] != nums[i + 1]:
			return nums[i]
		if nums[-i-1] != nums[-i-1 - 1]:
			return nums[-i-1]

if __name__ == "__main__":
	nums = [1]
	print(single_number(nums))
