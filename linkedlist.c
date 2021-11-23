#include <stdio.h>
#include <stdlib.h>
struct node{
 int data;
 struct node* link;
};
struct node *head = NULL, *cur, *temp, *temp1;
struct node* create(){
 int n;
 printf("Enter number of node: ");
 scanf("%d", &n);
 while(n--){
  cur = (struct node*)malloc(sizeof(struct node));
  scanf("%d", &(cur->data));
  cur -> link = NULL;
  if(head == NULL)
   head = cur;
  else{
   temp = head;
   while(temp -> link != NULL)
    temp = temp -> link;
   temp -> link = cur;
  }
 }
 return head;
}

struct node* insert_begin(int ele){
 cur = (struct node*)malloc(sizeof(struct node));
 cur -> data = ele;
 cur -> link = head;
 head = cur;
 return head;
}
	
struct node* insert_end(int ele){
 cur = (struct node*)malloc(sizeof(struct node));
 cur -> data = ele;
 cur -> link = NULL;
 temp = head;
 while(temp -> link != NULL)
  temp = temp -> link;
 temp -> link = cur;
 return head;
}

struct node* insert_pos(int pos, int ele){
 cur = (struct node*)malloc(sizeof(struct node));
 cur -> data = ele;
 int c;
 temp = head;
 while(c < pos - 1){
  temp = temp -> link;
  c++;
 }
 cur -> link = temp -> link;
 temp -> link = cur;
 return head;
}

struct node* delete_begin(){
 temp = head;
 head = temp -> link;
 printf("\nDeleted element: %d", temp -> data);
 free(temp);
 return head;
}

struct node* delete_end(){
 temp = head;
    temp1 = temp -> link;
 while(temp1 -> link != NULL){
  temp = temp -> link;
        temp1 = temp -> link;
    }
 printf("\nDeleted element: %d", temp1 -> data);
 free(temp1);
 temp -> link = NULL;
 return head;
}

struct node* delete_pos(int pos){
 temp = head;
 int c = 0;
  while(c < pos){
  temp1 = temp;
  temp = temp -> link;
  c++;
 }
 temp1 -> link = temp -> link;
 printf("\nDelted element: %d", temp -> data);
 free(temp);
 return head;
}

void display(){
    temp = head;
    printf("\n");
    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> link;
    }
}

void reverse_display(struct node * head){
    printf("\n");
    if(head != NULL){
        reverse_display(head -> link);
        printf("%d ", head -> data);
    }
}

int search(int key){
    int c = 1;
    temp = head;
    while(temp != NULL){
        if(temp -> data == key)
            return c;
        temp = temp -> link;
        c++;
    }
    return -1;
}

struct node * sort(){
    int x;
    temp = head;
    temp1 = head;
    while(temp != NULL){
        while(temp1 != NULL){
            if(temp1 -> data > temp1 -> link -> data){
                x = temp1 -> data;
                temp1 -> data = temp1 -> link -> data;
                temp1 -> link -> data = x;
            }
            temp1 = temp1 -> link;
        }
        temp = temp -> link;
    }
    return head;
}
	
int main(){
 int ch, ele, pos, key;
    while(1){
        printf("1-Create\n2-Insert begin\n3-Insert at end\n4-Insert at position\n5-Delete begin\n6-delete at end\n7- Delete at position\n8-Display\n9-Reverse display\n10-Search\n11-Sort\n12-Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            head = create();
            break;
        case 2:
            scanf("%d", &ele);
            head = insert_begin(ele);
            break;
        case 3:
            scanf("%d", &ele);
            head = insert_end(ele);
            break;
        case 4:
            printf("enter position");
            scanf("%d", &pos);
            printf("\nEnter element");
            scanf("%d", &ele);
            head = insert_pos(pos, ele);
            break;
        case 5:
            head = delete_begin();
            break;
        case 6:
            head = delete_end();
            break;
        case 7:
            scanf("%d", &pos);
            head = delete_pos(pos);
            break;
        case 8:
            display();
            break;
        case 9:
            reverse_display(head);
            break;
        case 10:
            scanf("%d", &key);
            pos = search(key);
            if(pos = -1){
                printf("\nElement is not found");
            }
            else{
                printf("\nElement found at position %d", pos);
            }
            break;
        case 11:
            head = sort();
            break;
        case 12:
            exit(0);
        }
    }
 return 0;
}
