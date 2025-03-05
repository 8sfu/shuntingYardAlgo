#include <iostream>
#include <cstring>
#include "list.h"

#include "stack.h"
#include "queue.h"

using namespace std;

bool cmp(char* input, const char* checkAgainst){ //simplify input to cstring comparison
  if(!strcasecmp(input,checkAgainst)){
    return true;
  }
  return false;
}

int main(){
  char* input = new char[40];
  
  /*
  Stack* stack = new Stack();
    
  while(true){
    cout << "push peek pop print quit" << endl;
    cin.getline(input,10);
    if(cmp(input,"push")){
      stack->push(new Node());
    }else if(cmp(input,"pop")){
      if(stack->isNotEmpty()){
	cout << "popped " << stack->pop()->getValue() << endl;
      }
    }else if(cmp(input,"peek")){
      if(stack->isNotEmpty()){
	cout << "peeked " << stack->peek()->getValue() << endl;
      }
    }else if(cmp(input,"print")){
      stack->print();
    }else if(cmp(input,"quit")){
      //CLEAR MEMORY
      return 0;
    }
  }
  delete[] stack;
  
  */

  /*
  Queue* queue = new Queue();
    
  while(true){
    cout << "enqueue dequeue print quit" << endl;
    cin.getline(input,10);
    if(cmp(input,"enqueue")){
      queue->enqueue(new Node());
    }else if(cmp(input,"dequeue")){
      if(queue->isNotEmpty()){
	cout << "dequeued " << queue->dequeue()->getValue() << endl;
      }
    }else if(cmp(input,"print")){
      queue->print();
    }else if(cmp(input,"quit")){
      //CLEAR MEMORY
      return 0;
    }
  }
  delete[] queue;
  
  */

  while(true){
    cout << "enter [an equation in infix] or quit" << endl;
    cin.getline(input,40);

    if(cmp(input,"quit")){
      return 0;
    }
    
    for(int i = 0; i < strlen(input); i+= 2){
      cout << input[i] << endl;
    }
    
  }

  

  delete[] input;
  return 0;
}
