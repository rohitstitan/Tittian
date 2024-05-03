
#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node *left;
        node *right;
        int lbit,rbit;
};
class TBT
{
    node *root,*head;
    public:

    TBT()
    {
        root=NULL;
        head = NULL;
    }
    void preorder();
    void inorder();
    void create_TBT();
};
void TBT::create_TBT()
{
    node *temp,*new_node;
    int flag=0;
    char ans;
    //creating head node
    head = new node();
    head->data = -999;
    head->left = head;
    head->right = head;
    head->lbit = 0;
    head->rbit = 0;
    //creating root node
    root = new node();
    cout<<"\n\tEnter root node: ";
    cin>>root->data;
    head->left=root;
    head->lbit=1;
    root->left = head;
    root->right = head;
    root->lbit= 0;
    root->rbit = 0;

    do
    {
        //creating new node
        new_node= new node();
        cout<<"\n\tEnter the node value: ";
        cin>>new_node->data;
        new_node->lbit = 0;
        new_node->rbit =0;

        temp = root;
        flag = 0;
        while(flag==0)
        {
            if(new_node->data < temp->data)
            {
                if(temp->lbit==0)
                {
                    new_node->left= temp->left;
                    temp->left = new_node;
                    temp->lbit=1;
                    new_node->right=temp;
                    flag =1;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if(new_node->data > temp->data)
            {
                if(temp->rbit==0)
                {
                    new_node->right= temp->right;
                    temp->right = new_node;
                    temp->rbit=1;
                    new_node->left=temp;
                    flag =1;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                cout<<"\n\tData already exist.....!!!";
            }
        }
        cout<<"\n\tDo you want to continue:";
        cin>>ans;
    }while(ans=='Y' || ans=='y');      
}
void TBT::inorder()
{
    node *temp;
    temp = root;
    int flag =0;
    if(root ==NULL)
    {
        cout<<"\n\tTree is empty...!";
    }
    else
    {
        while(temp!= head)
        {
            if(temp->lbit==1 && flag==0)
            {
              temp = temp->left;
            }
            else
            {
                cout<<" "<<temp->data;
                if(temp->rbit==1)
                {
                    temp=temp->right;
                    flag = 0;
                }
                else
                {
                    temp= temp->right;
                    flag =1;
                }
            }
        }
    }
}
void TBT::preorder()
{
    node *temp;
    temp = root;
    int flag =0;
    if(root ==NULL)
    {
        cout<<"\n\tTree is empty...!";
    }
    else
    {
        while(temp!= head)
        {
            if(flag==0)
            {
                cout<<" "<<temp->data;
            }
            if(temp->lbit==1 && flag==0)
            {
                temp = temp->left;
            }
            else
            {
                if(temp->rbit==1)
                {
                    temp=temp->right;
                    flag = 0;
                }
                else
                {
                    temp= temp->right;
                    flag =1;
                }
            }
        }
    }
}
int main()
{
    TBT t;
    int choice;
    do
    {
        cout<<"\n\t1.Insert Element ";
        cout<<"\n\t2.Display Inorder ";
        cout<<"\n\t3.Display Preorder ";
        cout<<"\n\t4.Exit ";
        cout<<"\n\tEnter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:  
                t.create_TBT();
            break;
            case 2: 
                cout<<"\n\t1Inorder is: ";
                t.inorder();
            break;
            case 3:
                cout<<"\n\tPreorder is: ";
                t.preorder();
            break;
            case 4:
                cout<<"\n\tExit";
            break;
        }
    }while(choice!=4);
    return 0;
   
}

