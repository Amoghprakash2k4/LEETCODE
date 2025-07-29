class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;

        for (string op : operations) {
            if (op == "C") {
                scores.pop_back();
            } else if (op == "D") {
                scores.push_back(2 * scores.back());
            } else if (op == "+") {
                int n = scores.size();
                scores.push_back(scores[n - 1] + scores[n - 2]);
            } else {
                scores.push_back(stoi(op));  // convert string to int
            }
        }

        // Sum all the scores
        int total = 0;
        for (int score : scores) {
            total += score;
        }
        return total;
    }
};
