#include<bits/stdc++.h>
#include<fstream>

using namespace std;

void inmang(int a[], int n, ofstream &fout){
    for(int i = 0; i < n; i++){
        fout << a[i] << " ";
    }
    fout << endl;
}

void InsertionSort(int a[], int n, ofstream &fout){
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i -1;

        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j + 1] = key;

        fout << "Sap xep lan " << i << ": ";
        inmang(a,n,fout); 
    }
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output5.txt");


    int a[1000];
    int n;

    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> a[i];
    }

    fout << "Mang Ban Dau: ";
    inmang(a,n,fout);

    InsertionSort(a,n,fout);

    fout << "Mang Da Sap Xep: ";
    inmang(a,n,fout);

    return 0;
}