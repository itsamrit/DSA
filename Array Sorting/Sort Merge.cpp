//Part of divide and conquer
//You can also find inversion with merge sort. Inversion means :a[i]>a[j] & i<j
//t.c=0(n*logn)              s.c=o(n) because of left[n/2] + right[n/2].

void merge(int *Arr, int start, int mid, int end,int &inversion) {    
	//🟩😊😊start to mid and mid to end are already sorted so just compare arr[i] and arr[j] && MERGE THEM
	
	vector<int>temp;
	int i = start, j = mid+1;     
    
	while(i <= mid && j <= end) {
	     if(Arr[i] <= Arr[j]) temp.push_back(Arr[i++]);  //🟩😊start to mid and mid to end are already sorted so just compare arr[i] and arr[j]
	     else temp.push_back(Arr[j++]);  // inversion+=mid-i; && REST SAME
	}
	//To find pairs/inversion such that arr[i]>2*arr[j] with i<j  : if(arr[i] <= arr[j]*2)  && Rest same in above loop
	
	while(i <= mid) { temp.push_back(Arr[i]); i++;}
  
	while(j <= end) { temp.push_back(Arr[j]); j++;}
    
	for(i=start; i<=end; i++) Arr[i] = temp[i-start]
	
}

void mergeSort(int *Arr, int start, int end) {
	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid+1, end);
		merge(Arr, start, mid, end,inversion);
	}
}
