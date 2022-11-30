//We find out minimum no of swaps to make temporry sorted array to given array & thats our answer.
//🟢To find no of nodes in cycle, we must have the starting node of cycle.
//    Here we have starting node as 1st unsorted element found. We can find no of nodes in all unsorted cycle of array (i,e starting from unsorted element & ending at same). 


int minSwaps(vector<int>&nums){
	    vector<pair<int,int>>temp;
	    for(int i=0;i<nums.size();i++){
	        temp.push_back({nums[i],i});
	    }
	    int ans=0;
	    sort(temp.begin(),temp.end());
	    for(int i=0;i<nums.size();i++){
	        while(i!=temp[i].second){
	            ans++;
	            swap(temp[i],temp[temp[i].second]);
	        }
	    }
	    return ans;
}
