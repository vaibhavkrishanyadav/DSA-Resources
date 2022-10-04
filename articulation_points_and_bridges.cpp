vector<pair<int,int>>bridges;
unordered_set<int>articulation_points;

void articulation_points_and_bridges(vector<vector<int>>&graph,int curr,int time,int parent,vector<bool>&vis,vector<int>&low,vector<int>&disc){

  vis[curr]=true;
  disc[curr]=low[curr]=time;
  int child_count=0; //using this for root node only

  for(auto child:graph[curr]){
      
      //if the child node is not visited ,make a dfs call
     if(!vis[child]){

      child_count++;

      articulation_points_and_bridges(graph,child,time+1,curr,vis,low,disc);
      // now we have all the data for this child node ,check if we can find low discover time using at most one backedge
      low[curr]=min(low[curr],low[child]);

      // edge b/w curr-child is a bridge edge iff
      if(low[child] > disc[curr]){
         bridges.push_back({curr,child});
      }

      // node curr is articulation point iff (we will handle the root node separately)
      if(parent!=0 and low[child] >= disc[curr]){
          articulation_points.insert(curr);
      }

     }
     
     // if the node is visited which means it is a backedge
     else if(child!=parent ){  
         low[curr]=min(low[curr],disc[child]);
     }
      
  }
  // for root node(the starting node)
  if(parent==0 and child_count>1){
    articulation_points.insert(curr);
  }

  return;

}

