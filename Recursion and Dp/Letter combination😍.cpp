//😍😍This problem is of 01 Combination of array of string of chars so its code looks like unbounded permutation but index is passed in dfs like we pass in combination
//🟩🟩🟩🟩RATNA   ❤️❤️Since we're just adding a layer of loop in combination 01 algo to generate the strings, so our passing of 😍😍❤️❤️c is unaffected by loop's int i

vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> ans;

void dfs(string &digits, int c, string combi){	
	if(c == size(digits)) { 
		ans.push_back(combi);    
		return;
	}

	for(auto &i : mappings[digits[c] - '2']){
		combi.push_back(i);
		helper(digits, c + 1, combi);    // 😍Since its a combination problem we pass index c which is uneffected by for loop.
		// ❤️❤️Since we're just adding a layer of loop in combination 01 algo to generate the strings, so our passing of 😍😍❤️❤️c is unaffected by loop's int i
		combi.pop_back();
	}
}

vector<string> letterCombinations(string digits) {
	if(digits == "") return ans;         // no combinations formed without any digits
	dfs(digits, 0, "");              
	return ans;
}
