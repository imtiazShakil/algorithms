# include <stdio.h>
# include <stdlib.h>
# include <string.h>

#define MAXN 1000050

int a[MAXN];
char s1[MAXN], s2[MAXN];

int main ( ){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int i, j, p, len1, len2;
    while(scanf("%s %s", s1, s2) == 2){

        memset(a, 0, sizeof(a));
        len1 = strlen(s1); len2 = strlen(s2);
        for(i=len1-1; i>=0; i--)
            for(j=len2-1, p=len1-1-i; j>=0; j--){
                a[p++] += (s1[i]-'0')*(s2[j]-'0');
            }
        for(i=0; i<MAXN; i++){
            a[i+1] += a[i]/10;
            a[i] %= 10;
        }

        for(i=MAXN-1; i>=0; i--) if(a[i]) break;
        if(i==-1) printf("0");
        else for(; i>=0; i--) printf("%d", a[i]);
        putchar('\n');
    }

    return 0;
}
