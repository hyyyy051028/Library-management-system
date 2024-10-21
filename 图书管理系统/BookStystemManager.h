#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>




typedef struct _Book {
	int number;
	char name[20];
	int times;
}Book;
typedef struct _Node {
	Book book;
	struct _Node* next;
}Node;
typedef struct user {
	char name[20];
	char log[11];
}user;
 


void welcome1(Node* head);
void welcome2(Node* head);
void inputbook(Node* head);
void printfbook(Node* head);
void coutbook(Node* head);
void find(Node* head);
void  savebook(Node* head);
void loadbook(Node* head);
void changebook(Node* head);
void numdel(Node* head);
void sort(Node* head);
void logadmian(Node* head);
void come();
void logname();
int  finduser();
void color(int c);
void input();
int income(Node* head);
void show();
void show2(Node* head);
void namefind(Node* head);
void numfind(Node* head);
void namedel(Node* head);
void delshow(Node* head);
void shaixuan(Node* head);
void fanwei(Node* head);
int judge(char a);
void zongying(Node* head);
int fanwei(int a, int b, int c);
void adminpeo();
void printadmin();
void deladmin();
void sort2(Node* head);
void sort3(Node* head);
void zuhe(Node* head);