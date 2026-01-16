#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 30;

double scalar_proizv(const vector<double>& p, const vector<double>& q) {
	double result = 0.0;
	for (int i = 1; i < N; i++) {
		result += p[i] * q[i];

	}
	return result;
}

double find_min(const vector<double>& vec) {
	double min_val = vec[0];
	for (int i = 1; i < N; i++) {
		if (vec[i] < min_val) {
			min_val = vec[i];
		}
	}
	return min_val;
}

double find_max(double a, double b, double c) {
	return max(a, max(b, c));
}

int main() {
	setlocale(LC_ALL, "rus");
	vector < double > x(N), y(N), z(N);
	vector < double > a, b, c;

	cout << "Введите " << N << " элементов вектора x: " << endl;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	cout << "Введите " << N << " элементов вектора y: " << endl;
	for (int i = 0; i < N; i++) {
		cin >> y[i];
	}
	cout << "Введите " << N << " элементов вектора z: " << endl;
	for (int i = 0; i < N; i++) {
		cin >> z[i];
	}


	double min_x = find_min(x);
	double min_y = find_min(y);
	double min_z = find_min(z);

	double max_min = find_max(min_x, min_y, min_z);

	if (max_min == min_x) {
		a = x;
		b = y;
		c = z;
	}
	else if (max_min == min_y) {
		a = y;
		b = x;
		c = z;

	}
	else {
		a = z;
		b = x;
		c = y;

	}


	double result = scalar_proizv(a, a) - scalar_proizv(b, c);

	cout << "Результат выражения (a,a) - (b,c) = " << result << endl;

	return 0;
}