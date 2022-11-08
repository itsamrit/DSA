✅✅👉 If a subarray becomes valid again by adding left elements which are already deleted earlier then it cant be solved by sliding window.Solve it by recursion.

eg: Substring with frequency of each character atleast k. acca & k=2.If we delete a & then go further then it agains become valid if we add a in cca.


👉 IF you need to pick either from left or right at each step there will subarray in middle so its a subarray prob.

👉 All subarray prob excepth this 4 types and printing are done by dp

👉 For hashing char to int : s[i]-'a' because a-'a'=0  Any character minus itself is 0 in coding except integers(never used).

👉 ◉ Since we dont intialize our map before loop we keep updating it in 1st line i,e in starting in our loop.

◉ We can also initialize our map before loop & then keep updating it in last line inside the loop. Loop will run till i=0 to i<n in both cases.

TO FIND ITERATOR OF SET & MAP SIMILAR TO VECTOR *i > *(i-1)
🤜

✅Except these problems all other subarray problem solved by dp except printing all subarray
