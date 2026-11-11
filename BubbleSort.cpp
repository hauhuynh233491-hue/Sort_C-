#include<bits/stdc++.h>
#include<fstream>

using namespace std;

void inmang(int a[], int n, ofstream &fout){
    for(int i = 0; i < n; i++){
        fout << a[i] << " ";
    }
    fout << endl;
}

void sapxep(int n, int a[], ofstream &fout){
    for(int i = 0; i < n-1 ; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                swap(a[j],a[j+1]);
            }
        }
        inmang(a, n,fout);
    }
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    int a[1000];

    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> a[i];
    }

    fout << "Mang Ban Dau: ";
    inmang(a, n , fout);

    sapxep(n, a, fout);

    fout << "Mang Da Sap Xep: ";
    inmang(a, n, fout);
    
    fin.close();
    fout.close();

    return 0;

}