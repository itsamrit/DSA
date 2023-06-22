//😍😍This problem is of 01 Combination of array of string of chars so its code looks like unbounded permutation but index is passed in dfs i like we pass in combination
//🟩🟩🟩🟩RATNA
vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> ans;

vector<string> letterCombinations(string digits) {
	if(digits == "") return ans;         // no combinations formed without any digits
	dfs(digits, 0, "");              
	return ans;
}

void dfs(string &digits, int i, string combi){	
	if(i == size(digits)) { 
		ans.push_back(combi);    
		return;
	}

	for(auto &c : mappings[digits[i] - '2']){
		combi.push_back(c);
		helper(digits, i + 1, combi);    // 😍Since its a combination problem we pass index i
		combi.pop_back();
	}
}
