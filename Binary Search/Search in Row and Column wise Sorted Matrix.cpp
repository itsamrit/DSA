// For fully sorted matrix i,e last element of 1st row is greater than 1st elem of 2nd rowTc thenn, search normally 0-n*m binaryt searach with index mat[/][%] =(log(n*m)) = o(logn + logm)


// For row wise & column wise sorted matrix : Start searching from mat[0][n-1] if(tar>mat) j--; else i++; =o(n) linear
//       First find the row in which it can be by searching in logm 
//       Then search in that row in logn
