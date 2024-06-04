//Start iterating from last & find the number which is smaller than any of the nuber previous iterated, I,e nums[I] smaller that nums[i+1] haha
//Now from this place start iterating to last to find element which is closest greater than this. Swap both & sort the array from this place. This is tricky see code implementation. Edge cases
// If whole array is montonically decreasing not found then sort the whole array

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        for i in range(len(nums)-2,-1 , -1):
            if(nums[i] < nums[i+1]):
                j=i+1
                while(j<len(nums)):
                    if(nums[j]<= nums[i]):
                        break
                j-=1
                swap(nums[i], nums[j])
                nums[i+1:] = sorted(nums[i+1:])
                return
            
        nums.sort()
