#include <iostream>
#include <algorithm>

using namespace std;

int obliczOdleglosc(const int odleglosci[], int n, int start, int koniec, int calkowitaOdleglosc) {
    int odlegloscZgodnieZRuchem = 0;

    for (int i = start; i != koniec; i = (i + 1) % n) {
        odlegloscZgodnieZRuchem += odleglosci[i];
    }

    int odlegloscPrzeciwnieDoRuchu = calkowitaOdleglosc - odlegloscZgodnieZRuchem;

    return min(odlegloscZgodnieZRuchem, odlegloscPrzeciwnieDoRuchu);
}

void znajdzNajdalszePary(const int odleglosci[], int n, int najdalszePary[][2], int& liczbaPar){
	
	
	
	
}


int main()
{


return 0;
}

