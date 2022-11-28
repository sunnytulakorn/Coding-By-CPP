#include <iostream>
#include <string>
#include "station.cpp"
using namespace std;

class Trip {

public:

    Station* header;
    Station* trailer;
    Trip()
    {
      header = new Station;
      trailer = new Station;
      header -> prev = NULL;
      header -> next = trailer;
      trailer -> prev = header;
      trailer -> next = NULL;
    }

    void printList()
    {
        cout << "[ ";
        Station* ptr = header->next;
        while (ptr != trailer) {
            cout << ptr->name << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }


    void insert_front(string newItem)
    {
      Station* newSta = new Station;
      newSta -> name = newItem;
      newSta -> prev = header;
      newSta -> next = header -> next;
      header -> next -> prev = newSta;
      header -> next = newSta;
    }
    void insert_back(string newItem)
    {
      Station* newSta = new Station;
      newSta -> name = newItem;
      newSta -> next = trailer;
      newSta -> prev = trailer -> prev;
      trailer -> prev -> next = newSta;
      trailer -> prev = newSta;
    }

    void remove_front()
    {
      Station* DelSta;
      DelSta = header -> next;
      header -> next = DelSta -> next;
      DelSta -> next -> prev = header;
      delete DelSta;
      DelSta = nullptr;
    }
    void remove_back()
    {
      Station* DelSta;
      DelSta = trailer -> prev;
      trailer -> prev = DelSta -> prev;
      DelSta -> prev -> next = trailer;
      delete DelSta;
      DelSta = nullptr;
    }

    Station* visit(int nStep, string stepText)
    {
      Station* nowSta;
      nowSta = header -> next;
      for(int i=0; i<nStep ; i++){
        if(stepText[i] == 'R'){
          nowSta = nowSta -> next;
          if(nowSta == trailer){
            nowSta = trailer -> prev;
          }
        }
        else{
          nowSta = nowSta -> prev;
          if(nowSta == header){
            nowSta = header -> next;
          }
        }
      }
      return nowSta;
    }
};