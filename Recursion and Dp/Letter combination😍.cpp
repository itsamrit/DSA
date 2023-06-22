//😍😍Letter combination algo in 1 LINE : LAYER OF for loop in COMBINATION 01 algorithm : so we're passing c+1 unaffected by for loop's int i
//🟩🟩🟩🟩RATNA   ❤️❤️Since we're just adding a layer of loop in combination 01 algo to generate the strings, so our passing of 😍😍❤️❤️c is unaffected by loop's int i

vector<string> mapp = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> ans;

void dfs(string &digits, int c, string &temp){	
	if(c == size(digits)) { 
		ans.push_back(temp);    
		return;
	}

	for(auto &i : mapp[digits[c] - '2']){
		temp.push_back(i);
		helper(digits, c + 1, temp);    // 😍Since its a combination problem we pass index c which is uneffected by for loop.
		// ❤️❤️Since we're just adding a layer of loop in COMBINATION 01 algo to generate the strings, so our passing of 😍😍❤️❤️c is unaffected by loop's int i
		temp.pop_back();
	}
}

vector<string> letterCombinations(string digits) {
	if(digits == "") return ans;         // no combinations formed without any digits
	dfs(digits, 0, "");              
	return ans;
}
