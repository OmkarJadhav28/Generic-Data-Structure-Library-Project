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

int main()
{
    SinglyLL<int> obj1;
    SinglyCL<float> obj2;
    DoublyLL<char> obj3;
    DoublyCL<double> obj4;

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
        cout << "5 : Terminate the application\n";
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
            exit(0);
            break;

        default:
            cout << "Please enter valid choice\n";
            break;
        }
    }
    return 0;
}
