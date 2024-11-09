// Problem Link : https://www.naukri.com/code360/problems/reach-the-destination_992853

bool reachDestination(int sx, int sy, int dx, int dy) {
    // Write your code here
    if(sx == dx && sy == dy)    return true;
    if(dx< sx || dy < sy)    return false;
    
    if(dx > dy)    return reachDestination(sx, sy, dx-dy, dy);
    else return reachDestination(sx, sy, dx, dy-dx);
}
