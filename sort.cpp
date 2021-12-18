#include<bits/stdc++.h>
using namespace std;
void printArray(int *a, int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}


/*Bubble Sort*/
void bubbleSort(int *a, int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]) swap(a[i],a[j]);
        }
    }
}
/************/


/*Insertion Sort*/
void insertionSort(int *a, int n){
    int index, value;
    for(int i=1; i<n; i++){
        index = i;
        value = a[i];
        while(index > 0 && a[index-1] > value){
            a[index] = a[index - 1];
            index--;
        }
        a[index] = value;
    }
}
/************/


/*Selection Sort*/
void selectionSort(int *a, int n){
    int index;
    for(int i=0; i<n; i++){
        index = i;
        for(int j=i+1; j<n; j++){
            if(a[index] > a[j]){
                index = j;
            }
        }
        if(i!=index){
            swap(a[i],a[index]);
        }
    }
}
/************/


/*Merge Sort*/
void merge(int *a, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1],R[n2];
    for(int i=0; i<n1; i++){
        L[i] = a[i+l];
    }
    for(int i=0; i<n2; i++){
        R[i] = a[i+m+1]; 
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k] = R[j];
        k++;
        j++;
    }
}
void mergeSort(int *a, int l, int r){
    if(l>=r) return;
    int m = (l+r)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    merge(a,l,m,r);
}
/************/


/*Shell Sort*/
void shellSort(int *a, int n){
    int i,j;
    for(int k = n/2; k > 0; k/=2){ // bước nhảy
        for(i=k; i<n; i++){
            int tmp = a[i];
            for(j=i; j>=k && tmp < a[j-k]; j-=k){
                a[j] = a[j-k];
            }
            a[j] = tmp;
        }
    }
}
/************/


/*Quick Sort*/
int partition(int *a, int l, int r, int indexPivot){
	int pivot = a[indexPivot];
	swap(a[indexPivot],a[r]);
	int storeIndex = l; // tìm vị trí mới cho pivot bằng cách tìm số phần tử bé thua pivot trong mảng
	for(int i=l; i<=r-1; i++){
		if(a[i] < pivot){
			swap(a[i],a[storeIndex]);
			storeIndex++;
		}
	}
	swap(a[storeIndex],a[r]);
	return storeIndex;
}
void quickSort(int *a, int l, int r){
	if(l>=r) return;
	int indexPivot = (l+r)/2;
	indexPivot = partition(a,l,r,indexPivot);
	if(indexPivot > l) quickSort(a,l,indexPivot-1);
	if(indexPivot < r) quickSort(a,indexPivot+1,r);
}
/************/


/*Heap Sort*/
void heapify(int *a, int i, int n){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int tmp = i;
    if(l<n && a[tmp] < a[l]){
        tmp = l;
    }
    if(r<n && a[tmp] < a[r]){
        tmp = r;
    }
    if(tmp != i){
        swap(a[i],a[tmp]);
        heapify(a,tmp,n);
    }
}
void buildheap(int *a, int n){
    for(int i = n/2-1; i >=0; i--){
        heapify(a,i,n);
    }
}
void heapSort(int *a, int n){
    buildheap(a,n);
    for(int i = n-1; i > 0; i--){
        swap(a[0],a[i]);
        heapify(a,0,i-1);
    }
}
/************/
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    quickSort(a,0,n-1);
    printArray(a,n);
}