class Solution {
public:
    int maxEvents(vector<vector<int>>& e) {
        // Min-heaps (priority_queues) for sorting events by start and end day
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> start, end;

        // Map to track which events are still available (not yet attended)
        map<int, int> idx;

        int m = 0; // Store the maximum end day across all events

        // Populate the heaps and the availability map
        for (int i = 0; i < e.size(); i++) {
            m = max(m, e[i][1]);              // update latest end day
            start.push({e[i][0], i});         // push (start day, event index)
            end.push({e[i][1], i});           // push (end day, event index)
            idx.insert({i, 1});               // mark event as available
        }

        int d = start.top().first; // Start from the earliest available event day
        int ans = 0;               // Counter for number of events attended

        // Main simulation loop: continue while events exist and days are valid
        while (!end.empty() && d <= m && !start.empty()) {

            // \U0001f9f9 Clean up invalid events from both heaps

            // Remove already-attended events from end heap
            while (!end.empty() && !idx.count(end.top().second)) end.pop();

            // Remove expired events from end heap
            while (!end.empty() && d > end.top().first) {
                idx.erase(end.top().second);
                end.pop();
            }

            // Remove already-attended events from start heap
            while (!start.empty() && !idx.count(start.top().second)) start.pop();

            // \U0001f3af Try to attend an event today, preferring the one that ends earliest

            if (!end.empty() && idx.count(end.top().second) &&
                d >= e[end.top().second][0] && d <= e[end.top().second][1]) {
                // Event from end heap is valid for today
                ans++;
                idx.erase(end.top().second); // mark it attended
                end.pop();
                // (Optional) Debug print: cout << d << " from end: event " << ... << endl;
            }

            // If no valid event in end heap, check start heap
            else if (!start.empty() && idx.count(start.top().second) &&
                     d >= e[start.top().second][0] && d <= e[start.top().second][1]) {
                ans++;
                idx.erase(start.top().second); // mark it attended
                start.pop();
                // (Optional) Debug print: cout << d << " from start: event " << ... << endl;
            }

            d++; // Move to the next day
        }

        return ans; // Return total events attended
    }
};
