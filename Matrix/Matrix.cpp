#include <iostream>
#include<fstream>
#include <string>
using namespace std;
template <typename T>
class Array {
private:
	T* a = 0; // указатель на массив
	unsigned int size = 0; // размер массива
public:
	Array(); // конструктор по умолчанию
	Array(int s); // конструктор с аргументом(размером массива)
	~Array(); // деструктор
	int& operator[](int index); // оператор индексации
	void setarrayzero(int k); // создание нулевой матрицы
	void setarray(int n); // метод ввода матрицы с клавиатуры построчно
	void getarray(int n); // вывод содержимого матрицы построчно
	void SetNum(int N, int M, int n);// установка значения элемента матрицы с индексами i, j;
	void GetNum(int N, int M, int n);// получение значения элемента матрицы с индексами i, j;
	void writing_to_a_file(ofstream& fout, int n);// запись матрицы в файл (первое число файла – размер матрицы)
};
template <typename T>
Array<T>::Array() {
	size = 10;
	a = new T[size];
	for (size_t i = 0; i != size; i++) {
		a[i] = 0;
	}
}
template <typename T>
Array<T>::Array(int s) {
	if (s > 0) {
		size = s;
		a = new T[size];
		for (size_t i = 0; i != size; i++) {
			a[i] = 0;
		}
	}
	else cout << "Size can't be negativ";
}
template <typename T>
Array<T>::~Array() {
	delete[]a;
}
template <typename T>
int& Array<T>::operator[](int index) {
	if (size_t(index <= size)) {
		return a[index];
	}
}
template <typename T>
void Array<T>::setarrayzero(int k)
{
	for (int i = 0; i < k; i++)
	{
		a[i] = 0;
	}
}
template <typename T>
void Array<T>::setarray(int n) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите числа не равные нулю через пробел для строки №" << i + 1 << endl;
		int count1 = 0;
		for (int z = 0; z <= i; z++)
		{
			cin >> a[count];
			count++;
			count1++;
		}
		for (int z1 = 0; z1 <= n - count1 - 1; z1++)
		{
			cout << "0" << " ";
		}
		cout << endl;
	}
}
template <typename T>
void Array<T>::getarray(int n) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "Строка №" << i + 1 << endl;
		int count1 = 0;
		for (int z = 0; z <= i; z++)
		{
			cout << a[count] << " ";
			count++;
			count1++;
		}
		for (int z1 = 0; z1 <= n - count1 - 1; z1++)
		{
			cout << "0" << " ";
		}
			cout << endl;
	}
}
template <typename T>
void Array<T>::SetNum(int N, int M, int n) {
	cout << "Новое значение" << endl;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int count1 = 0;
		for (int z = 0; z <= i; z++)
		{
			count1++;
			if ((i == N - 1) && (count1 == M))
			{
				cin >> a[count];
				cout << endl;
				break;
			}
			count++;
		}
	}
}
template <typename T>
void Array<T>::GetNum(int N, int M, int n) {
	cout << "Этот элемент равен:" << endl;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int count1 = 0;
		for (int z = 0; z <= i; z++)
		{
			count1++;
			if ((i == N - 1) && (count1 == M))
			{
				cout << a[count];
				cout << endl;
				break;
			}
			count++;
		}
	}
}
template <typename T>
void Array<T>::writing_to_a_file(ofstream& fout, int n) {
	int count = 0;
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << "Строка №" << i + 1 << endl;
		int count1 = 0;
			for (int z = 0; z <= i; z++)
			{
				fout << a[count] << " ";
				count++;
				count1++;
			}
		for (int z1 = 0; z1 <= n - count1 - 1; z1++)
		{
			fout << "0" << " ";
		}
		fout << endl;
	}
	fout.flush();
}
int read(ofstream& fout)
{
	std::string line;
	std::ifstream in("C:\\Users\\Clown\\Desktop\\kurs\\Matrix\\matrix.txt"); //открываем файл для чтения
		if (in.is_open())
		{
			while (getline(in, line))
			{
				std::cout << line << std::endl;
			}
		}
	in.close();// закрываем файл
	return 0;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	ofstream fout("matrix.txt");
	int x, y, n, N, M, k = 0;
	bool f1 = false;
	bool f2 = false;
	bool f3 = true;
	cout << "Введите размер матрицы " << endl;
	cout << "n = ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		k += i;
	}
	Array<int> arr(k);// Объявление матрицы A
	Array<int> ar(k);// Объявление матрицы B
	Array<int> arrr(k);// Объявление матрицы суммы A и B
	while (f1 == false)
	{
		cout << "1 - Создать нулевую матрицу" << endl << "2 - Ввести треугольную матрицу" << endl << "3 - Показать матрицу" << endl << "4 - Изменить значение элемента матрицы, находящегося ниже нулевых значений" << endl << "5 - Вывести значение элемента матрицы, находящегося ниже нулевых значений" << endl << "6 - Начать работу с матрицей B" << endl << "7 - Приравнять матрицу A к матрице B" << endl << "8 - Завершить работу" << endl;
			cin >> x;
		switch (x)
		{
		case 1:
			arr.setarrayzero(k);//создание нижней треугольной матрицы заданного размера с нулевыми значениями всех элементов;
			break;
		case 2:
			arr.setarray(n);//построчный ввод матрицы;
			break;
		case 3:
			arr.getarray(n);//построчный вывод матрицы;
			break;
		case 4:// установка значения элемента матрицы с индексами i, j;
			cout << "Введите номер строки" << endl;
			cin >> N;
			cout << "Введите номер столбца" << endl;
			cin >> M;
			arr.SetNum(N, M, n);
			break;
		case 5:// получение значения элемента матрицы с индексами i, j;
			cout << "Введите номер строки" << endl;
			cin >> N;
			cout << "Введите номер столбца" << endl;
			cin >> M;
			arr.GetNum(N, M, n);
			break;
		case 6:// Работа с матрицей B
			while (f2 == false)
			{
				cout << "1 - Создать нулевую матрицу" << endl << "2 - Ввести треугольную матрицу" << endl << "3 - Показать матрицу" << endl << "4 - Изменить значение элемента матрицы, находящегося ниже нулевых значений" << endl << "5 - Вывести значение элемента матрицы, находящегося ниже нулевых значений" << endl << "6 - Сумма матриц A и B" << endl << "7 - Сравнить матрицу A с B" << endl << "8 - Приравнять матрицу B к матрице A" << endl << "9 - Начать работу с матрицей A" << endl;
				cin >> y;
				switch (y)
				{
				case 1://создание нижней треугольной матрицы заданного размера с нулевыми значениями всех
				//элементов;
					ar.setarrayzero(k);
					break;
				case 2://построчный ввод матрицы;
					ar.setarray(n);
					break;
				case 3://построчный вывод матрицы;
					ar.getarray(n);
					break;
				case 4:// установка значения элемента матрицы с индексами i, j;
					cout << "Введите номер строки" << endl;
					cin >> N;
					cout << "Введите номер столбца" << endl;
					cin >> M;
					ar.SetNum(N, M, n);
					break;
				case 5:// получение значения элемента матрицы с индексами i, j;
					cout << "Введите номер строки" << endl;
					cin >> N;
					cout << "Введите номер столбца" << endl;
					cin >> M;
					ar.GetNum(N, M, n);
					break;
				case 6:// сумма двух матриц
					for (int i = 0; i < k; i++)
						arrr[i] = ar[i] + arr[i];
					cout << "Полученная матрица:" << endl;
					arrr.getarray(n);
					break;
				case 7:// сравнение матриц
					for (int i = 0; i < k; i++)
					{
						if (ar[i] != arr[i])
						{
							f3 = false;
						}
					}
					if (f3 == true)
					{
						cout << "Матрица A равна матрице B" << endl;
					}
					else
					{
						cout << "Матрица A не равна матрице B" << endl;
					}
					break;
				case 8:// приравнять матрицу B к матрице A
					for (int i = 0; i < k; i++)
					{
						ar[i] = arr[i];
					}
					break;
				case 9:// возврат к работе с матрицей A
					f2 = true;
					cout << "Работаем с матрицей A";
					break;
				}
			}
			break;
		case 7:// приравнять матрицу A к матрице B
			for (int i = 0; i < k; i++)
			{
				arr[i] = ar[i];
			}
				break;
		case 8:// конец программы, запись матриц в файл и чтение матриц из текстового файла
			f1 = true;
			arrr.writing_to_a_file(fout, n);
			arr.writing_to_a_file(fout, n);
			ar.writing_to_a_file(fout, n);
			read(fout);
			cout << "Exit" << endl;
			break;
		}
	}
	return 0;
}
