class Solution {
public:
	int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
		// first: string,second: steps
		queue<pair<string, int>> q;
		unordered_set<string> st(wordList.begin(), wordList.end());
		q.push({startWord, 1});
		st.erase(startWord);
		while (!q.empty()) {
			pair<string, int> Pair = q.front();
			q.pop();
			string word = Pair.first;
			int steps = Pair.second;
			if (word == targetWord) {
				return steps;
			}
			for (int ind = 0; ind < word.size(); ind++) {
				char original = word[ind];
				// replace each index character with a -z
				for (char ch = 'a'; ch <= 'z'; ch++) {
					word[ind] = ch;
					// if the new word exist in the set, push it into the q and erase it from stack
					if (st.find(word) != st.end()) {
						st.erase(word);
						q.push({ word, steps + 1 });
					}
				}
				word[ind] = original;
			}

		}
		return 0;
	}
};
