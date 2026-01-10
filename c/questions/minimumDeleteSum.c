#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minimumDeleteSum(char* s1, char* s2) {
    int s1s = 0;
    int s2s = 0;
    int pre;
    int tmp;
    int total = 0;
    for (; s1[s1s]; s1s++) {
        total += s1[s1s];
    }
    for(; s2[s2s]; s2s++) {
        total += s2[s2s];
    }
    int rs[s1s+1];
    for (int p=0; p<s1s+1; p++) {
        rs[p] = 0;
    }
    
    for (int p2=0; p2<s2s; p2++) {
        pre = 0;
        for (int p1=0; p1<s1s; p1++) {
            if (s1[p1] == s2[p2]) {
                tmp = pre + s1[p1];
                pre = rs[p1+1];
            } else {
                tmp = MAX(rs[p1+1], rs[p1]);
                pre = rs[p1+1];
            }
            rs[p1+1] = tmp;
        }
    }
    return total-rs[s1s]*2;
}
