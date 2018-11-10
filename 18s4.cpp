#include "pch.h"
#include <stdio.h>
#include <math.h>  
#include <map>
using namespace std;
int n = 0;
std::map<int, double> theMap;
double node(int weight) {
	int nodeWeight;
	double d = 0, temp = 0;
	for (int i = 2; i <= weight; i++) {
		//nodeWeight = (weight - (weight%i)) / i;
		nodeWeight = floor(weight / i);
		if (theMap.count(nodeWeight)) {
			d += theMap[nodeWeight];
		}
		else {
			temp = node(nodeWeight);
			theMap[nodeWeight]=temp;
			d += temp;
		}
	}
	return d;
}

int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("%d", 1);
		return 0;
	}
	printf("%d", node(n));
	return 0;
}
