#include <cstdio>
#include <list>
using namespace std;

struct contestant{
	int score, solved, id;
};
bool comp(contestant a, contestant b)
{
	if (a.score == b.score)
		if (a.solved == b.solved) return a.id<b.id;
		else return a.solved>b.solved;
	else return a.score>b.score;
}
list<contestant> ranks;

int n,t,p,score, problemvals[2005];
list<int> solved[2005];

int main()
{
	scanf("%i%i%i",&n,&t,&p);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=t; j++)
		{
			scanf("%i",&score);
			if (score) solved[i].push_back(j);
			else ++problemvals[j];
		}
		
	contestant curr;
	for (curr.id=1; curr.id<=n; ++curr.id)
	{
		curr.score = 0;
		for (auto it=solved[curr.id].begin(); it!=solved[curr.id].end(); it++)
			curr.score += problemvals[*it];
		curr.solved = solved[curr.id].size();
		ranks.push_back(curr);
	}
	ranks.sort(comp);
	auto it=ranks.begin();
	int i=1;
	for (; it->id != p; it++, i++);
	printf("%i %i\n",it->score,i);
	return 0;
}

