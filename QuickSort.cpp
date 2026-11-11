#include<bits/stdc++.h>
#include<fstream>

using namespace std;

void inmang(int a[], int n, ofstream &fout){
    for(int i = 0; i < n; i++){
        fout << a[i] << " " ;
    }
    fout << endl;
}

int phanchia(int a[], int low, int high){
    int pivot = a[high];

    int i = low - 1;
    for(int j = low; j < high;j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i + 1;
}

void quicksort(int a[], int low, int high, int n, ofstream &fout){
    if(low < high){
        int pi = phanchia(a,low,high);

        fout << "Pivot tai vi tri " << pi << ": ";
        inmang(a,n,fout);

        quicksort(a,low,pi - 1, n, fout);
        quicksort(a,pi + 1, high , n , fout);
    }
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output2.txt");

    int a[1000];
    int n;

    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> a[i];
    }
    
    fout<< "Mang Ban Dau: ";
    inmang(a,n, fout);

    quicksort(a, 0, n - 1, n, fout);

    fout << "Mang Da Sap Xep: ";
    inmang(a,n,fout);

    fin.close();
    fout.close();

    return 0;
}