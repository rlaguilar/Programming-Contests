/*
	Author:			Reynaldo Lázaro Aguilar Casajuana
	
	Nickname:		rlac
	
	Date:			22/02/13 14:01
	
	Topic:			Strings - Manacher
	
	Description: 	rad[i] = If i is odd, it's the largest even palindrome centered at position i / 2.
							 Otherwise, it's the size of the largest odd palindrome centered at 
							 position i / 2.
	
	Complexity:		build_rad = O(N)					
					is_palindrome = O(1)	
	
  	Verified:		TIMUS 1937. Davy Jones’s Organ (Best solution)
*/

#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#ifdef RLAC
	#define DEB(a)			clog << __LINE__ << ": " << #a << " = " << (a) << endl
	#define DEB2(a, b)		DEB(a); DEB(b)
	#define OUT(a, n)		for (int J = 0; J < (n); ++J)	clog << (a)[J] << " \n"[J == (n) - 1];
	#define OUT2(a, n, m)	{	DEB(a);	for (int I = 0; I < (n); ++I)	OUT(a[I], m);	}
	#define NAME			"manacher"
#else
	#define DEB(a)
	#define DEB2(a, b)
	#define OUT(a, n)
	#define OUT2(a, n, m)
#endif

using namespace std;

typedef complex<double> point;
typedef long long ll;
typedef pair<int, int> ii;

const int LEN = 1e5 + 5;
char s[LEN];
int rad[2 * LEN], n;

//WARNING: n = 2 * strlen(s)
void build_rad ()
{
	for (int i = 0, j = 0, k; i < n; i += k, j = max(j - k, 0))
	{
		for (; i >= j && i + j + 1 < n && s[(i - j) / 2] == s[(i + j + 1) / 2]; ++j);
		
		rad[i] = j;
		
		for (k = 1; i >= k && rad[i] >= k && rad[i - k] != rad[i] - k; ++k)
			rad[i + k] = min(rad[i - k], rad[i] - k);
	}
}

//WARNING: n = strlen(s)
bool is_palindrome (int b, int e)
{
	return b >= 0 && e < n &&  rad[b + e] >= e - b + 1;
}
