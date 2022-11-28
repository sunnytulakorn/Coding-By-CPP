#include <iostream>
using namespace std;
class Ranking{
private:
    int data[1000];
    int size;
public:
    Ranking(int n){
      size = n;
    }
    void inputData(){
        for(int i=0;i<size;i++){
            cin>>data[i];
        }
    }
    int binarySearch(int key){
        int low = 0;
        int high = size - 1;
        int mid = (low + high)/2;
        for(int i = low;i<=high;i++){
            if(key == data[mid]){
                return mid + 1;
            }
            else if(key < data[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            mid = (low + high)/2;
        }
        return NULL;
    }
    void merge(int left, int mid, int right){
        int i = 0, last_elem, number, positions;
        last_elem = mid - 1;
        positions = left;
        number = right - left + 1;
        int temp[number];
        while (left <= last_elem && mid <= right) {
            if (data[left] < data[mid]){
                temp[i] = data[mid];
                i++;
                mid++;
            }
            else{
              temp[i++] = data[left++];            
            }
        }
        while (left <= last_elem){
            temp[i++] = data[left++];
        }

        while (mid <= right)
        {
            temp[i++] = data[mid++];
        }
        for(int i = number-1; i >= 0; i--){
			    data[right] = temp[i];
			    right--;
        }
    }
    void mergeSort(int left, int right){
        int mid ;
        if (left < right)
        {
            mid = (left + right) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid + 1, right);
        }
	}
    int show(int index){
        return data[index-1];
    }
};