
const int dx[8] = {-1, -1, -1,  1, 1, 1,  0, 0 };
const int dy[8] = {-1,  0,  1, -1, 0, 1, -1, 1 };

bool hasWord(int y, int x, const string& word) {
    //Base Case#1
    if(!inRange(y,x) return false;
    //Base Case#2
    if(board[y][x] != word[0]) return false;
    //Base Case#3
    if(word.size()==1) return true;
    
    for(int direction=0; direction<8; ++direction) {
        int nextY = y+y[direction];
        int nextX = x+x[direction];
        
        if(hasWord(nextY, nextX, word.substr(1))
            return true;
    }
    return false;s
}
