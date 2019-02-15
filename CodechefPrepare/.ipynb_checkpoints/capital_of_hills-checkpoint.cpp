#include <iostream>
#include <stack>
#include <queue>
#include <algorithms>

using namespace std;


/*


#include <bits/stdc++.h>
using namespace std;
int N;
pair<int, int> A[100000];
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i].first), A[i].second=i;
    sort(A, A+N, greater<pair<int, int>>());
    int a=A[0].second, b=A[0].second;
    int ans=0;
    for(int i=1; i<N; i++)
    {
        int x=A[i].second;
        if(x<a || x>b)
            ans++;
        else
            ans+=2;
        a=min(a, x);
        b=max(b, x);
    }
    printf("%d\n", ans);
    return 0;
}

*/

int main()
{
    int n;
    cin >> n;
    
    pair<int, int> ar[n + 1];
    
    for(int i = 0; i < n; i++)
    {
        cin >> ar[i].first;
        ar[i].second = i;
    }
    
    sort(ar, ar + n, greater<pair<int, int> >());
    int a = ar[0].second, b = ar[0].second;
    
    int ans = 0;
    
    for (int i = 1; i < n; i++)
    {
        int x = ar[i].second;
        
        if (x < a || x > b)
        {
            ans++;
        }
        else
        {
            ans += 2;
        }
        
        a = min(a, x);
        b = max(b, x);
    }
    
    cout << ans << endl;
    return 0;
    
}