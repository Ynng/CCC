#include <iostream>
#include <iomanip> 
using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1])swap(&a[j], &a[j + 1]);
		}
	}
}

int main() {
	int villageN, *villages;
	double neighbourhood, least;
	//Input Gathering
	cin >> villageN;
	villages = new int[villageN];
	for (int i = 0; i < villageN; i++) {
		cin >> *(villages + i);
	}
	//cout << villages[0] << "  " << villages[1] << "  " << villages[2] << "  " << villages[3] << "  " << villages[4];
	sort(villages, villageN);
	//cout << villages[0] <<"  " << villages[1] << "  " << villages[2] << "  " << villages[3] << "  " << villages[4];
	least = neighbourhood = ((double)(villages[2] - villages[0])) /2;
	for (int i = 2; i < villageN-1; i++) {
		neighbourhood = ((double)(villages[i+1] - villages[i-1])) /2;
		if (neighbourhood < least)least = neighbourhood;
	}
	cout << fixed << setprecision(1) << least;
	delete villages;
	return 0;
}
