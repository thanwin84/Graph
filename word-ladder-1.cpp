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

/*
Initializing Dictionary (unordered_set):
The unordered_set dictionary is initialized with the words from the wordList. This operation has a time complexity of O(N), where N is the number of words in the wordList.
Queue Operations:

We use a queue to perform BFS (Breadth-First Search) traversal of the graph of words. In the worst case, each word is enqueued and dequeued once. Therefore, the time complexity of queue operations is O(N), where N is the number of words in the queue.
Character Replacement Loop:

For each word in the queue, we perform a loop to replace each character with all 26 lowercase English letters. This loop has a time complexity of O(M), where M is the length of the words.
Overall Time Complexity:

Considering the above factors, the overall time complexity of the solution is O(N * M * 26), where N is the number of words in the word list, and M is the length of the words.
Optimization:

Since we mark words as visited once they are enqueued, the same word will not be enqueued multiple times. This optimization ensures that we do not revisit the same word multiple times during the BFS traversal.
Early Termination:

If the target word is found during the BFS traversal, the search terminates early, reducing unnecessary operations.
In summary, the optimized solution has a time complexity of O(N * M * 26), where N is the number of words in the word list, and M is the length of the words. 
*/
