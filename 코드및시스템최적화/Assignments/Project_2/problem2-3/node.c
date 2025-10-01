
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 1. node의 구조체 NODE를 선언(5점)
typedef struct NODE{
    char* name; //문자열이므로 포인터로 생성
	struct NODE* parent; //부모 노드
	struct NODE* child; //자식 노드
	struct NODE* prev;
	struct NODE* next;
    }NODE;




//2. char* name을 이름으로 하는 NODE를 생성하는 함수 MakeNode(char* name)을 작성(5점)
NODE* MakeNode(char* name){
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


// 3. Parse tree에서 parent node에 child node(this node)를 insert 하는 함수 InsertChild (NODE* parent_node, NODE* this_node)를 작성(10점)
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


// 4. Parse tree에서 같은 depth에 있는 sibling node(prev_node)에 새로운 node(this node)를 insert 하는 함수 InsertSibling(NODE* prev_node, NODE* this_node)를 작성(10점)
void InsertSibling(NODE* prev_node, NODE* this_node){
	//todo
	this_node->parent = prev_node->parent;

	this_node->prev = prev_node;
	prev_node->next = this_node;

	}


//5. Parse tree의 특정 node를 root로 하는 subtree를 DFS 순서로 char* name을 출력하는 함수 WalkTree(NODE *node)를 작성(10점)
void WalkTree(NODE* node){
    if(node == NULL){
        return;
    }
    
    printf("(");
    printf("%s", node->name);
    
    if(node->child != NULL){ //child가 없을 때까지 반복.
        printf("\n"); 
        NODE* current_child = node->child;
        
        while(current_child != NULL){
            WalkTree(current_child); //재귀 호출.
            
            if(current_child->next != NULL){
                printf("\n");
            }
            
            current_child = current_child->next;
        }
    }
    
    printf(")");
}
// 6. node.c의 구현 검증: 그림 3과 같은 parse tree를 생성하고 출력하기(problem2.jpg)(10점)
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

		WalkTree(A);
		
		return 0;
	}