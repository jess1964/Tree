#include <iostream>
using namespace std;

class Tree
{
private:
    struct Node
    {
        int i;
        Node *left;
        Node *right;
    };
Node *root;
void clear (Node *&n)
{
    if(n)
    {
        clear(n->left);
        clear(n->right);
        delete n;
    }
}


int insert(Node *&r,Node *&n)
{
    if(!r)
    {
        r = n;
        return 0;
    }
    if(r->i > n->i)
    {
        if(!r->left)
        {
            r->left = n;
            return 0;
        }
        if(r->left)
        {
         return insert(r->left, n);
        }
    }

    if(r->i <= n->i)
    {
        if(!r->right)
        {
            r->right = n;
            return 0;
        }
        if(r->right)
        {
            return insert(r->right,n);

        }
    }
    return -1;
}


void inprint(Node *n) const
{
    if(n)
    {
        inprint(n->left);
        cout << n->i <<" ";
        inprint(n->right);
    }
}


bool find (Node *n, int i) const
{
    if(n->i == i)
    {
        return 1;
    }

    if(n->i <= i)
    {
        if(n->right)
        {
            return find(n->right,i);
        }
        if(!n->right)
        {
            return 0;
        }
    }

    if(n->i > i)
    {
        if(n->left)
        {
            return find(n->left,i);
        }
        if(!n->right)
        {
            return 0;
        }
    }
}



int count(Node *n) const
{
    if(n)
    {
            return 1+ (count(n->left))+(count(n->right));
    }
    if(!n)
    {
        return 0;
    }

}



int seek(Node *&n , int i)
{
    if(n->i == i)
    {
        destroy(n);// call destroy
        return 0;
    }
    if(n->i <= i)
    {
        if(n->right)
        {
            return seek(n->right, i);
        }
        if(!n->left)
        {
            return -1;
        }
    }
    if(n->i > i)
    {
        if(n->left)
        {
            return seek(n->left, i);
        }
        if(!n->left)
        {
            return -1;
        }
    }
    return -1;
}

void destroy(Node *&n)
{
if(!n->left && !n->right)
    {
        delete n;
        n = NULL;
    }
else
    {
        Node *l;
        Node *r;
        l = n->left;
        r = n->right;
        delete n;
        n = NULL;
        copy(l);
        copy(r);
    }

}

void copy(Node *n)
{
    if(n)
    {
        insert(root,n);
    }
}

public:
Tree()
{
    root = NULL;
}

Tree(const Tree &rhs)
{
    root = NULL;
    operator=(rhs);
}

~Tree()
{
    if(root)
    {
        clear();
        delete root;
    }
}
Tree& operator = (const Tree &rhs)
{   if(root)
    {
        clear(root);
        root = NULL;
    }

    Node *temp;
    Node *nerd;
    temp = rhs.root;
    if(!temp)
    {
        return *this;
    }
    while(temp)
    {
        if(!temp->left)
        {
            insert(temp->i);
            temp = temp->right;
        }
        else
        {
           nerd = temp->left;
           while(nerd->right && nerd->right != temp)
           {
               nerd = nerd->right;
           }

           if(!nerd->right)
           {
               nerd->right = temp;
               temp = temp->left;
           }
           else
           {
               nerd->right = NULL;
               insert(temp->i);
               temp = temp->right;
           }

        }
    }
    return *this;
}
bool operator == (const Tree &rhs)
{
     int red[2];
     red[0] = count(root);
     red[1] = count(rhs.root);
     if(red[0] == red[1])
     {
         return 1;
     }
        return 0;
}
bool operator < (const Tree &rhs)
{
     int red[2];

     red[0] = count(root);
     red[1] = count(rhs.root);

     if(red[0] < red[1])
     {
         return 1;
     }
        return 0;
}

bool isFull()
{
    if(root)
    {
        return 1;
    }
    if(!root)
    {
        return 0;
    }
}

bool isEmpty()
{
    if(root)
    {
        return 0;
    }
    if(!root)
    {
        return 1;
    }
}

void clear()
{
    if(root)
    {
        clear(root);
        root = NULL;
    }
}

int insert(int i)
{
    Node *temp;
    temp = new Node;
    temp->i = i;
    temp->left = NULL;
    temp->right = NULL;
    return insert(root,temp);
}

bool find(int i) const
{
    if(root)
    {
        return find(root, i);
    }
    if(!root)
    {
        return 0;
    }
}

int remove (int i)
{
    if(root)
    {
        return seek(root,i);
    }
    if(!root)
    {
        return -1;
    }
}


void inprint() const
{
    if(root)
    {
        inprint(root);
        cout << endl;
    }
}

};
