#include <iostream>
#include <queue>
#define SIZE 1000000
#define INT_MAX 1000000000
using namespace std;


class stack{
	private:
		int* arr;
		int top;
		int capacity;
	public:
		//constructor
		stack(int size=SIZE){
			arr = new int[size];
			top=-1;
			capacity = size;	
		}
		//destructor
		~stack(){
			delete[] arr;
		}
		//push element O(1) worst case
		void push(int val){
			if(!isfull()){
				top++;
				arr[top]=val;
			}
			else
				cout<<"Stack is Full, pop some element to insert new element"<<endl;
		}
		//pop element O(1) worst case
		void pop(){
			if(!isempty()){
				top--;
			}
			else
				cout<<"Empty Stack, invalid calling"<<endl;
		}
		//top element O(1)
		int peek(){
			if(top!=-1){
				return arr[top];
			}
			else
				cout<<"Empty Stack, invalid calling"<<endl;
		}
		bool isempty(){
			return top==-1;
		}
		bool isfull(){
			return top==capacity-1;
		}
};


class queue{
	private:
		int* arr;
		int front;
		int rear;
		int capacity;
		int curr_size;

	public:
		//constructor
		queue(int size=SIZE){
			arr = new int[size];
			front=0;
			rear=-1;
			capacity=size;
			curr_size=0;
		}
		//destructor
		~queue(){
			delete[] arr;
		}
		//push element O(1)
		void push(int val){
			if(!isfull()){
				rear++;
				arr[rear]=val;
				curr_size++;
			}
			else
				cout<<"Queue is Full, pop some element to insert new element"<<endl;
		}
		//pop element O(1)
		void pop(){
			if(!isempty()){
				front++;
				curr_size--;
			}
			else
				cout<<"Empty Queue, invalid calling"<<endl;
		}
		//peek front O(1)
		int peek_front(){
			if(front!=-1){
				return arr[front];
			}
			else
				cout<<"Empty Queue, invalid calling"<<endl;

		}
		//peek rear O(1)
		int peek_rear(){
			if(rear!=0){
				return arr[rear];
			}
			else
				cout<<"Empty Queue, invalid calling"<<endl;
		}
		bool isempty(){
			return curr_size==0;
		}
		bool isfull(){
			return curr_size==capacity;
		}

};

struct Node{
	int val;
	Node*left;
	Node*right;

	Node(int x){
		val=x;
		left=NULL;
		right=NULL;
	}
};

class BST{
	private:
		Node* root;

	public:
		//constructor
		BST(){
			root = NULL;
		}
		BST(int x){
		    root = new Node(x);
		}
		//desctructor
		~BST(){
			delete root;
		}
		//root
		Node* root_(){
		    return root;
		}
		//iterative insertion O(n)
		void insert(int x){
			if(root==NULL){
				root = new Node(x);
			}
			else{
				queue<Node*>q;
				q.push(root);
				while(!q.empty()){
					Node* temp = q.front();
					q.pop();
					if(temp->val>x){
						if(temp->left){
							q.push(temp->left);	
						}
						else{
							temp->left = new Node(x);
						}
					}
					else{
						if(temp->right){
							q.push(temp->right);
						}
						else{
							temp->right = new Node(x);
						}
					}
				}
			}
		}
		//recursive insertion O(n)
		void insert(Node* root, int x){
			if(root==NULL){
				root = new Node(x);
			}
			else{
				if(x<root->val){
				    if(root->left){
					    insert(root->left,x);
				    }
					else{
					    root->left = new Node(x);
					}
				}
				else{
				    if(root->right){
					    insert(root->right,x);
				    }
					else{
					    root->right = new Node(x);
					}
				}
			}
		}
		//preorder traversal O(n)
		void preorder(Node* root){
			if(root==NULL) return;
			cout<<root->val<<" ";
			inorder(root->left);
			inorder(root->right);
		}
		//postorder traversal O(n)
		void postorder(Node* root){
			if(root==NULL) return;
			inorder(root->left);
			inorder(root->right);
			cout<<root->val<<" ";
		}
		//inorder traversal O(n)
		void inorder(Node* root){
			if(root==NULL) return;
			inorder(root->left);
			cout<<root->val<<" ";
			inorder(root->right);
		}

};

struct node{
	int val;
	node* next;

	node(int x){
		val=x;
		next=NULL;
	}
};
class list{
	private:
		node* root;

	public:
		//constructor
		list(){
			root=NULL;
		}
		list(int x){
		    root = new node(x);
		}
		//destructor
		~list(){
			delete root;
		}
		node* root_(){
			return root;
		}
		//insertion
		void insert(int x){
			if(root==NULL){
				root = new node(x);
			}
			else{
			    node* temp = root;
				while(temp->next!=NULL){
					temp=temp->next;
				}
			    temp->next = new node(x);
			}
		}
		//deletion by pointer
		void remove(node* temp){
			if(root==temp){
				root=root->next;
			}
			else if(temp->next==NULL){
				delete temp;
			}
			else{
			    node* temp2 = root;
				while(temp2->next!=temp){
					temp2=temp2->next;
				}
			    temp2->next = temp->next;
			
			}
		}
		//deletion by value
		void remove(int x){
			if(root->val==x){
				root==NULL;
			} 
			else if(root->next==NULL&&root->val==x){
				root=NULL;
			}
			else{
			    node* temp = root;
				while(temp->next!=NULL){
					if(temp->next->val==x){
						break;
					}
					temp=temp->next;
				}
				temp->next = temp->next->next;
			}
		}
		//reverse list
		void reverse(){
			node* curr=root;
			node* next=NULL;
			node* prev=NULL;
			while(curr!=NULL){
				next = curr->next;
				curr->next=prev;
				prev = curr;
				curr = next;
			} 
			root=prev;
		}
		//print list
		void print(){
		    node* temp = root;
			while(temp!=NULL){
				cout<<temp->val<<" ";
				temp=temp->next;
			}
		}


};

