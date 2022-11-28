#include<iostream>
using namespace std;
class Router
{

	int capacity; 
	int heap_size; 
public:
    int *data; 
	Router(int cap){
        heap_size = 0;
        capacity=cap;
        data = new int[cap];
    }

	int parent(int i) { return (i-1)/2; }
	int left(int i) { return (2*i + 1); }
	int right(int i) { return (2*i + 2); }

	int removeMin(){

    if (heap_size == 1)
    {
        heap_size--;
        return data[0];
    }
    int root = data[0];
    data[0] = data[heap_size-1];
    heap_size--;
    downHeap(0);
    return root;
    }

	int min() {
        heap_size--;
        return data[0];
	}

	void insert(int k){
      if(heap_size != capacity){
        heap_size = heap_size + 1;
        int i = heap_size - 1;
        data[i] = k;
        while (i != 0 && data[parent(i)] > data[i]) {
        swap(data[i], data[parent(i)]);
        i = parent(i);
        }
      }
      else{
          return;
      }
  }

	void downHeap(int i){
    int left_heap = left(i);
    int right_heap = right(i);
    int smallest = i;

    if (left_heap < heap_size && data[left_heap] < data[i])
        smallest = left_heap;

    if (right_heap < heap_size && data[right_heap] < data[smallest])
        smallest = right_heap;

    if (smallest != i)
    {
        swap(data[i], data[smallest]);
        downHeap(smallest);
    }

    }

	void reset(int k){
        data[0] = k;
        downHeap(0);
    }
};