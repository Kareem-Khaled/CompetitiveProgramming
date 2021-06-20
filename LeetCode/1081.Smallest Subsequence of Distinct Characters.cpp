/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
class Solution {
public:
    string smallestSubsequence(string s) {
	unordered_map<char, int>frq, vis;
	for (int i = 0; i < s.size(); i++){
		frq[s[i]]++;
	}
	string ans = ""; stack<char>st;
	for (int i = 0; i < s.size(); i++){
		frq[s[i]]--;
		if (vis[s[i]])continue;
		while (st.size() && s[i] < st.top() && frq[st.top()])
			vis[st.top()]--, st.pop();
		st.push(s[i]); vis[s[i]]++;
	}
	while (st.size())
		ans += st.top(), st.pop();
	reverse(ans.begin(),ans.end());
	return ans;
    }
};
