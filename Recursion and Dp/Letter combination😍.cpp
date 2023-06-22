//😍😍This problem is of 01 Combination of array of string of chars but code is like 01 permutation
//🟩🟩🟩🟩RATNA
vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> ans;

vector<string> letterCombinations(string digits) {
	if(digits == "") return ans;         // no combinations formed without any digits
	helper(digits, 0, "");              
	return ans;
}

void helper(string &digits, int i, string combi){	
	if(i == size(digits)) { 
		ans.push_back(combi);    
		return;
	}

	for(auto &c : mappings[digits[i] - '2']){
		combi.push_back(c);
		helper(digits, i + 1, combi);
		combi.pop_back();
	}
}
