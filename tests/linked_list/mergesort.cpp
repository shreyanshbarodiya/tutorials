#include <iostream>

using namespace std;

struct node{
	int data;
	struct node* next;
};




struct node* SortedMerge(struct node* a, struct node* b){
	struct node* result = NULL;

	if(a==NULL){
		return b;
	}else if(b==NULL){
		return a;
	}

	if(a->data >= b->data){
		result = b;
		result->next = SortedMerge(a,b->next);
	}else{
		result = a;
		result->next = SortedMerge(a->next, b);
	}

	return result;
}

void append(struct node** head, int data){
	struct node* new_node = new node;
	new_node->data = data;
	new_node->next = NULL;
	struct node* curr = *head;

	if(*head==NULL){
		*head = new_node;
		return;
	}

	while(curr->next !=NULL){
		curr=curr->next;
	}

	curr->next = new_node;
	return;
}

void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef){

	struct node* fast;
	struct node* slow;

	if(source==NULL || source->next == NULL){
		*frontRef = source;
		*backRef = NULL;
	}else{
		slow = source;
		fast = source->next;

		while(fast != NULL){
			fast = fast->next;

			if(fast!=NULL){
				slow = slow->next;
				fast = fast->next;
			}
		}
		*frontRef = source;
		*backRef = slow->next;
		slow->next = NULL;
	}
}

void MergeSort(struct node** headRef){
	struct node* head = *headRef;
	struct node* a;
	struct node* b;

	if(head==NULL || head->next ==NULL){
		return;
	}else{
		FrontBackSplit(head,&a,&b);

		MergeSort(&a);
		MergeSort(&b);

		*headRef = SortedMerge(a,b);
	}
}

void print_linked(struct node** head){
	struct node* curr = *head;

	while(curr!=NULL){
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
	return;
}

struct node* reverse(struct node* head, int k){
	struct node* current = head;
	struct node* prev = NULL;
	struct node* next = NULL;

	int count = 0;

	while(current!=NULL && count<k){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	if(next!= NULL){
		head->next = reverse(next,k);
	}

	return prev;
}

void detectAndRemoveLoop(node *head){
	node* slow = head;
	node* fast = head->next;

	while(fast && fast->next){
		if(fast == slow){
			break;
		}else{
			fast = fast->next->next;
			slow = slow->next;
		}
	} 

	if(fast == slow){
		slow = head;

		while(fast->next != slow){
			slow = slow->next;
			fast = fast->next;
		}
		fast->next = NULL;
	}

}

int main(){
	struct node* head = new node;
	head->data = 1;

	append(&head, 2);
	append(&head, 4);
	append(&head, 6);
	append(&head, 8);


	struct node* head2 = new node;
	head2->data = 3;

	append(&head2, 5);
	append(&head2, 7);
	

	struct node* sorted_list = SortedMerge(head,head2);
	print_linked(&sorted_list);

	struct node* reversed_list = reverse(head,3);
	print_linked(&reversed_list);

	head->next->next->next->next->next  = head->next;

	print_linked(&head);
	detectAndRemoveLoop(head);
	


	return 0;
}