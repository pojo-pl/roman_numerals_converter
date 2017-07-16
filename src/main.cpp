#include <iostream>
using namespace std;

/*
1 - I
2 - II
3 - III
4 - IV
5 - V
6 - VI
7 - VII
8 - VIII
9 - IX
10 - X
*/

string to_roman_numeral(int n)
{
	if(n < 0) {
		throw invalid_argument{ "no '0' in roman numerals" };
	} else if(n == 0) {
		return "nulla";
	} else if(n <= 3) {
		string rn;
		rn.reserve(n);
		while(n-- > 0) {
			rn += 'I';
		}
		return rn;
	} else if(n == 4) {
		return "IV";
	} else if(n >=5 && n < 9) {
		n = (n - 9) + 4;
		string rn;
		rn.reserve(n + 1);
		rn += 'V';
		for(int i = 0; i < n; ++i) {
			rn += 'I';
		}
		return rn;
	} else if(n == 9) {
		return "IX";
	} else if(n == 10) {
		return "X";
	} else if(n > 10 && n <= 39) {
		string rn = "X";
		return rn + to_roman_numeral(n - 10);
	}

	throw invalid_argument{ "failed to convert num: " + to_string(n) };
}


int main()
{
	try {
		for(int i = 1; i <= 40; ++i) {
			cout << to_roman_numeral(i) << '\n';
		}
	} catch(invalid_argument const& e) {
		cerr << e.what() << endl;
	} catch(exception const& e) {
		cerr << "fatal error: " << e.what() << endl;
	}
}
