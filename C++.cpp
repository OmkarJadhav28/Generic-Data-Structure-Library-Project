#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for Singly Linear and Singly Circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for Doubly Linear and Doubly Circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Singly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////


template <class T>
class SinglyLL
{
public:
    struct NodeS<T> *first;
    int iCount;

    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyLL <T>::SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    cout << "Elements of Singly Linear Linked list are : " << "\n";

    NodeS<T> *temp = first;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    }
    cout << "NULL" << "\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{
    int count = Count();

    if ((iPos < 1) || (iPos > count + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == count + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *newn = new NodeS<T>;

        newn->data = no;
        newn->next = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int count = Count();

    if ((iPos < 1) || (iPos > count))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == count)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp1 = first;
        NodeS<T> *temp2 = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Singly Circular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
public:
    struct NodeS<T> *first;
    struct NodeS<T> *last;
    int iCount;

    SinglyCL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }

    cout << "Elements of Singly Circular Linked list are : " << "\n";

    NodeS<T> *temp = first;

    do
    {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    } while (temp != last->next);
    cout << "\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }

    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }

    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while (temp->next != last)
        {
            temp = temp->next;
        }

        delete last;
        last = temp;
        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
    int count = Count();

    if ((iPos < 1) || (iPos > count + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == count + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *newn = new NodeS<T>;

        newn->data = no;
        newn->next = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int count = Count();

    if ((iPos < 1) || (iPos > count))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == count)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp1 = first;
        NodeS<T> *temp2 = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Doubly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
public:
    struct NodeD<T> *first;
    struct NodeD<T> *last;
    int iCount;

    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    cout << "Elements of Doubly Linear Linked list are : " << "\n";

    NodeD<T> *temp = first;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |<=> ";
        temp = temp->next;
    }
    cout << "NULL" << "\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->prev = last;
        last->next = newn;
        last = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeD<T> *temp = first;

        first = first->next;
        first->prev = NULL;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeD<T> *temp = last;

        last = last->prev;
        last->next = NULL;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{
    int count = Count();

    if ((iPos < 1) || (iPos > count + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == count + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *temp = first;
        NodeD<T> *newn = new NodeD<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int count = Count();

    if ((iPos < 1) || (iPos > count))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == count)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp1 = first;
        NodeD<T> *temp2 = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;
        temp2->prev = temp1;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Doubly Circular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
public:
    struct NodeD<T> *first;
    struct NodeD<T> *last;
    int iCount;

    DoublyCL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }

    cout << "Elements of Doubly Circular Linked list are : " << "\n";

    NodeD<T> *temp = first;

    do
    {
        cout << "| " << temp->data << " |<=> ";
        temp = temp->next;
    } while (temp != last->next);
    cout << "\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->prev = last;
        last->next = newn;
        last = newn;
    }

    last->next = first;
    first->prev = last;
    iCount++;
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeD<T> *temp = first;

        first = first->next;
        first->prev = last;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeD<T> *temp = last;

        last = last->prev;
        last->next = first;
        first->prev = last;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos)
{
    int count = Count();

    if ((iPos < 1) || (iPos > count + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == count + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *temp = first;
        NodeD<T> *newn = new NodeD<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    int count = Count();

    if ((iPos < 1) || (iPos > count))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == count)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp1 = first;
        NodeD<T> *temp2 = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;
        temp2->prev = temp1;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Stack Implementation

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Stack
{
public:
    NodeS<T> *top;
    int iCount;

    Stack();

    void Push(T);
    void Pop();
    T Peek();
    bool IsEmpty();
    int Count();
};

template <class T>
Stack<T>::Stack()
{
    top = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>::Push(T value)
{
    NodeS<T> *newNode = new NodeS<T>;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    iCount++;
}

template <class T>
void Stack<T>::Pop()
{
    if (!IsEmpty())
    {
        NodeS<T> *temp = top;
        top = top->next;
        delete temp;
        iCount--;
    }
}

template <class T>
T Stack<T>::Peek()
{
    if (!IsEmpty())
    {
        return top->data;
    }
    else
    {
        cerr << "Stack is empty." << endl;
        exit(1);
    }
}

template <class T>
bool Stack<T>::IsEmpty()
{
    return (top == NULL);
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Queue Implementation

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queue
{
public:
    NodeS<T> *front;
    NodeS<T> *rear;
    int iCount;

    Queue();

    void Enqueue(T);
    void Dequeue();
    T Front();
    bool IsEmpty();
    int Count();
};

template <class T>
Queue<T>::Queue()
{
    front = NULL;
    rear = NULL;
    iCount = 0;
}

template <class T>
void Queue<T>::Enqueue(T value)
{
    NodeS<T> *newNode = new NodeS<T>;
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    iCount++;
}

template <class T>
void Queue<T>::Dequeue()
{
    if (!IsEmpty())
    {
        NodeS<T> *temp = front;
        front = front->next;
        delete temp;

        if (front == NULL)
        {
            rear = NULL;
        }

        iCount--;
    }
}

template <class T>
T Queue<T>::Front()
{
    if (!IsEmpty())
    {
        return front->data;
    }
    else
    {
        cerr << "Queue is empty." << endl;
        exit(1);
    }
}

template <class T>
bool Queue<T>::IsEmpty()
{
    return (front == NULL);
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Binary Search Tree (BST) Implementation

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct BSTNode
{
    T data;
    BSTNode *left;
    BSTNode *right;
};

template <class T>
class BinarySearchTree
{
public:
    BSTNode<T> *root;

    BinarySearchTree();

    void Insert(T);
    bool Search(T);
    void Delete(T);
    void InorderTraversal(BSTNode<T>*);

private:
    BSTNode<T>* DeleteNode(BSTNode<T>*, T);
    BSTNode<T>* FindMin(BSTNode<T>*);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = NULL;
}

template <class T>
void BinarySearchTree<T>::Insert(T value)
{
    BSTNode<T> *newNode = new BSTNode<T>;
    newNode->data = value;
    newNode->left = newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;
        return;
    }

    BSTNode<T> *current = root;
    BSTNode<T> *parent = NULL;

    while (true)
    {
        parent = current;
        if (value < current->data)
        {
            current = current->left;
            if (current == NULL)
            {
                parent->left = newNode;
                return;
            }
        }
        else
        {
            current = current->right;
            if (current == NULL)
            {
                parent->right = newNode;
                return;
            }
        }
    }
}

template <class T>
bool BinarySearchTree<T>::Search(T key)
{
    BSTNode<T> *current = root;

    while (current)
    {
        if (current->data == key)
        {
            return true;
        }
        else if (key < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    return false;
}

template <class T>
void BinarySearchTree<T>::InorderTraversal(BSTNode<T> *node)
{
    if (node)
    {
        InorderTraversal(node->left);
        cout << node->data << " ";
        InorderTraversal(node->right);
    }
}

template <class T>
void BinarySearchTree<T>::Delete(T key) {
    root = DeleteNode(root, key);
}

template <class T>
BSTNode<T>* BinarySearchTree<T>::DeleteNode(BSTNode<T>* node, T key) 
{
    if (node == NULL) 
    {
        return node;
    }

    if (key < node->data) 
    {
        node->left = DeleteNode(node->left, key);
    } 
    else if (key > node->data) 
    {
        node->right = DeleteNode(node->right, key);
    } else {
        // Node with only one child or no child
        if (node->left == NULL) {
            BSTNode<T>* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == NULL) {
            BSTNode<T>* temp = node->left;
            delete node;
            return temp;
        }

        // Node with two children, get the in-order successor (smallest in the right subtree)
        BSTNode<T>* temp = FindMin(node->right);
        node->data = temp->data;
        node->right = DeleteNode(node->right, temp->data);
    }
    return node;
}

template <class T>
BSTNode<T>* BinarySearchTree<T>::FindMin(BSTNode<T>* node) 
{
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}


int main()
{
    SinglyLL<int> obj1;
    SinglyCL<float> obj2;
    DoublyLL<char> obj3;
    DoublyCL<double> obj4;

    Stack<int> stack;
    Queue<string> queue;
    BinarySearchTree<int> bst;

    int iChoice = 0;
    int iValue = 0;
    int iPosition = 0;

    cout << "Linked List Application\n";

    while (1)
    {
        cout << "------------------------------------------------------\n";
        cout << "Please enter your choice : \n\n";

        cout << "1 : Singly Linear Linked List\n";
        cout << "2 : Singly Circular Linked List\n";
        cout << "3 : Doubly Linear Linked List\n";
        cout << "4 : Doubly Circular Linked List\n";
        cout << "5 : Stack\n";
        cout << "6 : Queue\n";
        cout << "7 : Binary Search Tree\n";
        cout << "8 : Terminate the application\n";
        cout << "------------------------------------------------------\n";

        cin >> iChoice;

        switch (iChoice)
        {
        case 1:
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "Please enter your choice for Singly Linear Linked List: \n\n";

                cout << "1 : Insert node at first position\n";
                cout << "2 : Insert node at last position\n";
                cout << "3 : Insert node at the given position\n";
                cout << "4 : Delete node from first position\n";
                cout << "5 : Delete node from last position\n";
                cout << "6 : Delete node from the given position\n";
                cout << "7 : Display the elements of Linked List\n";
                cout << "8 : Count number of nodes from Linked List\n";
                cout << "9 : Return to main menu\n";
                cout << "------------------------------------------------------\n";

                cin >> iChoice;

                switch (iChoice)
                {
                case 1:
                    cout << "Enter the value that you want to insert : \n";
                    cin >> iValue;
                    obj1.InsertFirst(iValue);
                    break;

                case 2:
                    cout << "Enter the value that you want to insert : \n";
                    cin >> iValue;
                    obj1.InsertLast(iValue);
                    break;

                case 3:
                    cout << "Enter the value that you want to insert : \n";
                    cin >> iValue;

                    cout << "Enter the position : \n";
                    cin >> iPosition;

                    obj1.InsertAtPos(iValue, iPosition);
                    break;

                case 4:
                    obj1.DeleteFirst();
                    break;

                case 5:
                    obj1.DeleteLast();
                    break;

                case 6:
                    cout << "Enter the position : \n";
                    cin >> iPosition;
                    obj1.DeleteAtPos(iPosition);
                    break;

                case 7:
                    obj1.Display();
                    break;

                case 8:
                    cout << "Number of nodes in Singly Linear Linked List are : " << obj1.Count() << "\n";
                    break;

                case 9:
                    break;

                default:
                    cout << "Please enter valid choice\n";
                    break;
                }
                if (iChoice == 9)
                {
                    break;
                }
            }
            break;

        case 2:
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "Please enter your choice for Singly Circular Linked List: \n\n";

                cout << "1 : Insert node at first position\n";
                cout << "2 : Insert node at last position\n";
                cout << "3 : Insert node at the given position\n";
                cout << "4 : Delete node from first position\n";
                cout << "5 : Delete node from last position\n";
                cout << "6 : Delete node from the given position\n";
                cout << "7 : Display the elements of Linked List\n";
                cout << "8 : Count number of nodes from Linked List\n";
                cout << "9 : Return to main menu\n";
                cout << "------------------------------------------------------\n";

                cin >> iChoice;

                switch (iChoice)
                {
                case 1:
                    cout << "Enter the value that you want to insert : \n";
                    cin >> iValue;
                    obj2.InsertFirst(iValue);
                    break;

                case 2:
                    cout << "Enter the value that you want to insert : \n";
                    cin >> iValue;
                    obj2.InsertLast(iValue);
                    break;

                case 3:
                    cout << "Enter the value that you want to insert : \n";
                    cin >> iValue;

                    cout << "Enter the position : \n";
                    cin >> iPosition;

                    obj2.InsertAtPos(iValue, iPosition);
                    break;

                case 4:
                    obj2.DeleteFirst();
                    break;

                case 5:
                    obj2.DeleteLast();
                    break;

                case 6:
                    cout << "Enter the position : \n";
                    cin >> iPosition;
                    obj2.DeleteAtPos(iPosition);
                    break;

                case 7:
                    obj2.Display();
                    break;

                case 8:
                    cout << "Number of nodes in Singly Circular Linked List are : " << obj2.Count() << "\n";
                    break;

                case 9:
                    break;

                default:
                    cout << "Please enter valid choice\n";
                    break;
                }
                if (iChoice == 9)
                {
                    break;
                }
            }
            break;

        case 3:
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "Please enter your choice for Doubly Linear Linked List: \n\n";

                cout << "1 : Insert node at first position\n";
                cout << "2 : Insert node at last position\n";
                cout << "3 : Insert node at the given position\n";
                cout << "4 : Delete node from first position\n";
                cout << "5 : Delete node from last position\n";
                cout << "6 : Delete node from the given position\n";
                cout << "7 : Display the elements of Linked List\n";
                cout << "8 : Count number of nodes from Linked List\n";
                cout << "9 : Return to main menu\n";
                cout << "------------------------------------------------------\n";

                cin >> iChoice;

                switch (iChoice)
                {
                case 1:
                    cout << "Enter the value that you want to insert : \n";
                    cin >> iValue;
                    obj3.InsertFirst(iValue);
                    break;

                case 2:
                    cout << "Enter the value that you want to insert : \n";
                    cin >> iValue;
                    obj3.InsertLast(iValue);
                    break;

                case 3:
                    cout << "Enter the value that you want to insert : \n";
                    cin >> iValue;

                    cout << "Enter the position : \n";
                    cin >> iPosition;

                    obj3.InsertAtPos(iValue, iPosition);
                    break;

                case 4:
                    obj3.DeleteFirst();
                    break;

                case 5:
                    obj3.DeleteLast();
                    break;

                case 6:
                    cout << "Enter the position : \n";
                    cin >> iPosition;
                    obj3.DeleteAtPos(iPosition);
                    break;

                case 7:
                    obj3.Display();
                    break;

                case 8:
                    cout << "Number of nodes in Doubly Linear Linked List are : " << obj3.Count() << "\n";
                    break;

                case 9:
                    break;

                default:
                    cout << "Please enter valid choice\n";
                    break;
                }
                if (iChoice == 9)
                {
                    break;
                }
            }
            break;

        case 4:
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "Please enter your choice for Doubly Circular Linked List: \n\n";

                cout << "1 : Insert node at first position\n";
                cout << "2 : Insert node at last position\n";
                cout << "3 : Insert node at the given position\n";
                cout << "4 : Delete node from first position\n";
                cout << "5 : Delete node from last position\n";
                cout << "6 : Delete node from the given position\n";
                cout << "7 : Display the elements of Linked List\n";
                cout << "8 : Count number of nodes from Linked List\n";
                cout << "9 : Return to main menu\n";
                cout << "------------------------------------------------------\n";

                cin >> iChoice;

                switch (iChoice)
                {
                case 1:
                    cout << "Enter the value that you want to insert : \n";
                    cin >> iValue;
                    obj4.InsertFirst(iValue);
                    break;

                case 2:
                    cout << "Enter the value that you want to insert : \n";
                    cin >> iValue;
                    obj4.InsertLast(iValue);
                    break;

                case 3:
                    cout << "Enter the value that you want to insert : \n";
                    cin >> iValue;

                    cout << "Enter the position : \n";
                    cin >> iPosition;

                    obj4.InsertAtPos(iValue, iPosition);
                    break;

                case 4:
                    obj4.DeleteFirst();
                    break;

                case 5:
                    obj4.DeleteLast();
                    break;

                case 6:
                    cout << "Enter the position : \n";
                    cin >> iPosition;
                    obj4.DeleteAtPos(iPosition);
                    break;

                case 7:
                    obj4.Display();
                    break;

                case 8:
                    cout << "Number of nodes in Doubly Circular Linked List are : " << obj4.Count() << "\n";
                    break;

                case 9:
                    break;

                default:
                    cout << "Please enter valid choice\n";
                    break;
                }
                if (iChoice == 9)
                {
                    break;
                }
            }
            break;

        case 5:
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "Please enter your choice for Stack: \n\n";

                cout << "1 : Push element onto the stack\n";
                cout << "2 : Pop element from the stack\n";
                cout << "3 : Peek at the top element of the stack\n";
                cout << "4 : Check if the stack is empty\n";
                cout << "5 : Count elements in the stack\n";
                cout << "6 : Return to main menu\n";
                cout << "------------------------------------------------------\n";

                cin >> iChoice;

                switch (iChoice)
                {
                case 1:
                    cout << "Enter the value that you want to push onto the stack: \n";
                    cin >> iValue;
                    stack.Push(iValue);
                    break;

                case 2:
                    stack.Pop();
                    break;

                case 3:
                    if (!stack.IsEmpty()) {
                        cout << "Top element of the stack: " << stack.Peek() << endl;
                    } else {
                        cout << "Stack is empty." << endl;
                    }
                    break;

                case 4:
                    cout << "Stack is " << (stack.IsEmpty() ? "empty" : "not empty") << endl;
                    break;

                case 5:
                    cout << "Number of elements in the stack: " << stack.Count() << endl;
                    break;

                case 6:
                    break;

                default:
                    cout << "Please enter a valid choice\n";
                    break;
                }
                if (iChoice == 6)
                {
                    break;
                }
            }
            break;

        case 6:
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "Please enter your choice for Queue: \n\n";

                cout << "1 : Enqueue element into the queue\n";
                cout << "2 : Dequeue element from the queue\n";
                cout << "3 : Front element of the queue\n";
                cout << "4 : Check if the queue is empty\n";
                cout << "5 : Count elements in the queue\n";
                cout << "6 : Return to main menu\n";
                cout << "------------------------------------------------------\n";

                cin >> iChoice;

                switch (iChoice)
                {
                case 1:
                    cout << "Enter the value that you want to enqueue into the queue: \n";
                    cin >> iValue;
                    queue.Enqueue(to_string(iValue));
                    break;

                case 2:
                    if (!queue.IsEmpty()) {
                        queue.Dequeue();
                    } else {
                        cout << "Queue is empty." << endl;
                    }
                    break;

                case 3:
                    if (!queue.IsEmpty()) {
                        cout << "Front element of the queue: " << queue.Front() << endl;
                    } else {
                        cout << "Queue is empty." << endl;
                    }
                    break;

                case 4:
                    cout << "Queue is " << (queue.IsEmpty() ? "empty" : "not empty") << endl;
                    break;

                case 5:
                    cout << "Number of elements in the queue: " << queue.Count() << endl;
                    break;

                case 6:
                    break;

                default:
                    cout << "Please enter a valid choice\n";
                    break;
                }
                if (iChoice == 6)
                {
                    break;
                }
            }
            break;

        case 7:
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "Please enter your choice for Binary Search Tree (BST): \n\n";

                cout << "1 : Insert a node into the BST\n";
                cout << "2 : Delete a node from the BST\n";
                cout << "3 : Search for a value in the BST\n";
                cout << "4 : Inorder traversal of the BST\n";
                cout << "5 : Return to main menu\n";
                cout << "------------------------------------------------------\n";

                cin >> iChoice;

                switch (iChoice)
                {
                case 1:
                    cout << "Enter the value that you want to insert into the BST: \n";
                    cin >> iValue;
                    bst.Insert(iValue);
                    break;

                case 2:
                    cout << "Enter the value that you want to delete from the BST: \n";
                    cin >> iValue;
                    bst.Delete(iValue);
                    break;

                case 3:
                    cout << "Enter the value that you want to search for in the BST: \n";
                    cin >> iValue;
                    if (bst.Search(iValue)) 
                    {
                        cout << iValue << " is found in the BST." << endl;
                    } 
                    else 
                    {
                        cout << iValue << " is not found in the BST." << endl;
                    }
                    break;

                case 4:
                    cout << "Inorder traversal of the BST: ";
                    bst.InorderTraversal(bst.root);
                    cout << endl;
                    break;

                case 5:
                    break;

                default:
                    cout << "Please enter a valid choice\n";
                    break;
                }
                if (iChoice == 5)
                {
                    break;
                }
            }
            break;

        case 8:
            exit(0);
            break;

        default:
            cout << "Please enter valid choice\n";
            break;
        }
    }
    return 0;
}
