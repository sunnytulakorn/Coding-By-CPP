#include <iostream>
#include <string>
#include "card.cpp"

using namespace std;

class CardList{

public:
	Card* head;
  int index;
  CardList(){
      head = NULL;
      index = 0;
  }

	void pop_back(){
    Card* Blast_c = head;
    Card* Delc;
    if(index > 1){
      for(int i = 1; i< index-1; i++){
        Blast_c = Blast_c -> next;
      }
      Delc = Blast_c -> next;
      Blast_c -> next =NULL;
      delete Delc;
      Delc = NULL;
      index--;
    }
    else{
      head = NULL;
      //index--;
    }

	}


    void insert_back(string newItem){
      Card* Fcard = new Card;
      Fcard -> name = newItem;
      Fcard -> next = NULL;
      if(index == 0){
        Fcard -> next = NULL;
        head = Fcard;
        index++;
      }
      else{
        Card* LastCard = head;
        for(int i =1; i<index ; i++){
          LastCard = LastCard -> next;
        }
        LastCard -> next = Fcard;
        index++;
      }
    }

    void shuffle(int pos){
      Card* LastCard = head;
      Card* position_c = head;
      Card* Rcard;
      if(0<pos && pos <= index-1){
        for(int i =1; i<index ; i++){
          LastCard = LastCard -> next;
        }
        LastCard -> next = head;
        for(int i = 1 ; i<pos; i++){
          position_c = position_c -> next;
        }
        Rcard = position_c -> next;
        head = Rcard;
        position_c -> next = NULL;  
        }
    }
    
    void printCardList(){
        /*
         DO NOT DELETE OR EDIT
         */
        cout << "[ ";
        Card* ptr = head;
        while(ptr!=NULL){
            cout << ptr->name << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }
};