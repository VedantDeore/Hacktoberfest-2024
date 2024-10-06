#include<iostream>
using namespace std;

int partition(int A[20], int low, int high) {
    int pivot = A[low];
    int i = low, j = high + 1;
    do {
        do {
            i++;
        } while (A[i] < pivot && i <= high);
        do {
            j--;
        } while (pivot < A[j]);
        if (i < j)
            swap(A[i], A[j]);
    } while (i < j);
    swap(A[low], A[j]);
    for(int i=low; i<=high  ; i++){
	cout<<A[i]<<" ";
	}
	cout<<endl;
    return j;
}

void qsort(int A[20], int low, int high) {
    if (low < high) {
        int k = partition(A, low, high);
        qsort(A, low, k - 1);
        qsort(A, k + 1, high);
    }
}

int main(){
	int n;
	int A[20];
	cout<<"Enter the no. of elements:";
	cin>>n;
	cout<<"Enter the elements:";
	for(int i=0; i<n; i++){
	cin>>A[i];
	}
	qsort(A, 0, n-1);
	cout<<endl<<"Sorted Elements are:";
	for(int i=0; i<n; i++){
	cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}
