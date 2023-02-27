🟩🟩Only rememmber code of merging intervals .
  If problem of inserting intervals and array is already sorted then insertt the interval using insert() fun on right place based on itering & mainitain sorted array with first element
  Merge the intervals  starting from interval where you inserted .Same tc=0(n/2 inserting) & 0(n/2merging) =0(n)
Sort the interval based on requirement either by starting index v[i][0] or ending index v[i][1]
Create another ans vector to insert the intervals.Dont modify existing array.If ans coming you can optimize space complex by modifying
