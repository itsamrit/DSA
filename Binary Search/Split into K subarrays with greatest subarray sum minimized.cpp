TC : o(n*logn) n for checking is all subarrays can be divided into k parts with max cap mx & logn for binary search of max cap mx.
bool isvalid(arr,n,k,mx){
  int student =1;
  int sum=0;
  for(int i=0;i<n;i++){
    sum=sum+v[i];
    if(sum>mx){
      student++;
      sum+=arr[i];
    }
    if(student>k)return false;
  }
  return true;
}








int start=max in array
int end=sum of array
int res=-1;

while(start<=end){
  int mid=start+(end-start)/2;
  if(isvalid(arr,n,k,mid)){
    res=mid;
    end=mid-1;
  }
  else start=mid+1;
}
  
