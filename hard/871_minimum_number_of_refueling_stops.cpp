class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        priority_queue<int> pq; //max heap
       
		
        int curr = startFuel; //my current position
        int i = 0; //station index
        int result = 0;
        while(curr < target) { //until I reach my target
            while(i < n && curr >= stations[i][0]) {
                
                pq.push(stations[i][1]);
				//Keep the station at top which can take me farthest (maximum gas)
                i++;
            }
            
            if(pq.empty()) //we can't move further now
                return -1;
            
            int dist = pq.top();
            pq.pop();
            
            curr += dist;
            result++;
        }
        
        return result;
        
    }
};