//dy,dx
const int coverType[4][3][2] = {
    { {0,0}, {1,0}, {0,1} },
    { {0,0}, {0,1}, {1,1} },
    { {0,0}, {1,0}, {1,1} },
    { {0,0}, {1,0}, {1,-1} }
};

bool set(vector<vector<int>>& board, int y, int x, int type, int delta) {
}

int cover(vector<vector<int>>&board) {
    int y=-1, x=-1;
    for (int i=0; i<board.size(); ++i) {
        for (int j=0; j<board.size(); ++j) {
            if(board[i][j] == 0) {
                y=i;
                x=j;
                break;
            }
        }
        if(y!=-1) break;
    }
    
    //Base case
    if(y==-1) return 1;
    
    int ret=0;
    for (int type=0; type<4; ++type) {
        if(set(board,y,x,type,1))
            ret += cover(board);
        set(board,y,x,type,-1);
    }
    
    return ret;
    
    
}
