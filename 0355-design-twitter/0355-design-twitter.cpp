class Twitter {
    // User -> set of followees
    unordered_map<int, unordered_set<int>> follows;
    
    // User -> list of (time, tweetId)
    unordered_map<int, vector<pair<int, int>>> tweets;
    
    // Global time counter
    int time;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Min-heap to keep the most recent 10 tweets
        priority_queue<pair<int, int>> heap;
        
        // Make sure user follows themselves
        follows[userId].insert(userId);
        
        for (int followee : follows[userId]) {
            auto& t = tweets[followee];
            // Add their tweets to the heap
            for (auto it = t.rbegin(); it != t.rend() && it != t.rbegin() + 10; ++it) {
                heap.push(*it);
            }
        }
        
        vector<int> res;
        while (!heap.empty() && res.size() < 10) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // Cannot unfollow themselves
        if (followerId != followeeId) {
            follows[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */