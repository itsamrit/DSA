int findPeakElement(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        if(nums.size()==1)return 0;
        
        while(left<=right){
            int mid=left+(right-left)/2;
            if( (mid==0 && nums[mid]>nums[mid+1]) || (mid==nums.size()-1 && nums[mid]>nums[mid-1])   ||   (mid!=0 && mid!=nums.size()-1 && nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid]) ){
                return mid;
            }
            else if( (mid==0 || nums[mid-1] < nums[mid]) && (mid==nums.size()-1 || nums[mid] < nums[mid+1]) ){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return -1;
}
