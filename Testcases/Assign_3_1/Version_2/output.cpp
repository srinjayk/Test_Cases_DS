#include <bits/stdc++.h> 
using namespace std; 

struct TreapNode{ 
	int key, priority; 
	TreapNode *left, *right; 
}; 


TreapNode *rightRotate(TreapNode *y){ 
	TreapNode *x = y->left, *T2 = x->right; 

	x->right = y; 
	y->left = T2; 

	return x; 
} 

int maxDepth(TreapNode* root)  {  
    if (root == NULL)  
        return 0;  
    else{  
        int lDepth = maxDepth(root->left);  
        int rDepth = maxDepth(root->right);  
      
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
} 

TreapNode *leftRotate(TreapNode *x){ 
	TreapNode *y = x->right, *T2 = y->left; 

	y->left = x; 
	x->right = T2; 

	return y; 
} 

TreapNode* newNode(int key, int prior){ 
	TreapNode* temp = new TreapNode; 
	temp->key = key; 
	temp->priority = prior; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

TreapNode* search(TreapNode* root, int key){ 
	if (root == NULL || root->key == key) 
	    return root; 

	if (root->key < key) 
	    return search(root->right, key); 

	return search(root->left, key); 
} 


TreapNode* insert(TreapNode* root, int key, int prior){ 
	
	if (!root) 
		return newNode(key, prior); 

	if (key <= root->key){ 

		root->left = insert(root->left, key, prior);
		if (root->left->priority < root->priority) 
			root = rightRotate(root); 
	} 
	else{ 
		
		root->right = insert(root->right, key, prior); 
		if (root->right->priority < root->priority) 
			root = leftRotate(root); 
	} 
	return root; 
} 


TreapNode* deleteNode(TreapNode* root, int key) 
{ 
	if (root == NULL) 
		return root; 

	if (key < root->key) 
		root->left = deleteNode(root->left, key); 
	else if (key > root->key) 
		root->right = deleteNode(root->right, key);

	else if (root->left == NULL){ 
		TreapNode *temp = root->right; 
		delete(root); 
		root = temp;
	} 
	else if (root->right == NULL){ 
		TreapNode *temp = root->left; 
		delete(root); 
		root = temp;
	}
	else if (root->left->priority < root->right->priority){ 
		root = leftRotate(root); 
		root->left = deleteNode(root->left, key); 
	} 
	else{ 
		root = rightRotate(root); 
		root->right = deleteNode(root->right, key); 
	} 

	return root; 
} 

void inorder(TreapNode* root){ 
	if (root){ 
	    if(root->left)
		    inorder(root->left); 
		cout <<root->key<<" "<<root->priority<<endl;
		if(root->right)
		    inorder(root->right); 
	} 
} 

void preorder(TreapNode* root){ 
	if (root){ 
	    cout <<root->key<<" "<<root->priority<<endl;
	    if(root->left)
		    preorder(root->left);
		if(root->right)
		    preorder(root->right); 
	} 
} 

// int calcheight

int main(){ 
	srand(time(NULL)); 

	int t;
	cin >>t;
	
	while(t--){
	    
	    int n;
	    cin >>n;
	    
	    int val[n];
	    int prior[n];
	    
	    for(int i=0;i<n;i++){
	        cin >>val[i];
	    }
	    
	    for(int i=0;i<n;i++){
	        cin >>prior[i];
	    }
	    struct TreapNode *root = NULL; 
	    
	    for(int i=0;i<n;i++){
	        root = insert(root, val[i], prior[i]);
	    }
	    
	   // inorder(root);
	    cout <<"Inorder"<<endl;
	    inorder(root);
	    cout <<"Preorder"<<endl;
	    preorder(root);
	    cout <<"Height"<<endl;
	    cout <<maxDepth(root)<<endl;
	    
	}

	return 0; 
} 
