#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node * next;
   struct node * prev;
};

struct node * head ,* tail;
struct node * head1,* tail1 ;

void create(){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data ");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    if(head==0){
        head = tail = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void createnewlist(){
    struct node * newnode1 = (struct node *)malloc(sizeof(struct node));
    printf("Enter data ");
    scanf("%d",&newnode1->data);
    newnode1->prev=0;
    newnode1->next=0;
    if(head1==0){
        head1 = tail1 = newnode1;
    }
    else{
        tail1->next = newnode1;
        newnode1->prev = tail1;
        tail1 = newnode1;
    }
}

void insertatbegin(){
    int data;
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data :");
    scanf("%d",&newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    newnode->prev = NULL;
    newnode->next = head;
    head = newnode;
};

void insertatindex(){
    int pos=0,i=1;
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    struct node * p = head;
    printf("enter the postion : ");
    scanf("%d",&pos);
    if(pos<1){
        printf("Invalid option");
    }
    else if (pos==1){
        insertatbegin();
    }
    else{
        printf("Enter the data : ");
        scanf("%d",&newnode->data);
        while(i!=pos-1){
            p = p->next;
            i++;
        }
        newnode->prev = p;
        newnode->next = p->next;
        p->next = newnode;
        p->next->prev = newnode;
    }
};

void insertatend(){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
};

struct node * deleteatbegin(struct node * head){
    struct node*temp;
    if(head==0){
        printf("List is empty");
    }
    else{
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        return head;
    }
}

struct node * deletefromend(struct node * head,struct node * tail){
    struct node * temp;
    if (tail = 0)
    {
        printf("\n List Empty\n");
    }
    else{
        temp = tail;
        temp->prev->next = 0 ;
        tail = tail->prev;
        free(temp);
    }
    
}

void deleteatpos(){
    int pos,i=1;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<1){
        printf("Invalid position!");
        return;
    }
    else if(pos==1){
        deleteatbegin(head);
    }
    else{     
        struct node *temp=head;
        while(pos!=i){
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}

void search(){
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    struct node *temp=head;
    int count=0; //starting counting from 0
     while(temp!=NULL){
        temp=temp->next;
        count++;
        if(temp!=NULL && temp->data==data){
            printf("\nElement found at %d position",count);
            return;
        }
    }
    printf("\nElement not found!\n");   
}
void sort(){
    struct node *p=head,*q=NULL;
    while(p->next!=NULL){
        q=p->next;
        while(q!=NULL){
            if(p->data > q->data){
                int temp = p->data;
                p->data=q->data;
                q->data=temp;
            }
            q=q->next;
        }
        p=p->next;
    }
}

void reverse(){
  struct node *p= NULL,*p1;  
  while(head!=NULL){
      p1 = head;
      head = head -> next;
      p1->prev = p1->next;
      p1-> next = p;
      p = p1;
  }
  head = p1;
}

void concat(struct node *ptr, struct node *ptr1){
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=ptr1;
}

struct node *intersection(struct node *ptr, struct node *ptr1) {
    struct node *result = NULL; 
    struct node *p = ptr; 
    while (p != NULL) {
        struct node *q = ptr1;
        while (q != NULL) {
            if (p->data == q->data) {
                struct node *newNode = (struct node *)malloc(sizeof(struct node));
                newNode->data = p->data;
                newNode->next = result;
                result = newNode;
                break; 
            }
            q = q->next;
        }
        p = p->next;
    }
    return result; 
}

void display(){
    struct node * temp = head;
    while(temp!=NULL){
        printf("Element : %d\n",temp->data);
        temp = temp->next;
    }
}

int main(){
    int ops;
    printf("\n1) Create \n2) Display \n3) Insert at begin \n4) Insert at index \n5) Insert at End \n6) Delete at Begin \n7) Delete at end \n8) Delete at pos \n9) Search \n10) Sort \n11) Reverse \n12) Create newlist \n13) Concat \n14) Intersection \n15) Exit \n");
    while(ops!=15){
        printf("\nEnter the choice : ");
        scanf("%d",&ops);
        switch(ops){
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insertatbegin();
                break;
            case 4:
                insertatindex();
                break;
            case 5:
                insertatend();
                break;    
            case 6:
                head = deleteatbegin(head);
                break;    
            case 7:
                head = deletefromend(head,tail);
                break; 
            case 8:
            	 deleteatpos();
                break;
			   case 9:
				   search();
			      break;
			   case 10:
			      sort();
				   break;
		    	case 11:
				  reverse();
			      break;	
			   case 12:
				  createnewlist();
			     break;	
			   case 13:
				  concat(head,head1);
			     break;	
			   case 14 :
				  intersection(head,head1);
			     break;
		   	case 15:
			     break;			       
        }
    }
    return 0;
}
