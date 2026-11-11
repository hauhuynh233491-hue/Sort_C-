#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void inmang(int a[], int n, ofstream &fout){
    for(int i = 0; i < n; i++){
        fout << a[i] << " ";
    }
    fout << endl;
}

void selectionsort(int a[], int n, ofstream &fout){
    for(int i = 0; i < n - 1; i++){
        int min = i;

        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        swap(a[i] , a[min]);

        fout << "Sap Xep Luot " << i + 1 << ": ";
        inmang(a,n,fout);
    }
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output3.txt");

    int a[1000];
    int n;
    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> a[i];
    }

    fout << "Mang Ban Dau: ";
    inmang(a,n,fout);

    selectionsort(a,n,fout);

    fout << "Mang Da Sap Xep: ";
    inmang(a,n,fout);

    fin.close();
    fout.close();

    return 0;
}