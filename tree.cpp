#include <iostream>
#include "queue.h"
#include "tree.h"

using namespace std;

Tree::Tree(Queue* postfix){
  root = new Stack();
  Node* addNode;
  Node* leftChild;
  Node* rightChild;
  while(postfix->isNotEmpty()){
    addNode = postfix->dequeue();
    //cout << "dequeued " << addNode->getValue() << " from postfix" << endl;
    // cout << "err1" << endl;
    if(addNode->isOperator()){
      //cout << "err2" << endl;
      rightChild = root->pop();
      //cout << "right child of " << addNode->getValue() << " is " << rightChild->getValue() << endl;
      leftChild = root->pop();
      //cout << "left child of " << addNode->getValue() << " is " << leftChild->getValue() << endl;
      addNode->setLeft(leftChild);
      addNode->setRight(rightChild);
    }
    root->push(addNode);
    //cout << "pushed " << root->peek()->getValue() << " to root" << endl;
  }
}

void Tree::printPrefix(){
  root->peek()->printPrefix();
}

void Tree::printInfix(){
  root->peek()->printInfix();
}

void Tree::printPostfix(){
  root->peek()->printPostfix();
}
