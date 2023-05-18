//Start iterating from last & find the number which is smaller than any of the nuber previous iterated.
//Now from this place start iterating to last to find element which is closest greater than this. Swap both & sort the array from this place

void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                int j=i+1;
                while(j<nums.size()){
                    if(nums[j]<=nums[i]){
                        break;
                    }
                    j++;
                }
                j--;
                swap(nums[j],nums[i]);
                sort(nums.begin()+i+1,nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end());
}
