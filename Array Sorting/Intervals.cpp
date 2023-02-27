🟩🟩Only rememmber code of merging intervals .  IN merging u just need to sort 1st index not 2nd like u dont need to do this : if(arr[i][0]==arr[i+1][0])return arr[i][1]>...
  If problem of inserting intervals and array is already sorted then insertt the interval using insert() fun on right place based on itering & mainitain sorted array with first element
  Merge the intervals  starting from interval where you inserted .Same tc=0(n/2 inserting) & 0(n/2merging) =0(n)
  
Sort the interval based on requirement either by starting index v[i][0] or ending index v[i][1] 
Create another ans vector to insert the intervals.Dont modify existing array.If ans coming you can optimize space complex by modifying
