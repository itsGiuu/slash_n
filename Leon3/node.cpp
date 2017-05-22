// C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
#include "node.h"  
  
using namespace std;

// A utility function to create a new BST node

Node::Node(){
	nodeLeft = nodeRight = NULL;	
}

Node::Node(unsigned long matricula_aux, string nome_aux, float cMobile_aux, float cCard_aux){
	matricula = matricula_aux;
	nome = nome_aux;
	creditsMobile = cMobile_aux;
	creditsCard = cCard_aux;
	nodeLeft = nodeRight = NULL;
}

bool Node::ehFolha(unsigned long matricula_aux){
	bool aux = false;

	if (nodeLeft == NULL && nodeRight == NULL) aux = true;

	return aux;
}

void Node::nodeNew(unsigned long matricula_aux, string nome_aux, float cMobile_aux, float cCard_aux){
	matricula = matricula_aux;
	nome = nome_aux;
	creditsMobile = cMobile_aux;
	creditsCard = cCard_aux;
	nodeLeft = nodeRight = NULL;
}

unsigned long Node::getMatricula(){
	return matricula;
}

List::List(unsigned long matricula_aux, string nome_aux){
	root = new Node(matricula_aux, nome_aux, 0.0, 0.0);
}

void List::auxInserir(Node* temporary, unsigned long matricula_aux, string nome_aux){

	Node* temporary2;

	if (temporary == NULL)
	{
		temporary = new Node(matricula_aux, nome_aux, 0.0, 0.0);
		cout << "cadastro: " << temporary->getMatricula() << endl;
		delete temporary;
		
	}else{
		temporary2 = temporary;
	    
	    if (matricula_aux < temporary->getMatricula())
	    {
	    	temporary = temporary->nodeLeft;
	        auxInserir(temporary, matricula_aux, nome_aux);
	        temporary2->nodeLeft = temporary;
	    }
	    else if (matricula_aux > temporary->getMatricula())
	    {
	    	temporary = temporary->nodeRight;
	        auxInserir(temporary, matricula_aux, nome_aux);   
	        temporary2->nodeRight = temporary;
	    }
	    cout << temporary2->getMatricula() << temporary2->nodeLeft << endl;
	}
}

void List::listAll(Node *temporary){
	if (temporary != NULL)
    {
    	cout << temporary->getMatricula() << endl;
        listAll(temporary->nodeLeft);
        listAll(temporary->nodeRight);
    }
}