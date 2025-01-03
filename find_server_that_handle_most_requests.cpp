class Solution {
public:
vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    // Priority queue to track busy servers, stores (end_time, server_id)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy_servers;
    
    // Set to track available servers
    set<int> available_servers;
    for (int i = 0; i < k; ++i) {
        available_servers.insert(i);
    }
    
    // Array to count requests handled by each server
    vector<int> request_count(k, 0);
    
    for (int i = 0; i < arrival.size(); ++i) {
        int start_time = arrival[i];
        int duration = load[i];
        
        // Free up servers that have finished their tasks
        while (!busy_servers.empty() && busy_servers.top().first <= start_time) {
            available_servers.insert(busy_servers.top().second);
            busy_servers.pop();
        }
        
        if (available_servers.empty()) {
            continue; // All servers are busy, drop the request
        }
        
        // Find the preferred server or the next available one
        int preferred = i % k;
        auto it = available_servers.lower_bound(preferred);
        
        // Wrap around if no suitable server is found
        if (it == available_servers.end()) {
            it = available_servers.begin();
        }
        
        int server_id = *it;
        available_servers.erase(it);
        
        // Assign the request to this server
        request_count[server_id]++;
        busy_servers.emplace(start_time + duration, server_id);
    }
    
    // Find the maximum number of requests handled
    int max_requests = *max_element(request_count.begin(), request_count.end());
    
    // Collect the IDs of the busiest servers
    vector<int> result;
    for (int i = 0; i < k; ++i) {
        if (request_count[i] == max_requests) {
            result.push_back(i);
        }
    }
    
    return result;
}
};
