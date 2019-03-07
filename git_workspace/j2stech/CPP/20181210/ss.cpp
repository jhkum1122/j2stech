#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
	int n;
//	stringstream ss;
	std::stringstream ss;

	ss.str("12 345 6789 0 -12");

	for (int i = 0; i < 5; i++ ){
		ss >> n;
		cout<< n << endl;
	}

	/*
	ss << 100 << ' ' << 200;

	int foo,bar;

	ss >> foo >> bar;

	std::cout << "foo: " << foo <<'\n';
	std::cout << "bar: " << bar <<'\n';
	*/
	return 0;
}
