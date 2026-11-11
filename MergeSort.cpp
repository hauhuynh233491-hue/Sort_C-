#include<bits/stdc++.h>
#include<fstream>

using namespace std;

void inmang(int a[],int  n, ofstream &fout){
    for(int i = 0; i < n; i++){
        fout << a[i] << " ";
    }
    fout << endl;
}

void tron(int a[], int temp[], int left, int mid, int right, int n, ofstream &fout){
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right){
        if(a[i] < a[j]){
            temp[k] = a[i];
            i++;
        }
        else{
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while(i <= mid){
        temp[k] = a[i];
        k++;
        i++; 
    }

    while( j <= right){
        temp[k] = a[j];
        k++;
        j++;
    }
    for(int i = left; i <= right; i++){
        a[i] = temp[i];
    }

    inmang(a,n,fout);
}

void mergesort(int a[], int temp[], int left, int right, int n, ofstream &fout){
    if(left < right){
        int mid = left + (right - left)/2;
        mergesort(a, temp, left, mid, n, fout);
        
        mergesort(a, temp, mid + 1, right, n, fout);
        
        tron(a, temp, left, mid, right, n, fout);
    }
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output4.txt");

    int n;
    int a[1000];
    int temp[1000];

    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> a[i];
    }

    fout << "Mang Ban Dau: ";
    inmang(a,n,fout);

    mergesort(a, temp, 0, n -1, n, fout );

    fout << "Mang Da Sap Xep: ";
    inmang(a,n,fout);

    fin.close();
    fout.close();
    return 0;
}