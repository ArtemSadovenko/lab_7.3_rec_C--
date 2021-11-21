#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void create(int** a, int col, int row, int l, int h, int i, int j);
void print(int** a, int row, int col, int i, int j);
int count(int** a, int row, int col, int i, int j, int u);
void num(int** a, int row, int col, int i, int j, int& j_max, int a_same, int max, int mp);

void main() {
	srand((unsigned)time(NULL));

	int k;
	int n;

	cout << "row = "; cin >> k;
	cout << "col = "; cin >> n;

	int l = 0;
	int h = 2;

	int max = 0;
	int q;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	create(a, n, k, l, h, 0, 0);

	print(a, k, n, 0, 0);

	q = count(a, k, n, 0, 0, 0);
	cout << "num = " << q << endl;

	num(a, k, n, 0, 0, max, a[0][0] +1, 0, 0);
	cout << "j_max = " << max + 1 << endl;


}

void create(int** a, int col, int row, int l, int h, int i, int j) {
	a[i][j] = l + rand() % (h - l + 1);
	if (j < col - 1) {
		create(a, col, row, l, h, i, j + 1);
	}
	else if (i < row - 1) {
		create(a, col, row, l, h, i + 1, 0);
	}
	else {
		cout << endl;
	}
}

void print(int** a, int row, int col, int i, int j) {

	if (j == 0) {
		cout << "|";
	}

	cout << setw(4) << a[i][j] << " ";

	if (j == col - 1) {
		cout << "|\n";
	}

	if (j < col - 1) {
		print(a, row, col, i, j + 1);
	}
	else if (i < row - 1) {
		print(a, row, col, i+1, 0);
	}
	else {
		cout << endl;
	}
}

int count(int** a, int col, int row, int i, int j, int u) {
	if (a[i][j] == 0 && j < row - 1 && i < col - 1) {
		return count(a, col, row, i, row, u + 1);
	}
	else if (a[i][j] != 0 && j < row - 1) {
		return count(a, col, row, i , j+1, u);
	}
	else if (i < col - 1) {
		return count(a, col, row, i+1, 0, u);
	}
	else
		return u+1;
	
}

void num(int** a, int row, int col, int i, int j, int& j_max, int a_same, int max, int mp) {	
	if (a[i][j] == a_same) {
		mp += 1;

		if (mp > max) {
			max = mp;
			j_max = j;
		}
	}
	else {
		a_same = a[i][j];
		mp = 0;
	}

	if (i < row - 1) {
		num(a, row, col, i + 1, j, j_max, a_same, max, mp);
	}
	else if (j < col - 1) {
		num(a, row, col, 0, j + 1, j_max, a[0][j + 1] + 1, max, 0);
	}
}