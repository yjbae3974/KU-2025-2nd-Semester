
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct NODE{
	//todo: define struct NODE
    char* name; //문자열이므로 포인터로 생성
	struct NODE* parent; //부모 노드
	struct NODE* child; //자식 노드
	struct NODE* prev;
	struct NODE* next;



    }NODE;




//MakeNode: make a new node
NODE* MakeNode(char* name){
	//todo	
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->name = (char*)malloc(strlen(name) + 1);
	strcpy(new_node->name, name);

	//처음엔 누구도 못가리키므로, 포인터 초기화
	new_node->parent = NULL;
	new_node->child = NULL;
	new_node->prev = NULL;
	new_node->next = NULL;

	return new_node;
	}


// Insert node (parent-child): append a child node to parent node
void InsertChild(NODE* parent_node, NODE* this_node){
	//todo
	this_node->parent = parent_node;

	if(parent_node->child == NULL){ //자식이 없으면
		parent_node->child = this_node;
	}
	else{
		NODE* temp = parent_node->child; //자식노드 첫번째 노드
		while(temp->next != NULL){ //계속 뒤로 이동하여 마지막 노드 찾기
			temp = temp->next;
		}
		temp->next = this_node;
		this_node->prev = temp; //현재 노드 이전을 기존의 마지막 노드로 설정
	}
}


// Insert node (prev-next): append a next node to prev node 
void InsertSibling(NODE* prev_node, NODE* this_node){
	//todo
	this_node->parent = prev_node->parent;

	this_node->prev = prev_node;
	prev_node->next = this_node;

	}


//Tree walk algorithm
void WalkTree(NODE* node){ //DFS로, 재귀적으로 구현
	//todo
	if(node == NULL){
		return;
	}
	printf("%s\n", node->name);
	WalkTree(node->child);
	WalkTree(node->next);

	}

	int main() {
		NODE* A = MakeNode("A");
		NODE* B = MakeNode("B");
		NODE* C = MakeNode("C");
		NODE* D = MakeNode("D");
		NODE* E = MakeNode("E");
		NODE* F = MakeNode("F");
		NODE* G = MakeNode("G");
		NODE* H = MakeNode("H");
		NODE* I = MakeNode("I");
		NODE* J = MakeNode("J");
		
		InsertChild(A, B);
		InsertChild(B, C);
		InsertSibling(B, E);
		InsertSibling(E, I);
		InsertSibling(C, D);
		InsertChild(E, F); 
		InsertSibling(F, G);
		InsertSibling(G, H);
		
		printf("Tree traversal:\n");
		WalkTree(A);
		
		return 0;
	}