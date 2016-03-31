// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

bool collatz_read (istream& r, int& i, int& j) 
{
    if (!(r >> i))
        return false;

    r >> j;

    return true;
}

// -----------------
// collatz_length
// -----------------

int cycle_length(int n) 
{
	assert(n > 0);

	int i = 1;

	while (n > 1) 
	{
		if ((n % 2) == 0)
			n = (n / 2);
		else
			n = (3 * n) + 1;
		++i;
	}
	assert(i > 0);
	return i;
}


// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) 
{
    // <your code>
	int b; int maxlen = 0;

	for (b = i; b < j; b++)
	{
		int len = cycle_length(b);
		if (len > maxlen)
			maxlen = len;
	}

	return maxlen;

}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) 
{
    w << i << " " << j << " " << v << endl;
}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) 
{
    int i;
    int j;

    while (collatz_read(r, i, j)) 
	{
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);
	}
}

/*int main() {
	using namespace std;
	collatz_solve(cin, cout);
	return 0;
}*/
