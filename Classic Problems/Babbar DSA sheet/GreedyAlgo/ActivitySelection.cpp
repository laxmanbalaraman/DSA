class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool comp(pair<int, int> a, pair <int, int> b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector <pair<int, int>> meeting(n);
        for(int i = 0; i < n; i++){
            meeting[i] = {start[i], end[i]};
        }
        
        sort(meeting.begin(), meeting.end(), comp);
        
        int ans = 1;
        int fin = meeting[0].second;
        for(int i = 1; i < n; i++){
            if (fin < meeting[i].first){
                fin = meeting[i].second;
                ans++;
            }
        }
        return ans;
    }
};