class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> dictionary(wordList.begin(), wordList.end());
        dictionary.erase(startWord);
        // q.first = word and q.second = number of steps 
        queue<pair<string, int>> q;
        q.push({ startWord, 1 });
        while (!q.empty()) {
            pair<string, int> current = q.front();
            string currentWord = current.first;
            int steps = current.second;
            q.pop();
            if (currentWord == targetWord) {
                return steps;
            }
            for (int i = 0; i < startWord.size(); i++) {
                char originalChar = currentWord[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    currentWord[i] = ch;
                    if (dictionary.find(currentWord) != dictionary.end()) {
                        q.push({ currentWord, steps + 1});
                        dictionary.erase(currentWord);
                    }
                }
                currentWord[i] = originalChar;
            }
        }
        return 0;

    }
};

// time complexity of O(N * M * 26), where N is the number of words in the word list, and M is the length of the words
