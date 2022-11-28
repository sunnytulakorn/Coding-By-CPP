#include <iostream>
#include "term.cpp"
using namespace std;
class Polynomial{
public:
    Poly_node* head;
    int index;
    Polynomial(){
        head = NULL;
        index = 0;
    }
    void addTerm(int coef, int exponent){
        Poly_node* NewTerm;
        NewTerm = new Poly_node;
        NewTerm -> coef = coef;
        NewTerm -> exponent = exponent;
        if(index == 0){
            head = NewTerm;
            NewTerm -> next = NULL;
            index++;
        }
        else if(head -> exponent < NewTerm -> exponent){
            NewTerm -> next = head;
            head = NewTerm;
        }
        else{
          Poly_node* CheckEx = head;
          while(true){
            if(CheckEx -> next == NULL){
              break;
            }
            else if(CheckEx -> next -> exponent < NewTerm -> exponent){
              break;
            }
            else if(CheckEx -> exponent == NewTerm -> exponent){
              break;
            }           
            CheckEx = CheckEx -> next;           
          }
          if(CheckEx -> exponent == NewTerm -> exponent){
            CheckEx -> coef += NewTerm -> coef;
          }
          else{
            NewTerm -> next = CheckEx -> next;
            CheckEx -> next = NewTerm;
          }
        }
    }
    void printPolynomial(){
        cout<<"[ ";
        Poly_node* ptr = head;
        while(ptr!=NULL){
            if(ptr->coef==0){

            }else{
                cout<< ptr->coef<<"X^{"<<ptr->exponent<<"} ";
            }
            ptr = ptr->next;
        }
        cout<<"]\n";
    }
    void plus(Polynomial f2){
        Poly_node* Itemf1 = head;
        Poly_node* Itemf2 = f2.head;
        Poly_node* nextIt2;

        while (true){
            if(Itemf1 -> exponent > Itemf2 -> exponent){
              if(Itemf1 -> next == NULL){
                    Itemf1 -> next = Itemf2;
                    break;
                }    
                if(Itemf1 -> next -> exponent < Itemf2 -> exponent){
                    nextIt2 = Itemf2 -> next;
                    Itemf2 -> next = Itemf1 -> next;
                    Itemf1 -> next = Itemf2;
                    Itemf1 = Itemf2;
                    Itemf2 = nextIt2;
                    if(Itemf2 == NULL){
                        break;
                    }
                }
                else{
                    Itemf1 = Itemf1 -> next;
                } 
            }
            else if(Itemf1 -> exponent == Itemf2 -> exponent){
                Itemf1 -> coef += Itemf2 -> coef;
                Itemf2 = Itemf2 -> next;
                if(Itemf2 == NULL){
                    break;
                }
                if(Itemf1 -> next == NULL){
                  Itemf1 -> next = Itemf2;
                  break;
                }
            }
            else if(Itemf1 -> exponent < Itemf2 -> exponent){
                nextIt2 = Itemf2 -> next;
                Itemf2 -> next = Itemf1;
                head = Itemf2;
                Itemf1 = Itemf2;
                Itemf2 = nextIt2;
            }
        }
    }
    void minus(Polynomial f2){
      Poly_node* Itemf1 = head;
        Poly_node* Itemf2 = f2.head;
        Poly_node* nextIt2;

        while (true){
            if(Itemf1 -> exponent > Itemf2 -> exponent){
              if(Itemf1 -> next == NULL){
                    Itemf1 -> next = Itemf2;
                    break;
                }    
                if(Itemf1 -> next -> exponent < Itemf2 -> exponent){
                    nextIt2 = Itemf2 -> next;
                    Itemf2 -> coef *= -1; 
                    Itemf2 -> next = Itemf1 -> next;
                    Itemf1 -> next = Itemf2;
                    Itemf1 = Itemf2;
                    Itemf2 = nextIt2;
                    if(Itemf2 == NULL){
                        break;
                    }
                }
                else{
                  Itemf1 = Itemf1 -> next;
                } 
            }
            else if(Itemf1 -> exponent == Itemf2 -> exponent){          
                Itemf1 -> coef -= Itemf2 -> coef;
                Itemf2 = Itemf2 -> next;
                if(Itemf2 == NULL){
                    break;
                }
                if(Itemf1 -> next == NULL){
                  Itemf1 -> next = Itemf2;
                  break;
                }
            }
            else if(Itemf1 -> exponent < Itemf2 -> exponent){
                nextIt2 = Itemf2 -> next;
                Itemf2 -> coef *= -1; 
                Itemf2 -> next = Itemf1;
                head = Itemf2;
                Itemf1 = Itemf2;
                Itemf2 = nextIt2;
            }
        }
    }
};