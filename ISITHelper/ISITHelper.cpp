#include <iostream>
#include <string>
#include <iomanip>  
#include <sstream>
#include <cmath>
#include <fstream>

using namespace std;

double ToDouble(string str) {
	double res;
	bool flag = false;
	int k = 0;
	int trns = 0;
	//cout << str.length() << endl;
	for (int i = 0; i < str.length(); i++) {
		char zet = str[i];
		if (zet == ',') {
			flag = true;
		}
		//cout << "im in";
		if (zet != ',' && zet != '\n') {
			trns = trns * 10 + (zet - 48);
			if (flag == true) {
				k++;
			}
			//cout << trns << endl;
		}
	}
	res = trns;
	for (int i = 0; i < k; i++) {
		res /= 10;
	}
	return res;
}

int main() // преобразователь для перегона в вольфрам
{
	string mass[6][6];
	double arr[6][6];
    fstream fll;
	string str1, str2, str3;
	fll.open("D:\\Prakhuys.txt", ios::in);
	if (!fll.is_open()) {
		fstream fll("D:\\Prakhuys.txt", ios::in);
	}
	int n1, n2;
	cout << "number of i\n";
	cin >> n1;
	cout << "number of j\n";
	cin >> n2;
	int i = 0;
	int j = 0;
	while (!fll.eof()) {
		getline(fll, mass[i][j], '	');
		
		j++;
		if (j == n2) {
			//cout << mass[i][j] << endl;
			i++;
			j = 0;
		}
	}
	cout << i << " " << j << endl;

	for (i = 0; i < n1; i++) {
		for (j = 0; j < n2; j++) {
			arr[i][j] = ToDouble(mass[i][j]);
		}
	}

	for (i = 0; i < n1; i++) {
		for (j = 0; j < n2; j++) {
			cout << mass[i][j] << ' ';
		}
		//cout << endl;
	}

	cout << endl;
	fll.close();
	fll.open("D:\\Prakhuys.txt", ios::app);

	cout << '{';
	fll << '{';
	for (i = 0; i < n1; i++) {
		cout << '{';
		fll << '{';
		for (j = 0; j < n2; j++) {
			cout << arr[i][j];
			fll << fixed << setprecision(3) << arr[i][j];
			if (j < n2 - 1) {
				cout << ',';
				fll << ',';
			}
		}
		cout << '}';
		fll << '}';
		if (i < n1 - 1) {
			cout << ',';
			fll << ',';
		}
	}
	cout << '}';
	fll << '}';
	cout << endl;
	fll.close();

    system("pause");
}
