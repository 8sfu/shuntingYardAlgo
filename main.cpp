#include <iostream>
#include <cstring>
#include "list.h"
#include "stack.h"

using namespace std;

bool cmp(char* input, const char* checkAgainst){ //simplify input to cstring comparison
  if(!strcasecmp(input,checkAgainst)){
    return true;
  }
  return false;
}

int main(){
  char* input = new char[10];
  Stack* list = new Stack();

  while(true){
    cout << "push peek pop print quit" << endl;
    cin.getline(input,10);
    if(cmp(input,"push")){
      list->push(new Node());
    }else if(cmp(input,"pop")){
      cout << "popped " << list->peek()->getValue();
      Node* garbageCanNode = list->pop();
    }else if(cmp(input,"peek")){
      cout << "peeked " << list->peek()->getValue();
    }else if(cmp(input,"print")){
      list->print();
    }else if(cmp(input,"quit")){
      return 0;
    }
    
  }

  delete[] input;
  delete[] list;
  return 0;
}
