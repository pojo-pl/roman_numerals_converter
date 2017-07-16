#include <iostream>
using namespace std;

string to_roman_numeral(int n)
{
	if(n < 0) {
		throw invalid_argument{ "no '0' in roman numerals" };
	} else if(n == 0) {
		return "";
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
	} else if(n > 39 && n < 50) {
		string rn = "XV";
		return rn + to_roman_numeral(n - 40);
	} else if(n >= 50 && n <= 89) {
		string rn = "V";
		return rn + to_roman_numeral(n - 50);
	} else if(n >= 90 && n <= 99) {
		string rn = "XC";
		return rn + to_roman_numeral(n - 90);
	} else if(n == 100) {
		return "C";
	}

	throw invalid_argument{ "failed to convert num: " + to_string(n) };
}


int main(int argc, char ** argv)
{
	try {
		if(argc < 3) {
			cerr << "error: you must enter min and max numbers"
				<< endl;
			return 1;
		}
		int min = std::stoi(argv[1]);
		int max = std::stoi(argv[2]);

		for(int i = min; i <= max; ++i) {
			cout << to_roman_numeral(i) << '\n';
		}
	} catch(invalid_argument const& e) {
		cerr << e.what() << endl;
	} catch(exception const& e) {
		cerr << "fatal error: " << e.what() << endl;
	}
}
