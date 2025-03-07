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

char* shuntingYard(char infix[40][40],int len){
  for(int i = 0; i < len; i++){
    cout << i << ": " << infix[i] << endl;
  }

  
  
  char* postfix = infix[0];
  return postfix;
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
    char* token;
    int i = 0;
    char tokenArr[40][40]{};
    
        
    token = strtok(input," ");
    while(token != NULL){
      strcpy(tokenArr[i],token);
      i++;
      token = strtok(NULL," ");
    }
    
    for(int j = 0; j < i; j++){
      //cout << j+1 << ": " << tokenArr[j] << endl;
    }

    char* postfix = shuntingYard(tokenArr,i);
    cout << postfix << endl;
    return 0;
    
  }



  

  delete[] input;
  return 0;
}
