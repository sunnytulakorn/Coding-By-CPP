class CharStack {

public:
  int indexItem;
  char List[50];
  
  CharStack() { // constructor
    indexItem = 0;
  }

  void push(char new_item) {
    indexItem++;
    List[indexItem] = new_item;
  }

  char pop() {
    indexItem--;
    return(List[indexItem]);   
  }

  char top() {
    return(List[indexItem]);
  }

  bool isEmpty() {
    if(indexItem == 0){
      return(true);
    }else{
      return(false);
    }
  }
};