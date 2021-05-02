#include <vector>
#include <unordered_map>
using namespace std;

int n, values[1000005], sumL, sumR, ans;
unordered_map<int,vector<int>> emf;

int main()
{
    scanf("%d",&n);
    emf[0].push_back(0);
    for (int i=1; i<=n; i++)
    {
        scanf("%d",&values[i]);
        sumL += values[i];
        emf[sumL].push_back(i);
    }
    
    ans = n-emf[0].back();
    for (int i=n; i>0; i--)
    {
        emf[sumL].pop_back();
        if (emf[sumL].empty()) emf.erase(sumL); 
        sumL -= values[i];
        sumR += values[i];
        if (emf.count(sumR))
          ans = min(ans, i-emf[sumR].back()-1);
    }
    printf("%d\n",ans);
}

