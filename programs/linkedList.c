#include <stdio.h>
#include <stdlib.h>

typedef struct item{ //Struct of item
    int data; //data in item struct
    struct item * nextitem; //ptr to nextitem
} item;

void fillLinkedList();  //Populates the Linked List with user input
void printLinkedList(); //Prints the data in the Item linked list to the stdout
void freeLinkedList(); //Freeze the memory allocated for the linked list

item * ptrFirst = NULL; //Points to head and tail of list
item *ptrLast = NULL;
int size = 0; // Size of the list


int main() {
    fillLinkedList(); //Calls function to add item to list
    printLinkedList(); //Prints the data in the linked list
    freeLinkedList(); //Unallocates the memory in the linked list 
}

void fillLinkedList() {
    item * temp = NULL; //The last item to be inputted
    
    printf("Please enter the data of the linked list\n");
    
    do  { //Populates the list
        temp = (item*)malloc(sizeof(struct item)); //Allcoates memory for temp
        
        printf("Please enter item #%d's data: ", size+1);
        scanf("%d", &(temp->data));
        if(temp->data == -1){
            continue;
        }
        if(size == 0) {
            ptrFirst = temp; 
        }
        else {
            ptrLast->nextitem = temp;
        }
        ptrLast = temp; 
        ptrLast->nextitem = NULL;
        size++;
    }while (temp->data != -1);
}

void printLinkedList() {
    item * ptrCurrent = NULL; //Points to the current item of the linked list that is to be printed
    ptrCurrent = ptrFirst;
    for(int i = 0; i < size; i++) { //Each iteration prints the data in the current item in the linked list to the stdout
        printf("%d\n", ptrCurrent->data); 
        ptrCurrent = ptrCurrent->nextitem; //Updates ptrCurrent
    }
}

void freeLinkedList() {
    item *ptrCurrent = NULL; //The current memory address that has to be cleared 
    for (int i = 0; i < size; i++) { //Each iteration ptrFirst is updated and ptrCurrent is freed
        ptrCurrent = ptrFirst; 
        ptrFirst = ptrFirst->nextitem;
        free(ptrCurrent);
    }
}