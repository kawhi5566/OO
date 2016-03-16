#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 
using namespace std;

void quickSort(string name[100], int score[100],int left, int right) { //using quicksort on both array
	
	int i = left, j = right;
	int tmp;
	string tmp2;
	int pivot = score[(left + right) / 2];

	//partition
	while (i <= j) {                                         
		while (score[i] < pivot)
			i++;
		while (score[j] > pivot)
			j--;
		if (i <= j) {
			tmp = score[i];
			tmp2 = name[i];
			score[i] = score[j];
			name[i] = name[j];
			score[j] = tmp;
			name[j] = tmp2;
			i++;
			j--;
		}
	};
	
	//recursion
	if (left < j)
		quickSort(name, score,left, j);
	if (i < right)
		quickSort(name, score,i, right);
	
}

//input two array
void getHighScore() {	
	string name[100];
	string score[100];
	int score1[100] ;
	ifstream myfile("scores.txt");
	int a = 0;
	int b = 0;

	while (!myfile.eof())
	{
		getline(myfile, name[a], '\n');
		getline(myfile, score[b], '\n');

		a++; b++;
	}

	//tranform strint into array
	for (int c = 0; c < 100; c++) {
		score1[c] = atoi(score[c].c_str());		
	}

	//call quicksort func and output the top three
	quickSort(name, score1,0,99);
		for (int c = 99; c > 96; c--) {
			cout << name[c] << endl << score1[c] << endl;
		}
}

int main() {
	getHighScore();
}
