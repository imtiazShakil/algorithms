//0 based
int m[2*lim+1]; //length of the longest palindrome centered at the index

int manacher(string &s)
{
    int len = s.size();
    if(len == 0) return -1;
    mem(m,0);
    m[0] = 0;
    m[1] = 1;
    // "cur" is the current center
    // "r" is the right bound of the palindrome
    // that centered at current center
    int cur, r;
    r = 2;
    cur = 1;
    int ma=1;
    for(int p2=2; p2<2*len+1; p2++)
    {
        int p1 = cur- (p2-cur);
        //if p1 is negative, we need to
        //move "cur" forward
        while(p1 < 0)
        {
            cur++;
            r = m[cur] + cur;
            p1 = cur- (p2-cur);
        }
        //If the first character of t is
        //strictly on the right of the
        // first character of s
        if(m[p1] < r - p2)
            m[p2] = m[p1];
        //otherwise
        else
        {
            //reset "cur"
            cur = p2;
            int k = r-p2;
            if(k<0) k = 0;
            while(1)
            {
                if((p2+k+1)&1)
                {
                    if(p2+k+1 < 2*len+1 && p2-k-1 >=0 && s[(p2+k)/2] == s[(p2-k-2)/2])
                        k++;
                    else break;
                }
                else
                {
                    if(p2+k+1 < 2*len+1 && p2-k-1 >=0)
                        k++;
                    else break;
                }

            }
            r = p2+k;
            m[p2] = k;
            ma=max(ma,k);
        }
    }
    return ma;
}


int main()
{
    string s;
    while(cin>>s)
    {
        print1(manacher(s));
    }
    return 0;
}
