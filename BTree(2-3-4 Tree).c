/*  BTree Data Structure with Insert,Search,Delete functions */

#include<stdio.h>
#include<stdlib.h>

struct bTreeNode
{
    int keys[3]; 		 // An array of keys
    struct bTreeNode *C[4]; 	// An array of child pointers
    int n;    			// Current number of keys
    int leaf; 			// Is 1 when node is leaf. Otherwise 0
};

struct bTree				// Structure pointing to root node of the tree
{
    struct bTreeNode * root;
};

int t = 2;				// minimum degree for 2-3-4 tree

int search(struct bTreeNode *x, int k)
{
    int i = 0;
    while(i < x->n && k > x->keys[i])
    {
        printf("%d ",x->keys[i]);
        i++;
    }
    if(i < x->n && k == x->keys[i])
    {
        printf("%d ",x->keys[i]);
        return 1;
    }
    else if(x->leaf)
    {
        return -1;
    }
    else
    {
        return search(x->C[i],k);
    }
    return 0;
}

void bTree_Create(struct bTree * T)								// Setting initial structure of Tree(first node)
{
    struct bTreeNode *temp = (struct bTreeNode *)malloc(sizeof(struct bTreeNode));
    temp->leaf = 1;
    temp->n = 0;
    T->root = temp;
}

int bTree_splitChild(struct bTreeNode * x, int i)						// function to split child in case when node is full and next key is to be entered
{
    int j;
    struct bTreeNode * z = (struct bTreeNode *)malloc(sizeof(struct bTreeNode));	// z is new child node
    struct bTreeNode * y;
    y = x->C[i];
    z->leaf = y->leaf;
    z->n = t - 1;
    for(j = 1;j <= t - 1;j++)	// setting keys for node z
    {
        z->keys[j - 1] = y->keys[j - 1 + t];
    }
    if(!(y->leaf))
    {
        for(j = 1;j <= t;j++)
        {
            z->C[j - 1] = y->C[j - 1 + t];
        }
    }
    y->n = t - 1;					// reducing no of elemnts in node y
    for( j = x->n + 1;j >= i + 1;j--)
    {
        x->C[j] = x->C[j - 1];
    }
    x->C[i + 1] = z;				// making z new child of x
    for(j = x->n;j > i;j--)
    {
        x->keys[j] = x->keys[j - 1];
    }
    x->keys[i] = y->keys[t - 1];		
    x->n = x->n + 1;

    return 1;
}

int bTree_insertNonFull(struct bTreeNode * x,int k)
{
    int i = x->n;
    if(x->leaf)
    {
        while(i >= 1 && k < x->keys[i - 1])
        {
            x->keys[i] = x->keys[i - 1];
            i--;
        }
        x->keys[i] = k;
        x->n = x->n + 1;
    }
    else
    {
        while(i >= 1 && k < x->keys[i - 1])
        {
            i--;
        }
        i++;
        if(x->C[i - 1]->n == 2 * t - 1)		// if child is full and not a leaf first split then insert.
        {
            bTree_splitChild(x,i - 1);
            if(k > x->keys[i - 1])
            {
                i++;
            }
        }
        bTree_insertNonFull(x->C[i - 1],k);
    }
    return 2;
}

int bTree_insert(struct bTree *T,int k)
{
    struct bTreeNode * r = T->root;
    if(r->n == 2 * t - 1)				// if the root node is full then making new root
    {
        struct bTreeNode * s = (struct bTreeNode *)malloc(sizeof(struct bTreeNode));
        T->root = s;
        s->leaf = 0;
        s->n = 0;
        s->C[0] = r;
        bTree_splitChild(s,0);			//calling split child on first child of root node
        bTree_insertNonFull(s,k);
    }
    else						// directly inserting in case root is not full
    {
        bTree_insertNonFull(r,k);
    }
    return 3;
}

void bTree_traverse(struct bTreeNode * x)		// function for traversing Tree in increasing order
{
    int i;
    for (i = 0; i < x->n; i++)
    {
        if (!x->leaf)
            bTree_traverse(x->C[i]);
        printf("%d ",x->keys[i]);
    }

    if (!x->leaf)
        bTree_traverse(x->C[i]);
}

int findkey(struct bTreeNode * x,int k)			// A function that returns the index of the first key that is greater or equal to k
{
    int i = 0;
    while(i < x->n && x->keys[i] < k)
    {
        ++i;
    }
    return i;
}

void merge(struct bTreeNode * x, int idx)	    // A function to merge idx-th child of the node with (idx+1)th child of the node
{
    int i;
    struct bTreeNode *child = x->C[idx];
    struct bTreeNode *sibling = x->C[idx + 1];

    // Pulling a key from the current node and inserting it into (t-1)th position of C[idx]
    child->keys[t - 1] = x->keys[idx];

    // Copying the keys from C[idx+1] to C[idx] at the end
    for (i = 0; i < sibling->n; ++i)
            child->keys[i+t] = sibling->keys[i];

    if (!child->leaf)				// if child is not a leaf then Copying the child pointers from C[idx+1] to C[idx]
    {
        for(i = 0; i <= sibling->n; ++i)
            child->C[i+t] = sibling->C[i];
    }
    for (i = idx + 1; i < x->n; ++i)		// shifting keys
        x->keys[i-1] = x->keys[i];

    for (i = idx + 2; i <= x->n; ++i)		// shifting child pointers
        x->C[i-1] = x->C[i];

    child->n += sibling->n + 1;			// Updating the key count of child
    x->n--;					// Updating the key count of current node
    free(sibling);
    return;
}

int getPred(struct bTreeNode *x,int idx)	 // A function to get the predecessor of the key- where the key is present in the idx-th position in the node
{
    struct bTreeNode *cur = x->C[idx];
    while(!cur->leaf)
    {
        cur = cur->C[cur->n];
    }
    return cur->keys[cur->n - 1];

}

int getSucc(struct bTreeNode *x,int idx)       // A function to get the successor of the key- where the key is present in the idx-th position in the node
{
    struct bTreeNode * cur = x->C[idx + 1];
    while(!cur->leaf)
    {
        cur = cur->C[0];
    }
    return cur->keys[0];
}


void borrowFromPrev(struct bTreeNode * x,int idx)	// A function to borrow a key from the C[idx-1]-th node and place it in C[idx]th node
{
    int i;
    struct bTreeNode *child = x->C[idx];
    struct bTreeNode *sibling = x->C[idx - 1];
    //shifting all key in child one step ahead
    for (i = child->n - 1; i >= 0; --i)
        child->keys[i+1] = child->keys[i];
    // shifting the child pointer one step ahead
     if (!child->leaf)
     {
         for(i = child->n; i >= 0; --i)
             child->C[i+1] = child->C[i];
     }

    child->keys[0] = x->keys[idx-1];		// setting child keys[0] to be last key of parent node


    if (!x->leaf)				// Moving sibling's last child as C[idx]'s first child
        child->C[0] = sibling->C[sibling->n];
    x->keys[idx - 1] = sibling->keys[sibling->n - 1];		// setting parent key as sibbling's last key
    child->n += 1;				// increasing the count of keys in  child
    sibling->n -=1;				// decreasing the count of keys in siblings
    return;
}
void borrowFromNext(struct bTreeNode * x,int idx)	// A function to borrow a key from the C[idx+1]-th node and place it in C[idx]th node
{
    int i;
    struct bTreeNode *child = x->C[idx];
    struct bTreeNode *sibling = x->C[idx + 1];

    child->keys[child->n] = x->keys[idx];		// keys[idx] is inserted as the last key in C[idx]

    if(!child->leaf)
    {
        child->C[child->n + 1] = sibling->C[0];
    }
    x->keys[idx] = sibling->keys[0];		//The first key from sibling is inserted into keys[idx]

    // shifting all keys in sibling one step behind
    for (i = 1; i < sibling->n; ++i)
        sibling->keys[i-1] = sibling->keys[i];

    //shifting the child pointers
    if(!sibling->leaf)
     {
         for(i = 1; i <= sibling->n; ++i)
            sibling->C[i-1] = sibling->C[i];
     }

    child->n += 1;		// increasing the count of keys in  child
    sibling->n -=1;		// decreasing the count of keys in siblings
    return;
}


void removeFromLeaf(struct bTreeNode * x, int idx)		// FUNCTION TO DELETE KEY FROM A LEAF NODE
{
    int i;
    for (i = idx + 1; i < x->n; i++)
        x->keys[i - 1] = x->keys[i];	 // SHIFTING KEYS IN NODE IF NECESSARY
    x->n--;				 // Reduce the count of keys

    return;
}

void removeFromNonLeaf(struct bTreeNode *x,int idx)		// FUNCTION TO DELETE KEY FROM INTERNAL NODE(NON LEAF)
{

    int pred,succ;
    int k = x->keys[idx];

    // If the child that precedes k (C[idx]) has atleast t keys, find the predecessor 'pred' of k in the subtree rooted at C[idx].
    //Replace k by pred. Recursively delete pred in C[idx]

    if(x->C[idx]->n >= t)
    {
        pred = getPred(x,idx);
        x->keys[idx] = pred;
        delete_atnode(x->C[idx],pred);
    }
    // If the child C[idx] has less that t keys, examine C[idx+1].If C[idx+1] has atleast t keys, find the successor 'succ' of k in the subtree rooted at C[idx+1]
        // Replace k by succ Recursively delete succ in C[idx+1]
    else if(x->C[idx + 1]->n >= t)
    {
        succ = getSucc(x,idx);
        x->keys[idx] = succ;
        delete_atnode(x->C[idx + 1],succ);
    }
    // If both C[idx] and C[idx+1] has less that t keys,merge k and all of C[idx+1] into C[idx] Now C[idx] contains 2t-1 keys
        // Free C[idx+1] and recursively delete k from C[idx]
    else
    {
        merge(x,idx);
        delete_atnode(x->C[idx],k);
    }
    return;
}


void fill(struct bTreeNode * x, int idx)
{
    // If the previous child(C[idx-1]) has more than t-1 keys, borrow a key from that child
    if(idx != 0 && x->C[idx - 1]->n >= t)
    {
        borrowFromPrev(x,idx);
    }
    // If the next child(C[idx+1]) has more than t-1 keys, borrow a key from that child
    else if(idx != x->n && x->C[idx + 1]->n >= t)
    {
        borrowFromNext(x,idx);
    }
    // Merge C[idx] with its sibling If C[idx] is the last child, merge it with with its previous sibling
    // Otherwise merge it with its next sibling

    else
    {
        if(idx != x->n)
        {
            merge(x,idx);
        }
        else
        {
            merge(x,idx - 1);
        }
    }
    return;
}

void delete_atnode(struct bTreeNode *x,int k)
{
    int idx = findkey(x,k);
    if(idx < x->n && x->keys[idx] == k)
    {
        if(x->leaf)
        {
            removeFromLeaf(x,idx);
        }
        else
        {
            removeFromNonLeaf(x,idx);
        }
    }
    else
    {
        if(x->leaf)
        {
            printf("The Key %d does not exist in the tree\n");
            return;
        }
        int flag = ((idx == x->n)?1:0);
        if(x->C[idx]->n < t)
        {
            fill(x,idx);
        }
        if(flag && idx > x->n)
        {
            delete_atnode(x->C[idx - 1],k);
        }
        else
        {
            delete_atnode(x->C[idx],k);
        }
    }
    return;
}


struct bTreeNode * remove_atnode(struct bTreeNode * x,int k)
{
    if(x == NULL)
    {
        printf("The Tree is Empty\n");
        return x;
    }

    delete_atnode(x,k);
    if(x->n == 0)			//if root node is empty
    {
        struct bTree * temp = (struct bTree*)malloc(sizeof(struct bTree));
        temp->root = x;
        if(x->leaf)
        {
            x = NULL;
        }
        else
        {
            x = x->C[0];		// making child as new root
        }
        free(temp);
    }
    return x;
}

int main()
{
    int m,i,p,choice,searchNo,deleteNo,flag = 0;
    struct bTree *T = (struct bTree*)malloc(sizeof(struct bTree));
    bTree_Create(T);
    printf("Enter number of values to be inserted : ");
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&p);
        bTree_insert(T,p);
    }
    while(1)
    {
        printf("\nEnter\n1) Insert\n2) Search\n3) Delete\n4)Traverse\n5) Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    printf("Enter value to be inserted in Tree \n");
                    scanf("%d",&p);
                    if(T->root != NULL)
                   		 bTree_insert(T,p);
                   	else
					{
                   		bTree_Create(T);
                   		bTree_insert(T,p);
                   	}
                    break;
            case 2:
                    printf("Enter value to be searched in Tree \n");
                    scanf("%d",&searchNo);
                    flag = search(T->root,searchNo);
                    if(flag != 1)
                    {
                        printf("\nKey Not Found\n");
                    }
                    break;
            case 3:
                    printf("Enter value to be deleted from Tree \n");
                    scanf("%d",&deleteNo);
                    T->root = remove_atnode(T->root,deleteNo);
                    break;
            case 4:
            		if(T->root != NULL)
                    	bTree_traverse(T->root);
                    else
                    	printf("\nNothing to traverse\n");
                    break;
            case 5:
                    exit(12);
            default :
                    printf("Please Enter correct choice\n");
        }
    }
    return 11;
}

