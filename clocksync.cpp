const int INF=9999, SWITCHES=10, CLOCKS=16;
const char linked[SWITCHES][CLOCKS+1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

bool areAlligned(const vector<int>& clocks);

void push(vector<int>& clocks, int switch) {
    for(int clock=0; clock<CLOCKS; ++clock) {
        if(linked[switch][clock] == 'x') {
            clocks[clock] += 3;
            if(clocks[clock] == 15) clocks[clock] = 3;
           
        }
    }
}

int solve(vector<int>& clocks, int switch) {
    if(swtich == SWITCHES) return areAlligned(clocks) ? 0:INF;
    
    int ret = INF;
    for (int cnt=0;cnt<4;++cnt) {
        ret = min(ret, cnt + solve(clocks, switch+1));
        push(clocks, switch);
    }
    
    return ret;    
}
