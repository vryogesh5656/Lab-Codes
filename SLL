#include <stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node * next;
};

void traversal(struct node * head){
    struct node * ptr = head;
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct node * insertatbegin(struct node * head , int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = head;
    return ptr;
};

struct node * insertatindex(struct node * head , int data , int index){
    int i =0;
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p -> next;
    p -> next = ptr;
    return head;
};

struct node * insertatend(struct node * head,int data){
   struct node * ptr = (struct node * )malloc(sizeof(struct node));
   struct node * p = head;
   while(p->next!=NULL){
       p = p->next;
   }
   ptr -> data = data;
   ptr -> next = NULL;
   p->next = ptr;
   return head;
};

struct node * deleteatbegin(struct node * head ){
    struct node * p = head;
    head = head->next;
    free(p);
    return head;
};

struct node * deleteatindex(struct node * head , int index){
    struct node * p = head;
    struct node * q = head->next;
    for(int i = 0 ; i < index - 1;i++){
        p = p -> next; 
        q = q-> next;
    }
    p->next = q->next;
    free(q);
    return head;
};

struct node * deleteatend(struct node * head){
    struct node * p = head;
    struct node * q = head->next;
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
};

struct node * search(struct node * head , int key){
  struct node * ptr = head ;
  int i =0;
  while(ptr!=NULL){
      if(ptr->data == key){
          printf("Key found\n");
          i++;
          return head;
      }
      ptr = ptr -> next;
  }
  printf("not found \n ");
  return head;
};

struct node * sort(struct node * head){
    int temp;
    struct node * p = head;
    while(p->next!=NULL){
        struct node * q = p->next;
        while(q!=NULL){
            if(p->data > q->data){
                temp = p ->data;
                p -> data = q -> data;
                q -> data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
    return head;
};

struct node * reverse(struct node * head){
  struct node * prev , *current,*nextnode;  
  prev = 0;
  current = nextnode = head;
  while(nextnode!=NULL){
      nextnode = nextnode->next;
      current->next = prev;
      prev = current;
      current = nextnode;
  }
  head = prev;
};

int main() {
    int ops;
    struct node * head;
    struct node * second;
    struct node * third;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    
    head -> data = 106;
    head -> next = second;
    
    second -> data = 47;
    second -> next = third;
    
    third -> data = 98;
    third -> next = NULL;
    printf("1) Insert at begin \n2) Insert at index \n3) Insert at end \n4) Delete at Begin \n5) Delete at index \n6) Delete at end \n7) Search \n8) Sort \n9) reverse \n10) Exit \n");
    scanf("%d",&ops);
    switch(ops){
            case 1:
               head = insertatbegin(head,7);
               break;
               
            case 2:
               head = insertatindex(head,68,1);
               break;
               
            case 3:
               head = insertatend(head,98);
               break;
               
            case 4:
               head = deleteatbegin(head);
               break;
               
            case 5 :
               head = deleteatindex(head,1);
               break;
               
            case 6 : 
               head = deleteatend(head);
               break;
               
            case 7 :
               head = search(head,7);
               break;
               
            case 8 :
               head = sort(head);
               break;
               
            case 9:
               head = reverse(head);
               break;
            
            case 10 :
               break;
    }

    traversal(head);
    return 0;
}
