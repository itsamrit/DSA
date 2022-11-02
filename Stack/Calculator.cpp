you will be given either +-*/ or +-() questions . You cant have */ and () combined and solved using stack
Like +- have same priority so as */ have same priority.eg: 2*3/2 .U either divide first or multiply ans will be same

IN +-*/ whenever +- comes we simply push it into stack & whenever */ comes we go back or pop 1 element and push the current element multiplied or divided by poped element.
   At last we add all elemetns of stack.
In +-() push all element in stack and when ) comes we and add till ( appers
