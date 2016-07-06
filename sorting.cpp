#include <ctime>
#include <iostream>
using namespace std;
 
void read_array(int* p,int n){
	for (int i=0;i<n;i++)
		p[i]=rand()%100;
 
}
void print_array(int* p,int n){
	for (int i=0;i<n;i++)
		cout<<p[i]<<' ';
	cout<<endl;
}
void del_array(int* p,int n){
	if (p) delete[]p;
	p=NULL;
}
//сортировка пузырьком
void bubble_sort(int *a, int size){
	for(int i=0;i<size-1;i++)
		for (int k=i+1;k<size;k++)
			if (a[i]>a[k]){
				int p=a[i]; a[i]=a[k]; a[k]=p;
			}
}
//сортировка сравнением
void comparison_sort(int *a, int size){
	for(int i=1;i<size;i++)
	for (int k=0;k<size-i;k++)
		if (a[k]>a[k+1]){
			int p=a[k]; a[k]=a[k+1]; a[k+1]=p;
		}
}
//пирамидальная сортировка
void heapify(int* arr, int pos, int n){
	while(2*pos+1<n){
		int t=2*pos+1;
		if(2*pos+2<n && arr[2*pos+2]>=arr[2*pos+1]){
			t=2*pos+2;
		}
		if(arr[pos]<arr[t]){
			swap(arr[pos],arr[t]);
			pos=t;
		}
		else break;
	}
}
void heap_make(int* arr, int n){
	for(int i=n/2;i>=0;i--)
		heapify(arr,i,n);
}
void heap_sort(int* arr, int n){
	heap_make(arr,n);
	while(n>0){
		swap(arr[0],arr[n-1]);
		n--;
		heapify(arr,0,n);
	}
}
//быстрая сортировка
void quick_sort(int* a,int start,int end){
	int s,e,c,X;
	if(start>=end) return;
	s=start; e=end;
	X=a[(s+e)/2];
	while (s<=e){
		while(a[s]<X) s++;
		while(a[e]>X) e--;
		if(s<=e){
			swap(a[s],a[e]);
			s++;e--;
		}
	}
	quick_sort(a,start,e);
	quick_sort(a,s,end);
}
//сортировка вставками
void insertion_sort(int* a,int size){
	for (int i=1;i<size;i++)
		for(int j=i;j>0 && a[j]<a[j-1];j--)
			swap(a[j],a[j-1]);
}
int main() {
	clock_t t;
	cout.setf(ios::fixed);
	cout.precision(3);
	t = clock();
 
	int n; cin>>n;
	int *ptr=new int[n];
	read_array(ptr,n);
	//print_array(ptr,n);
	
	bubble_sort(ptr,n);
	//print_array(ptr,n);
		t = clock() - t;
	printf ("Bubble sort took me %d clicks (%f seconds).\n", t, ((float)t)/ CLOCKS_PER_SEC );
	
	comparison_sort(ptr,n);
	//print_array(ptr,n);
		t = clock() - t;
	printf ("Comparison sort took me %d clicks (%f seconds).\n", t, ((float)t)/ CLOCKS_PER_SEC );
	
	heap_sort(ptr,n);
	//print_array(ptr,n);
		t = clock() - t;
	printf ("Heap sort took me %d clicks (%f seconds).\n", t, ((float)t)/ CLOCKS_PER_SEC );
	
	quick_sort(ptr,0,n-1);
	//print_array(ptr,n);
		t = clock() - t;
	printf ("Quick sort took me %d clicks (%f seconds).\n", t, ((float)t)/ CLOCKS_PER_SEC );
	
	insertion_sort(ptr,n);
	//print_array(ptr,n);
		t = clock() - t;
	printf ("Insertion sort took me %d clicks (%f seconds).\n", t, ((float)t)/ CLOCKS_PER_SEC );
	del_array(ptr,n);
	return 0;
}
