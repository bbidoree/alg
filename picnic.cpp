int n;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
    int firstFree = -1;
    for(int i=0; i<n;++i) {
        if(!taken[i]) {
            firstFree=i;
            break;
        }
    }
    
    //Base Case#1
    if (firstFree==-1) return 1;
    
    int ret=0;
    
}
