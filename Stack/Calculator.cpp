🟢Like +- have same priority so as /* have same priority.eg: 2*3/2 .U either divide first or multiply ans will be same

🟢You will be given either +-/* or +-() questions . You cant have */ and () combined and solved using stack
   🟢IN +-/* whenever +- comes we simply push it into stack & whenever /* comes we go back or pop 1 element and push the current element multiplied or divided by poped element.
       At last we add all elemetns of stack.
       
   🟢IN +-() push all element in stack and when ) comes we go back and add each element of stack till ( appers. At last we can add all elements of stack.
       Improvement : We can add each element while traversing and only push sumation of all element before ( appears & pop that top most sumation when ) appears & add it to current sum.
