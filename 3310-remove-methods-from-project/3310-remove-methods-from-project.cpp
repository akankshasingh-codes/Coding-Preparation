class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n); //u--> {ngbr1, ngbr2}
        vector<int>inDegree(n, 0);
        vector<bool>suspicious(n, false);


        for(auto &edge: invocations) //making adj list and storing indegree of each node
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        //bfs 
        queue<int>que;
        que.push(k);
        suspicious[k]= true; // given suspicious node

        while(!que.empty())
        {
            int curr = que.front();
            que.pop();

            for(int &ngbr: adj[curr])
            {
                inDegree[ngbr]--;
                if(!suspicious[ngbr])
                {
                    que.push(ngbr);
                    suspicious[ngbr] = true; // mark suspicious because directly or indirectly current node is connect to suspicious node
                }
            }
        }

        vector<int>res;
        bool cannotRemove = false;
        for(int i =0;i<n;i++)
        {
            if(suspicious[i] == true && inDegree[i] > 0) // unsuspicious node is coming to suspicious node so can not remove any node 
            {
                cannotRemove = true;
                break;
            }
            if(!suspicious[i])
                res.push_back(i);
        }

        if(cannotRemove == true)
        {
            vector<int>vec(n);
            for(int i = 0;i<n;i++)
                vec[i] = i;

            return vec;

        }

        return res;
        //t.c = 0(v + E)
        //s.c = 0( V + E)

        
    }
};