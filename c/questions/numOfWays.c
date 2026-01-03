int numOfWays(int n) {
    const int MOD = 1000000007;
    int lt = 12;
    int lineType[lt];
    int cnt = 0;
    for (int b3=0; b3<3; b3++) {
        for (int b2=0; b2<3; b2++) {
            for (int b1=0; b1<3; b1++) {
                if (b3==b2 || b2==b1) {
                    continue;
                }
                lineType[cnt++] = b3*100+b2*10+b1;
            }
        }
    }
    int nextLine[lt][lt] = {};
    for (int cr=0; cr<lt; cr++) {
        int cb1 = lineType[cr] % 10;
        int cb2 = lineType[cr] / 10 % 10;
        int cb3 = lineType[cr] / 100;
        for (int nr=0; nr<lt; nr++) {
            int nb1 = lineType[nr] % 10;
            int nb2 = lineType[nr] / 10 % 10;
            int nb3 = lineType[nr] / 100;
            if (cb1!=nb1 && cb2!=nb2 && cb3!=nb3) {
                nextLine[cr][nr] = 1;
            } else {
                nextLine[cr][nr] = 0;
            }
        }
    }
    int fullMap[n+1][lt] = {};
    for (int p=0; p<lt; p++) {
        fullMap[0][p] = 0;
        fullMap[1][p] = 1;
    }
    for (int r=2; r<=n; r++) {
        for (int pt=0; pt<lt; pt++) {
            for (int ct=0; ct<lt; ct++) {
                if (nextLine[pt][ct] == 1) {
                    fullMap[r][ct] += fullMap[r-1][pt];
                    fullMap[r][ct] %= MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int t=0; t<lt; t++) {
        ans += fullMap[n][t];
        ans %= MOD;
    }
    return ans;
}
