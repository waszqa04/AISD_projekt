#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const int MAX_N = 100; 

int obliczDystans(const int dystanse[], int n, int start, int koniec, int calkowityDystans) {
    int dystansZgodny = 0;

    for (int i = start; i != koniec; i = (i + 1) % n) {
        dystansZgodny += dystanse[i];
    }

    int dystansPrzeciwny = calkowityDystans - dystansZgodny;

    return min(dystansZgodny, dystansPrzeciwny);
}

void znajdzNajdalszePary(const int dystanse[], int n, int najdalszePary[][2], int& liczbaPar) {
    int calkowityDystans = 0;
    for (int i = 0; i < n; i++) {
        calkowityDystans += dystanse[i];
    }

    int maksymalnyDystans = 0;
    liczbaPar = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dystans = obliczDystans(dystanse, n, i, j, calkowityDystans);

            if (dystans > maksymalnyDystans) {
                maksymalnyDystans = dystans;
                liczbaPar = 0;
                najdalszePary[liczbaPar][0] = i + 1; 
                najdalszePary[liczbaPar][1] = j + 1;
                liczbaPar++;
            } else if (dystans == maksymalnyDystans) {
                najdalszePary[liczbaPar][0] = i + 1;
                najdalszePary[liczbaPar][1] = j + 1;
                liczbaPar++;
            }
        }
    }
}

int main() {
    ifstream plikWejsciowy("wejscie.txt");
    ofstream plikWyjsciowy("wyniki.txt");

    if (!plikWejsciowy.is_open() || !plikWyjsciowy.is_open()) {
        cout << "Nie mozna otworzyc pliku!" << endl;
        return 1;
    }
    else{
    	cout<<"Wyniki zosta³y zapisane do pliku!"<<endl;
	}

	//Przypadki testowe
	//[1 2 3 4 3]
	//[2 3 5 7 11]
	//[1 1 1 1 1 1]
	//[10 20 30 40]
	//[1 2 5 3 8 6]

    int liczbaTestow;
    plikWejsciowy >> liczbaTestow;

    for (int numerTestu = 0; numerTestu < liczbaTestow; numerTestu++) {
        int n;
        plikWejsciowy >> n;

        int dystanse[MAX_N];
        for (int i = 0; i < n; i++) {
            plikWejsciowy >> dystanse[i];
        }

        int najdalszePary[100][2];
        int liczbaPar;
        znajdzNajdalszePary(dystanse, n, najdalszePary, liczbaPar);

        plikWyjsciowy << "Przypadek testowy: " << numerTestu + 1 << ":\n";
        plikWyjsciowy << "Dystanse: [";
        for (int i = 0; i < n; i++) {
            plikWyjsciowy << dystanse[i] << (i < n - 1 ? ", " : "");
        }
        plikWyjsciowy << "]\n";

        plikWyjsciowy << "Najdalsze pary: [";
        for (int i = 0; i < liczbaPar; i++) {
            plikWyjsciowy << "[" << najdalszePary[i][0] << ", " << najdalszePary[i][1] << "]";
            if (i < liczbaPar - 1) plikWyjsciowy << ", ";
        }
        plikWyjsciowy << "]\n";
        plikWyjsciowy << "-----------------------------\n";
    }

    plikWejsciowy.close();
    plikWyjsciowy.close();

    return 0;
}

