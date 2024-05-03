
#include<iostream>
using namespace std;
class graph
{
int a[10][10], vcnt, Rcnt;
int v[20];
public:
graph()
{
Rcnt = 0;
vcnt = 0;
}
void read_adjacency();
void display_adjacency();
void BFS();
void DFS();
int search(int);
};
void graph::read_adjacency()
{
cout << "Enter vertex count :";
cin >> vcnt;
for (int i = 1; i <= vcnt; i++)
{
for (int j = 1; j <= vcnt; j++)
{
cout << "Enter edge " << i << " to " << j << ":";
cin >> a[i][j];
}
}
}
void graph::display_adjacency()
{
for (int i = 1; i <= vcnt; i++)
{
for (int j = 1; j <= vcnt; j++)
{
cout << a[i][j] << " ";
}
cout << "\n";
}
}
class Queue
{
int a[20], f, r;
public:
Queue()
{
f = 0;
r = 0;
}
void insert(int key);
int Delete();
};
void Queue::insert(int key)
{
if (r != 20)
{
a[r++] = key;
}
else
{
cout << "Queue is full ";
}
}
int Queue::Delete()
{
if (f != r)
{
return (a[f++]);
}
else
{
cout << "Queue is Empty ";
return -1; // Return a sentinel value to indicate empty queue
}
}
class stack
{
int a[20], top;
public:
stack()
{
top = -1;
}
void push(int key);
int pop();
};
void stack::push(int key)
{
if (top != 19)
{
a[++top] = key;
}
else
{
cout << "Stack is full ";
}
}
int stack::pop()
{
if (top != -1)
{
return(a[top--]);
}
else
{
cout << "Stack is Empty";
return -1; // Return a sentinel value to indicate empty stack
}
}
int graph::search(int key)
{
for (int i = 0; i < Rcnt; i++)
{
if (v[i] == key)
{
return(1);
}
}
return 0; // Return 0 if key is not found
}
void graph::BFS()
{
int sv, curr;
cout << "Enter starting vertex ";
cin >> sv;
v[Rcnt++] = sv;
Queue q;
q.insert(sv);
while ((curr = q.Delete()) != -1) // Keep dequeueing until the queue is empty
{
for (int c = 1; c <= vcnt; c++)
{
if (a[curr][c] == 1)
{
if (search(c) == 0)
{
q.insert(c);
v[Rcnt++] = c;
}
}
}
}
cout << "BFS=";
for (int i = 0; i < Rcnt; i++)
{
cout << " " << v[i];
}
}
void graph::DFS()
{
int sv, curr;
cout << "Enter starting vertex ";
cin >> sv;
v[Rcnt++] = sv;
stack s;
s.push(sv);
while ((curr = s.pop()) != -1) // Keep popping until the stack is empty
{
if (search(curr) == 0) // Only process if the vertex is not visited
{
for (int c = 1; c <= vcnt; c++)
{
if (a[curr][c] == 1)
{
s.push(c);
v[Rcnt++] = c;
}
}
}
}
cout << "\nDFS=";
for (int i = 0; i < Rcnt; i++)
{
cout << " " << v[i];
}
}
int main()
{
int choice;
graph obj;
obj.read_adjacency();
obj.display_adjacency();
do
{
cout << "\nMenu\n1.BFS\n2.DFS\n Enter choice ";
cin >> choice;
switch (choice)
{
case 1:
obj.BFS();
break;
case 2:
obj.DFS();
break;
default:
cout << "Invalid choice!";
break;
}
} while (choice != 3);
return 0;
}
