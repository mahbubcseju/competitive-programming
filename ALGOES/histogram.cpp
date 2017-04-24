int main()
{
    int tc;
    S(tc);
    for(int t=1; t<=tc; t++)
    {
        int n;
        S(n);
        int  a[n+2];
        for(int i=1; i<=n; i++)
        {
            S(a[i]);
        }

        int mx=0;
            int d[n+2];
            SET(d);
            stack<int> s;
            for(int j=1; j<=n; j++)
            {
                while(!s.empty())
                {
                    if(a[j]<=a[s.top()])s.pop();
                    else break;
                }
                int l;
                if(s.size()==0)l=0;
                else l=s.top();
                d[j]+=j-l-1;
                s.push(j);
            }
            while(!s.empty())s.pop();

            for(int j=n; j>=1; j--)
            {
                while(!s.empty())
                {
                    if(a[j]<=a[s.top()])s.pop();
                    else break;
                }
                int l;
                if(s.size()==0)l=n+1;
                else l=s.top();
                d[j]+=(l-j-1);
                s.push(j);
            }
            for(int j=1; j<=n; j++)
           {

                mx=max(mx,(d[j]+1)*a[j]);
            }


        PT(t);
        P(mx);
    }
    return 0;
}

