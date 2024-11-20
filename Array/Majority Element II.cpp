// Problem Link : https://www.geeksforgeeks.org/problems/majority-vote/1

vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
      int x = -1, y = -1, cx = 0, cy = 0, n = arr.size();
      
      for(int i=0; i<n; i++){
          if(cx == 0 && y != arr[i]){
              x = arr[i];
              cx = 1;
          }
          else if(cy == 0 && x != arr[i]){
              y = arr[i];
              cy = 1;
          }
          else if(x == arr[i])    cx++;
          else if(y == arr[i])    cy++;
          else{
              cx--;
              cy--;
          }
      }
      
      int half = n/3;
      cx = 0, cy = 0;
      
      for(int i=0; i<n; i++){
          if(x == arr[i]) cx++;
          if(y == arr[i]) cy++;
      }
      
      if(x > y){
          swap(x,y);
          swap(cx,cy);
      }
      
      if(cx > half && cy > half)  return {x,y};
      else if(cx > half)  return {x};
      else if(cy > half)  return {y};
      else return {};
  }
