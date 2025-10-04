class Solution {
public:
    void dfs(int i ,vector<vector<int>>&adjl , vector<int>& visited ){
        for(auto s : adjl[i]){
            if(!visited[s]){
                visited[s]=1;
                dfs(s,adjl,visited);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<int> visited(n ,0);
        vector<vector<int>>adjl(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if((isConnected[i][j] == 1) && (i != j)){
                   adjl[i].push_back(j);
                   adjl[j].push_back(i);
                }
            }
        }
    
        int count =0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i , adjl,visited);
                count++;
                
            }
        }
        return count;
    }
};
