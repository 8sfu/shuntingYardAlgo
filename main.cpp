#include <iostream>
#include <cstring>
#include <cmath>

#include "list.h"
#include "stack.h"
#include "queue.h"

using namespace std;

bool cmp(char* input, const char* checkAgainst){ //simplified comparison
  if(!strcasecmp(input,checkAgainst)){
    return true;
  }
  return false;
}

int charLength(char* check){
  int i = 0;
  while(check[i] != '\0'){
    i++;
  }
  return i;
}

int getPrecedence(char* token){
  char check = token[0];
  if(check == '+' || check == '-'){
    return 2;
  }else if(check == '*' || check == '/'){
    return 4;
  }else if(check == '^'){
    return 5;
  }else if(check == '('){
    return 6;
  }else if(check == ')'){
    return 7;
  }else{
    return 0;
  }
}

bool isNumber(Node* node){
  char* check = node->getValue();
  int i = 0;
  bool isNumber = true;
  while(check[i] != '\0'){
    if(!isdigit(check[i])){
      isNumber = false;
    }
    i++;
  }
  if(isNumber){
    cout << check << " is a number." << endl;
  }
  return isNumber;
}

bool isOperator(Node* node){
  char* check = node->getValue();
  if(charLength(check) == 1 && getPrecedence(check) < 6 && getPrecedence(check) > 0){
    //cout << check << " is an operator. (of precedence " << getPrecedence(check) << ") " << endl;
    return true;
  }
  return false;
}

bool isLeftParen(Node* node){
  char* check = node->getValue();
  if(charLength(check) == 1 && getPrecedence(check) == 6){
    //cout << check << " is a left parenthesis." << endl;
    return true;
  }
  return false;
}

bool isRightParen(Node* node){
  char* check = node->getValue();
  if(charLength(check) == 1 && getPrecedence(check) == 7){
    //cout << check << " is a right parenthesis." << endl;
    return true;
  }
  return false;
}

int charToInt(char* check){
  double value = 0.0;
  int i = 0;
  while(check[i] != '\0'){
    value += ((double)check[i]-48) * pow(10,0-i);
    i++;
  }
  return value * pow(10,i-1);
}

void shuntingYard(Queue* infix,int len){
  Stack* operatorStack = new Stack();
  Queue* output = new Queue();
  
  infix->print();
  
  while(infix->isNotEmpty()){
    //cout << "There are still tokens to be read." << endl;
    
    Node* check = infix->dequeue();
    //check->print();
    //cout << endl;

    if(isNumber(check)){
      //cout << check->getValue() << " was a number, enqueued." << endl;
      output->enqueue(check);
    }else if(isOperator(check)){
      while(operatorStack->isNotEmpty() && !isLeftParen(operatorStack->peek()) 
	    && getPrecedence(operatorStack->peek()->getValue()) >= getPrecedence(check->getValue())){
	//cout << operatorStack->peek()->getValue() << " was >= " << check->getValue() << " enqueued." << endl;
	output->enqueue(operatorStack->pop());
      }
      //cout << "enqueueing " << check->getValue() << endl;
      operatorStack->push(check);
    }else if(isLeftParen(check)){
      
      //cout << check->getValue() << " was a left parenthesis, pushed onto operator stack." << endl;
      operatorStack->push(check);
      
    }else if(isRightParen(check)){
      while(!isLeftParen(operatorStack->peek())){
	//cout << operatorStack->peek()->getValue() << ", top op is not a left parenthesis." << endl;
	if(operatorStack->isNotEmpty()){
	  //cout << "The operator stack is not empty." << endl;
	  //cout << "Popped " << operatorStack->peek()->getValue() << " and enqueued it to output." << endl;
	  output->enqueue(operatorStack->pop());
	}
      }
      if(isLeftParen(operatorStack->peek())){
	//cout << operatorStack->peek()->getValue() << ", top op is a left parenthesis." << endl;
	Node* discarded = operatorStack->pop();
      }
    }
    //cout << endl;
  }
  while(operatorStack->isNotEmpty()){
    //cout << "op stack still not empty, popped " << operatorStack->peek()->getValue() << " and enqueued it" << endl;
    output->enqueue(operatorStack->pop());
  }

  while(output->isNotEmpty()){
    cout << output->dequeue()->getValue();
  }
  
  return; //RETURN OUTPUT QUEUE WHEN DONE
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
  
  Queue* infix = new Queue();

  while(true){
    cout << "enter [an equation in infix] or quit" << endl;
    cin.getline(input,40);
    char* token;
    int i = 0;
    char tokenArr[40][40] = {"\0"};
    //for(int i = 0; i < 40; i++){
    //for(int j = 0; j < 40; j++){
    //tokenArr[i][j] = "\0";
    //}
    //}
    
    
    token = strtok(input," ");
    while(token != NULL){
      strcpy(tokenArr[i],token);
      i++;
      token = strtok(NULL," ");
    }
    
    for(int j = 0; j < i; j++){
      infix->enqueue(new Node(tokenArr[j]));
    }
    
    
    shuntingYard(infix,i);
    
    infix->print();
    
    cout << endl;
    return 0;
  }
  


  

  delete[] input;
  return 0;
}
