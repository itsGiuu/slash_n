#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

class Node
{
private:
	unsigned long matricula;
	string nome;
	float creditsMobile;
	float creditsCard;

public:
	Node *nodeLeft, *nodeRight;
	
	Node();
	Node(unsigned long matricula_aux, string nome_aux, float cMobile_aux, float cCard_aux);
	unsigned long getMatricula();
	bool ehFolha(unsigned long matricula_aux);
	void nodeNew(unsigned long matricula_aux, string nome_aux, float cMobile_aux, float cCard_aux);
};

class List
{
public:
	Node* root;
	List(unsigned long matricula_aux, string nome_aux);
	void auxInserir(unsigned long matricula_aux, string nome_aux);
	void auxInserir(Node* temporary, unsigned long matricula_aux, string nome_aux);
	void listAll(Node* temporary);
/*	void auxApaga(Node*);
	void auxRemoverNodo(Node *&, unsigned long);
	Node* auxProcurar(Node *&, unsigned long);
	void auxListAll(Node *&, unsigned long);
	void inserirNodo(string, unsigned long, int, string);
	*/
};