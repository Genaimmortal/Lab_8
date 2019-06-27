#include <iostream>
#include <limits>
using namespace std;
double * normirovanie (int const razmer, double * massive)
{
	double max = numeric_limits<double>::min(), 
	       min = numeric_limits<double>::max();
	for (int i=0; i<razmer; i++) {
	if (max < massive[i])
		max = massive[i];
	else if (min > massive[i])
			 min = massive[i];
	}
	double *now = new double [razmer];
	for (int i=0; i<razmer; i++) {
		massive[i]=(massive[i]- min)/(max-min);
		now[i]=massive[i];
	}
	return now;
	delete[] now;
}
int main()
{
	int Razm;
	cout << "Укажите размер массива: " << endl;
	cin >> Razm;
	double * Mas = new double [Razm];
	cout << "Введите значения массива: " << endl;
	for(int i=0; i < Razm ; i++) {
		cin >> Mas[i];
	}
	Mas = normirovanie(Razm,Mas);
	for(int i=0; i<Razm; i++) {
		cout << *(Mas+i) << endl; // Указатель
	}
	delete[] Mas;
	return 0;
}
