#include <iostream>
#include <cmath>
using namespace std;
double S0(const int j, const int N)
{
	double s = 0;
	for (int i = j; i <= N; i++)
		s += ((j*(N-j))/(pow(j,2)+pow(N-j,2)));
	return s;
}
double S1(const int j, const int N, const int i)
{
	if (i > N)
		return 0;
	else
		return ((j * (N - j)) / (pow(j, 2) + pow(N - j, 2))) + S1(j, N, i + 1);
}
double S2(const int j, const int N, const int i)
{
	if (i < j)
		return 0;
	else
		return ((j * (N - j)) / (pow(j, 2) + pow(N - j, 2))) + S2(j, N, i - 1);
}
double S3(const int j, const int N, const int i, double t)
{
	t = t + ((j * (N - j)) / (pow(j, 2) + pow(N - j, 2)));
	if (i >= N)
		return t;
	else
		return S3(j, N, i + 1, t);
}
double S4(const int j, const int N, const int i, double t)
{
	t = t + ((j * (N - j)) / (pow(j, 2) + pow(N - j, 2)));
	if (i <= j)
		return t;
	else
		return S4(j, N, i - 1, t);
}

int main()
{
	int j=2, N;
	cout << "j =  2" << endl;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << S0(j, N) << endl;
	cout << "(rec up ++) S1 = " << S1(j, N, j) << endl;
	cout << "(rec up --) S2 = " << S2(j, N, N) << endl;
	cout << "(rec down ++) S3 = " << S3(j, N, j, 0) << endl;
	cout << "(rec down --) S4 = " << S4(j, N, N, 0) << endl;
	return 0;
}