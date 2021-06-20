/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://leetcode.com/problems/process-tasks-using-servers/
class Solution {
public:
    vector<int> assignTasks(vector<int>& a, vector<int>& b) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	set<pair<int, int>>st;
	for (int i = 0; i < a.size(); i++) {
		st.insert({ a[i], i });
	}
	vector<int>ans; int t = 0;
	for (int i = 0; i < b.size(); i++) {
		t = max(t, i);
		while ((!st.size()) || (pq.size() && pq.top().first <= t)) {
			if (!st.size()) t = pq.top().first;
			int x = pq.top().second; pq.pop();
			st.insert({ a[x], x });
		}
		int x = st.begin()->second;
		ans.push_back(x);
		st.erase(st.begin());
		pq.push({ t + b[i], x });
	}
     return ans;
    }
};
