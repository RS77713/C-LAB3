
#include <iostream>
#include <vector>
#include <cmath>
//#include <cmath>

using namespace std;

//int main() {
//int taskVarCount = 16;
//int studentCode = 83994;
//
//int taskNr = studentCode % taskVarCount;
//cout << "Task number is: " << taskNr << endl;
	//task 10

	//Task 10 -  Input: integer numbers a, b, c, d. Find all integer roots of equation ax³+bx²+cx+d=0 (search roots among possible divisors of number d).

bool isRoot(double a, double b, double c, double d, double x, double tolerance = 1e-6) {
	double value = a * x * x * x + b * x * x + c * x + d; // avoiding float point precision using pow(x,3) and replacing 0 with 1e-6
	return abs(value) < tolerance && abs(x) >= tolerance;
}
	vector<double> findRealRoots(double a, double b, double c, double d){
		vector<double> realRoots;
		double i = -1000.0;
		while (i <= 1000.0) {
			if (isRoot(a, b, c, d, i)) {
				realRoots.push_back(i);
			}
			i += 0.1;
		}
	return realRoots;
}


	int main() { // Validation part
		double a, b, c, d;
		cout << "Enter the coefficients of the cubic equation: " << endl;

		while (true) {
			cout << "a: ";
			cin >> a;

			if (cin.fail()){
				cin.clear(); //-error clear
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard invalid input
					cout << "Invalid input! Please enter valid integer for a!" << endl;
			}
			else {
				break;
			}
		}
		cout << "b: ";
		cin >> b;

		cout << "c: ";
		cin >> c;

		cout << "d: ";
		cin >> d;
		
		vector<double> roots = findRealRoots(a, b, c, d);
		if (roots.empty()){
			cout << "No int root found!" << endl;
		}
		else {
			cout << "Integer roots: ";
			for (double root : roots){
				cout << root << " ";
			}
			cout << endl;
		}
		return 0;
	}
