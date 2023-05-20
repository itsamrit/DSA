//🟩🟩🟩🟩ALWAYS COMPARE WITH RIGHT PERSON i,e INDEX
int bs(vector<int>&nums,int target,int s,int e){
        while(s<=e){
            int mid=(s+(e-s)/2);
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {   
        int left=0,right=nums.size()-1;
        int mid;
        int ind=-1;
        while(left<=right){
            mid=left+(right-left)/2;
            if((mid==0 || nums[mid]<nums[mid-1]) && (mid==nums.size()-1 || nums[mid]<nums[mid+1])){   //😊🟩 First condition if found & break
                ind=mid;
                break;
            }
            else if(nums[mid]>nums[right]){   //😊🟩Always compare with nums[right] NOT WITH nums[left]
                                              //  U can also do this else if(nums[mid]<nums[right])    DONT COMPARE WITH BOTH LEFT AND RIGHT
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        
        int f=bs(nums,target,0,ind-1);        //🟢Sorted 0 to ind-1 .Since nums[ind] = smallest in rotated array. So dont do 0 to ind
        int s=bs(nums,target,ind,nums.size()-1);
        if(f!=-1)return f;
        else if(s!=-1)return s;
        else return -1;
    }
