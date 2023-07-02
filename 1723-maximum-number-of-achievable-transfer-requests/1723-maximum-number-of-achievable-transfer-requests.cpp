class Solution {
private:
    void process(const vector<vector<int>>& requests, vector<int>& capacity, int reqId, int reqProcessed, int& maxRequests){
    	//Base case: Processed all the requests, wind up.
        if(reqId == requests.size()){
        	//Check if all the buildings are balanced ( 0 incoming-0 outgoing)
            for(auto cap : capacity)if(cap != 0){
                return;
            }            
            //All the building are balanced, check and update max Req.
			maxRequests = max(maxRequests, reqProcessed);                
            return;
        }
        
        //Check without processing this request.
        process(requests, capacity, reqId+1, reqProcessed, maxRequests);
        
        //Check with processing this request.
        //Update incoming and outgoing building requests.
        capacity[requests[reqId][0]]--; capacity[requests[reqId][1]]++;
		
       	process(requests, capacity, reqId+1, reqProcessed+1, maxRequests);
        
        //Rollback the changes.
        capacity[requests[reqId][0]]++;   capacity[requests[reqId][1]]--;
    }

public:    
    int maximumRequests(int n, vector<vector<int>>& requests) {        
        vector<int> capacity(n, 0);
        int maxRequests;
        //Recur and process the requests.
        process(requests, capacity, 0, 0, maxRequests);
        return maxRequests;        
    }
};