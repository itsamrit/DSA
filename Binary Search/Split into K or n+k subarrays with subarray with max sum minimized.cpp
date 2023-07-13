TC : o(n*logn) n for checking is all subarrays can be divided into k parts with max cap mx & logn for binary search of max cap mx.
// KOKO EATING BANANAS : array of n to be split in n+k size opposite of this

#define intt long long int
bool valid(intt mid, int h, vector<int>&piles){
        intt temph=0;
        for(int i=0;i<piles.size();i++){
            temph+= (piles[i] + mid-1)/mid;
        }
        
        if(temph>h)return false;
        else return true;
}
    
int minEatingSpeed(vector<int>& piles, int h) {
        intt right =1;
        intt left;
        for(int i=0;i<piles.size();i++){
            if(left<piles[i]){
                left=piles[i];
            }
        }
        int ans=left;
        
        while(right<=left){
            intt mid=right + (left-right)/2;
            if(valid(mid, h, piles)==true){
                ans=mid;
                left=mid-1;
            }
            else{
                right=mid+1;
            }
        }
        
        return ans;
}
