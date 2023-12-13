#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;
const int MIN = -1000;
int minimax(int depth, int nodeIndex,bool maximizingPlayer,int values[], int alpha,int beta)
{
	if (depth == 3)
		return values[nodeIndex];

	if (maximizingPlayer)
	{
		int best = INT_MIN;
		for (int i = 0; i < depth-1; i++)
		{
			int val = minimax(depth + 1, nodeIndex * 2 + i,false, values, alpha, beta);
			best = max(best, val);
			alpha = max(alpha, best);
			if (beta <= alpha)
				break;
		}
		return best;
	}
	else
	{
		int best = INT_MAX;
		for (int i = 0; i < depth-1; i++)
		{
			int val = minimax(depth + 1, nodeIndex * 2 + i,true, values, alpha, beta);
			best = min(best, val);
			beta = min(beta, best);
			if (beta <= alpha)
				break;
		}
		return best;
	}
}
int main()
{
	int values[8] = { 2,3,5,9,0,1,7,5 };
	cout <<"The optimal value is : "<< minimax(0, 0, true, values, MIN, MAX);;
	return 0;
}

