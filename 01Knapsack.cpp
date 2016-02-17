#include <iostream>
#include <stdio.h> 
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "timer.h"

using namespace std;

vector<int> v, c;
vector< vector<int> > DP;

void pick(int i, int w)
{
	if (i <= 0 || w <= 0) return;

	int k = DP[i][w];
	if (k != DP[i - 1][w]) {
		cout << i << "\t\t" << c[i] <<"\t\t" << v[i] << " RM" <<endl; // select!
		pick(i - 1, w - c[i]); // capacity decreases
	} else {
		// move on to next item; capacity no change
		pick(i - 1, w);
	}
}

int main()
{
	int S, N; 
	cout << "Enter Total Jobs: ";
	cin >> N;
	cout << endl;
	cout << "Enter Maximum capacity: ";
	cin >> S;

	// sloted for easy array access; values won't be used.
	c.push_back(-1);
	v.push_back(-1);
		srand (1);
	for (int i = 0; i < N; i++) {
		c.push_back(1 + rand() % 12);
		v.push_back(1 + rand() % 50);
	}

	DP.resize(N + 1, vector<int>(S + 1, 0));

// Start of the 01 KnapSack Alogrithm
//TICK();

	for (int i = 1; i <= N; i++) { // i is scope of items in consideration
		for (int w = 1; w <= S; w++) { // j is max size of bag
			if (c[i] > w) {
				DP[i][w] = DP[i - 1][w];
			} else {
				DP[i][w] = max(DP[i - 1][w], v[i] + DP[i - 1][w - c[i]]);
			}
		}
	}
//TOCK(); // end of the alogrithm
	
	cout << "Selected\n";
	cout << "Job no.\tWoriking hours\t\tSalary\n";
	pick(N, S);
	cout << endl;
	cout << "Jobs Size: " << N << endl;
	cout << "Maximum Working Hour: " << S << endl;
	cout <<"Totoal Benefit: " <<DP[N][S]<< " RM"<< endl; 
//	cout << "Elapsed Time: " << DURATION() << " seconds" << endl;

}