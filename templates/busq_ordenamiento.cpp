#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int partition (vector <int> &v, const int &left, const int &right){
	int mid = left + (right - left) / 2;
	int pivot = v[mid];
	
	std::swap(v[mid],v[left]);
	int i = left +1;
	int j = right;
	
	while(i <= j){
		while(i <= j && v[i] <= pivot){
			i++;
		}
	
		while(i <= j && v[j] > pivot){
			j--;
		}
	
		if(i < j){
			std::swap(v[i],v[j]);
		}
	
	}
	std::swap(v[i-1],v[left]);
	return i-1;
}

void quicksort(vector <int> & v, const int& left, const int& right){
	
	if (left >= right)	return;
	
	int part = partition(v, left, right);
	
	quicksort(v, left, part - 1);
	quicksort(v, part + 1, right);
}

int binary_search(vector <int> &v, int low, int high, int key)
{
	if(low<=high)
	{
		int mid = low + (high - low) / 2;
		
		if (v[mid] == key)	return mid;
		
		if (v[mid] > key)	return binary_search(v,low, mid-1, key);
						    return binary_search(v, mid+1, high, key);
	}
	
    return -1;
}
