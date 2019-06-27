#include <iostream>
#include <limits>
using namespace std;
void normirovanie (int const razmer, double * massive)
{
	double max = numeric_limits<double>::min(),
		   min = numeric_limits<double>::max();
	for (int i=0; i<razmer; i++) {
	if (max < massive[i])
		max = massive[i];
	else if (min > massive[i])
	min = massive[i];}
	for (int i=0; i<razmer; i++) {
	massive[i]=(massive[i]- min)/(max-min);}
	for (int i=razmer-1; i>=1; i--)
	for (int j=0; j<i; j++) {
	if (massive[j] > massive[j+1]) {
	double MASS = massive[j];
	massive[j] = massive[j + 1];
	massive[j+1] = MASS;}
		}
}
int main()
{
	int Razm;
	cout << "Укажите размер массива: " <<endl;
	cin >> Razm;
	double * Mas = new double [Razm];
	cout << "Введите значения массива: " <<endl;
	for(int i=0; i<Razm ; i++) {
	cin >> Mas[i];}
	normirovanie (Razm,Mas);
	for(int i=0; i<Razm ; i++) {
		cout << "Результат нормировки: " << endl;
	cout << Mas[i] << endl;}
	delete[] Mas;
	return 0;
}
