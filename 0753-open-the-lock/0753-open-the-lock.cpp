class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1; // starting point blocked

        queue<string> q;
        q.push("0000");

        unordered_set<string> visited;
        visited.insert("0000");

        int steps = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();

                if(curr == target) return steps;

                // Try all 8 next combinations by turning each wheel
                for(int i = 0; i < 4; i++){
                    char c = curr[i];

                    // Turn wheel up
                    string up = curr;
                    up[i] = (c == '9') ? '0' : c + 1;

                    // Turn wheel down
                    string down = curr;
                    down[i] = (c == '0') ? '9' : c - 1;

                    if(!dead.count(up) && !visited.count(up)){
                        visited.insert(up);
                        q.push(up);
                    }

                    if(!dead.count(down) && !visited.count(down)){
                        visited.insert(down);
                        q.push(down);
                    }
                }
            }
            steps++; // increment BFS layer
        }

        return -1; // unreachable
    }
};
