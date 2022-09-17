int getPivot(vector<int>& nums, int n){
        int s=0;
        int e =nums.size()-1;
        while(s<e){
            int m = s+(e-s)/2;
            if(nums[m] >= nums[e]) s=m+1;          // ✅left side has small values (rotated array)
            else e=m;                        // right side has small value (not rotated)
        }
        return s;
}
    
int binarySearch(vector<int>& nums, int s, int e, int target){  //Apply to that part binary search where there is possibility
        int m;
        while(s <= e){
            m = s + (e-s)/2;
            if(nums[m]== target) return m;
            else if(nums[m]< target) s = m+1;
            else e = m-1;
        }
        return -1;
}
    
int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = getPivot(nums, n);
        if(target >= nums[pivot] && target <= nums[n-1]){
            return binarySearch(nums, pivot, n-1, target);
        }
        else{
            return binarySearch(nums, 0, pivot-1, target);
        }
}
