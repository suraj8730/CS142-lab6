#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;
	node(int value){
		data=value;
		left=NULL;
		right=NULL;
	}
};
class BIST{
public:
	node* root;
	BIST(){
		root=NULL;
	}
	void insert(int value){
		insertHelper(root,value);
	}
	void insertHelper(node* curr,int value){
		//Base case if curr is NULL ,insert there
		if(root==NULL){
			//curr=new node(value);
			//(root == NULL){
			 root =new node(value) ;//}                                                                       
			return;
		}
		//Else compare the curr data with value
		else if (value  <  curr->data){
		//if curr data > value ==> move right and call insert
			if(curr->left==NULL)curr->left=new node(value);
			else
			//node* temp=curr;
				insertHelper(curr->left,value);
			//temp->left=curr;
		}
		else{	
		//else move right and call insert
			if(curr->right==NULL)curr->right=new node(value);
			else
				//node* temp=curr;
				insertHelper(curr->right,value);
				//temp->left=curr;
		}
		
	}
	void display(){display2(root);cout<<endl;}
	void display2(node * curr){
		if (curr == NULL) return;
		//display left
		display2(curr->left);
		//display current
		cout<<curr->data<<",";
		//display right
		display2(curr->right);
}
	node* search(int no){
	return search2(root,no);
	}
	node* search2(node * curr, int value){
			if (curr == NULL || curr->data == value) return curr;
			else if (value < curr->data)
				//search for number in left
				return search2(curr->left,value);
				//search number in right
			else 
				return search2(curr->right,value);
	}
	//Next class- Friday
	//height();
	//deletNode();
};
int main(){
BIST a;
a.insert(5);
a.insert(3);
a.insert(4);
a.insert(6);
a.insert(9);
a.insert(1);
cout<<"adress of your search is "<<a.search(6)<<endl;
cout<<a.search(6)->data<<endl;
a.display();
return 0;
}
