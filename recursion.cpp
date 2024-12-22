#include <iostream>
#include <cmath>
using namespace std;

double fX(const double x, const double n) {
	return ((pow(-1.0, n + 1.0)) * ((pow(x, 2.0 * n + 1.0)) / (4.0 * (pow(n, 2)) - 1)));
}
double recFun(const double x, double n, double& sum) {
	if (n <= 1)
		return fX(x, n);
	sum += fX(x, n);
	return recFun(x, n - 1, sum) + recFun(x, n - 2, sum);
}

int main() {
	double sum_g = 0.0;
	setlocale(LC_ALL, "rus");
	cout << "Введите значение для n > 1: ";
	int n;
	cin >> n;
	cout << "Введите значение для x: ";
	int x;
	cin >> x;
	//Параметр sum_g меняется по ссылке в вызываемой рекурсии
	recFun(static_cast<double>(x), static_cast<double>(n), sum_g);
	cout << sum_g << endl;
	system("pause");
	return 0;
}


