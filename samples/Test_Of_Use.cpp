#include <iostream>
#include "TVector.h"
#include "TMatrix.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	cout << "Введите размер матрицы: ";
	cin >> size;
	TMatrix<int> a(5), b(5), c(5),d(size),e(size);
	int i, j;
	cout << "Тестирование программ поддержки представления треугольных матриц" << endl;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
		{
			d[i][j] = i * 10 + j;
			e[i][j] = (i * 10 + j) * 100;
		}
	cout << "Matrix d" << endl << c << endl;
	d = d * 2;
	cout << "Matrix d = a * 2" << endl << c << endl;
	cout << "Matrix e" << endl << e << endl;


	cout << "Тестирование программ поддержки представления треугольных матриц" << endl;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
		{
			a[i][j] = i * 10 + j;
			b[i][j] = (i * 10 + j) * 100;
		}
	c = a + b;
	cout << "Matrix a = " << endl << a << endl;
	cout << "Matrix b = " << endl << b << endl;
	cout << "Matrix c = a + b" << endl << c << endl;
	c = b-a;
	cout << "Matrix c = b - a" << endl << c << endl;
	c = a * b;
	cout << "Matrix c = a * b" << endl << c << endl;

	return 0;
}