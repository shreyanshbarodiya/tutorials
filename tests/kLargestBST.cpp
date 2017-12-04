#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
};

Node* newNode(int data){
	Node *node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void insert(Node* root,int data){

	if(root->data > data){
		if(root->left == NULL){
			Node* node = newNode(data);
			root->left = node;
		}else{
			insert(root->left, data);
		}
	}else if(root->data < data){
		if(root->right == NULL){
			Node* node = newNode(data);
			root->right = node;
		}else{
			insert(root->right, data);
		}
	}

}

void inOrderForN(Node* root, int* n){
	if(root == NULL){
		return;
	}
	inOrderForN(root->left,n);
	cout<< root->data<< " ";
	*n = *n + 1;
	inOrderForN(root->right,n);
	return ;
}

int inOrderForAns(Node* root,int t, int* m){
	if(root == NULL){
		return -1000;
	}
	inOrderForAns(root->left,t,m);
	*m = *m + 1;
	if(*m == t ){
		cout << root->data;
		return root->data;
	}
	inOrderForAns(root->right,t,m);
}

int kthLargest(Node* root, int k){
	int n ;
	n = 0;
	inOrderForN(root, &n);
	cout << endl << "n is : " << n<<endl;

	int m;
	m = 0;
	cout << "Kth largest is: "<< endl;
	return inOrderForAns(root,n-k+1, &m);
}

int main(){
	int k = 1;
	Node * root = newNode(5);
	insert(root,4);
	insert(root,6);
	insert(root,7);
	insert(root,8);
	insert(root,42);
	insert(root,-1);

	cout << kthLargest(root, k );

	return 0;
}