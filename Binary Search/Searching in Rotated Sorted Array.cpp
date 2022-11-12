int getPivot(vector<int>& nums, int n){
        int s=0;
        int e =nums.size()-1;
        // ✅✅ WE ONLY COMPARE MID AND RIGHTMOST ELEMENT NO USE OF LEFT element
        
        while(s<e){
            int m = s+(e-s)/2;
            if(nums[m] > nums[e]) s=m+1;  // ✅left side has big values.✅TLE : INCREMENT MID SINCE nums[mid]>nums[e],so it is fixed that mid is not pivot. 
            else if(nums[m]<nums[s])e=m;           // right side has big value ✅U cant decrement e=m-1; Since it is mid, it can be pivot.
            else e--;                    //✅ For upper bound e++; when both found equal
        }
        return s;
}
    
int binarySearch(vector<int>& nums, int s, int e, int target){  //Apply to that part binary search where there is possibility
        int m;
        while(s <= e){
            m = s + (e-s)/2;
            if(nums[m]== target) return m;
            else if(nums[m]< target) s = m+1;
            else if(nums[m]>target) e = m-1;
            else e--;
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
