TC : o(n*logn) n for checking is all subarrays can be divided into k parts with max cap mx & logn for binary search of max cap mx.
bool isvalid(arr,n,k,mx){
  int student =1;
  int sum=0;
  for(int i=0;i<n;i++){
    sum=sum+arr[i];
    if(sum>mx){
      student++;
      sum=arr[i];
    }
    if(student>k)return false;
  }
  return true;
}



int start=max in array   //🟢1st step i,e Smallest sum can be max element of array
int end=sum of array     //🟢2nd i,e max sum can be sum of whole array use a loop to find sum of whole array
int res=-1;

while(start<=end){
  int mid=start+(end-start)/2;
  if(isvalid(arr,n,k,mid)){
    res=mid;
    end=mid-1;
  }
  else start=mid+1;
}
  
