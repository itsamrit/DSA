//Start iterating from last & find the number which is smaller than any of the nuber previous iterated.
//Now from this place start iterating to last to find element which is closest greater than this. Swap both & sort the array from this place

void nextPermutation(vector<int>& nums) {
        int flag=0, maxx=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<nums[maxx]){ 
                for(int j=i+1;j<nums.size();j++){
                    if(nums[i]<nums[j] && nums[maxx]>nums[j]){
                        maxx=j;
                    }
                }
                swap(nums[i],nums[maxx]);
                sort(nums.begin()+i+1,nums.end());
                flag=1;
                break;
                
            }
            if(nums[i]>nums[maxx])maxx=i;
        }
        
        if(flag==1)return;
        sort(nums.begin(),nums.end());
        return;
}
