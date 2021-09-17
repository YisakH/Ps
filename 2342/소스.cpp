#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;
vector<int> inp;
vector<vector<vector<int>>> dp;
int main()
{
	int input;
	inp.push_back(0);
	scanf("%d", &input);
	while (input != 0) {
		inp.push_back(input);
		scanf("%d", &input);
	}

	dp.assign(inp.size()+1, vector<vector<int>>(5, vector<int>(5, -1)));

	dp[0][0][0] = 0;
	
	for (int i = 1; i < inp.size(); i++) {
		int move = inp[i];

		for (int left = 0; left < 5; left++) {
			for (int right = 0; right < 5; right++) {
				if (dp[i - 1][left][right] == -1) continue;

				if (left == move || right == move) {
					if (dp[i][left][right] > dp[i - 1][left][right] + 1 || dp[i][left][right] == -1)
						dp[i][left][right] = dp[i - 1][left][right] + 1;
				}
				else {
					int next_left_cost;
					if (left == 0)
						next_left_cost = 2;
					else if (abs(move - left) == 2)
						next_left_cost = 4;
					else
						next_left_cost = 3;

					if (dp[i][move][right] == -1 || dp[i][move][right] > dp[i - 1][left][right] + next_left_cost)
						dp[i][move][right] = dp[i - 1][left][right] + next_left_cost;

					if (right == 0)
						next_left_cost = 2;
					else if (abs(move - right) == 2)
						next_left_cost = 4;
					else
						next_left_cost = 3;

					if (dp[i][left][move] == -1 || dp[i][left][move] > dp[i - 1][left][right] + next_left_cost)
						dp[i][left][move] = dp[i - 1][left][right] + next_left_cost;

				}
			}
		}
	}

	int minval = 1000000000;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			if (dp[inp.size()-1][i][j] != -1 && dp[inp.size()-1][i][j] < minval)
				minval = dp[inp.size()-1][i][j];
		}

	printf("%d", minval);
}