#include "header.h"



///////////////////////////////////////////////////////////DOUBLY CIRCULAR /////////////////////////////////////////////////////////////
template<class T>
generic_DoublyCircular<T>:: generic_DoublyCircular()
{
	head = NULL;
	tail = NULL;
	iCnt = 0;
}

template<class T>
void generic_DoublyCircular<T>:: InsertFirstDC(T no)
{
	struct node<T> *newn = NULL;

	newn = new node<T>;

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if((head == NULL) && (tail == NULL))
	{
		head = newn;
		tail = newn;
	}
	else
	{
		newn->next = head;	
		head->prev = newn;
		head = newn;
	}

	tail->next = head;
	head->prev = tail;

	iCnt++;
}

template<class T>
void generic_DoublyCircular<T>:: InsertLastDC(T no)
{
	struct node<T> *newn = NULL;

	newn = new node<T>;
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if((head == NULL) && (tail == NULL))
	{
		head = newn;
		tail = newn;
	}
	else
	{
		tail->next = newn;
		newn->prev = tail;
		tail = newn; 	
	}
	tail->next = head;
	head->prev = tail;

	iCnt++;
}

template<class T>
void generic_DoublyCircular<T>::InsertAtPosDC(T no, int pos)
{
	int size = CountDC();

	if((pos < 0) || (pos > size+1))
	{
		cout<<"Invalid Position!!"<<endl;
		return;
	}
	
	if(pos == 1)
	{
		InsertFirstDC(no);
	}
	else if(pos == size+1)
	{
		InsertLastDC(no);
	}
	else
	{
		struct node<T> *newn = NULL;
	
		newn = new node<T>;

		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;

		struct node<T> *temp = head;
		for(int iCnt = 1; iCnt < pos-1; iCnt++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		temp->next->prev = newn;
		newn->prev = temp;
		temp->next = newn;

		iCnt++;

	}
}

template<class T>
void generic_DoublyCircular<T>::DeleteFirstDC()
{
	if(head == NULL && tail == NULL)
	{
		cout<<"Cannot Perform Delete Operation LL Empty!!"<<endl;
		return;
	}
	struct node<T> *temp = head;
	
	head = head->next;
	head->prev = tail;
	tail->next = head;
	delete temp;
	iCnt--;
}

template<class T>
void generic_DoublyCircular<T>::DeleteLastDC()
{
	if(head == NULL && tail == NULL)
	{
		cout<<"Cannot Perform Delete Operation LL Empty!!"<<endl;
		return;
	}
	
	struct node<T> *temp = tail;	
	tail = tail->prev;
	tail->next = head;
	head->prev = tail;

	delete temp;

	iCnt--;
}

template<class T>
void generic_DoublyCircular<T>::DeleteAtPosDC(int pos)
{

	int size = CountDC();

	if(head == NULL && tail == NULL)
	{
		cout<<"Cannot Perform Delete Operation LL Empty!!"<<endl;
		return;
	}

	if(pos<0 && pos>size)
	{
		cout<<"Invalid Position!!"<<endl;
		return;
	}
	if(pos == 1)
	{
		DeleteFirstDC();
	}
	else if(pos == size)
	{
		DeleteLastDC();
	}
	else
	{
		struct node<T> *temp = head;
	
		for(int iCnt = 1; iCnt< pos-1; iCnt++)
		{
			temp = temp->next;
		}

		struct node<T> *tempdelete = temp->next;	
		temp->next->next->prev = temp;
		temp->next = temp->next->next;
		
		delete tempdelete;
		iCnt--;
	}
	
} 

template<class T>
void generic_DoublyCircular<T>::DisplayDC()
{
	struct node<T> *temp = head;

	do
	{
		cout<<"<-|"<<temp->data<<"|->";
		temp = temp->next;
	}
	while(temp != head);
	cout<<endl;
}

template<class T>
int generic_DoublyCircular<T>::CountDC()
{
	return iCnt;
}

template<class T>
void generic_DoublyCircular<T>::Head_TailDC()
{
	cout<<"Head : "<<head->data<<endl;
	cout<<"Tail : "<<tail->data<<endl;
}

///////////////////////////////////////////////////////////DOUBLY LINEAR/////////////////////////////////////////////////////////////
template<class T>
generic_DoublyLinear<T>:: generic_DoublyLinear()
{
    head = NULL;
    Count = 0;
}

template<class T>
void generic_DoublyLinear<T>::InsertFirstDL(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == 0 && Count == 0)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    Count++;
}

template<class T>
void generic_DoublyLinear<T>::InsertLastDL(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == 0 && Count == 0)
    {
        head = newn;
    }
    else if(Count == 1 && head->next == NULL)
    {
        head->next = newn;
        newn->prev = head;
    }
    else
    {
        struct node<T> *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    Count++;
}

template<class T>
void generic_DoublyLinear<T>::DeleteFirstDL()
{
    if(head == 0 && Count == 0)
    {
        cout<<"Cannot Perform Delete Operation!!"<<endl;
        return;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = NULL;
    }
    Count--;
}

template<class T>
void generic_DoublyLinear<T>::DeleteLastDL()
{
    if(head == 0 && Count == 0)
    {
        cout<<"Cannot Perform Delete Operation!!"<<endl;
        return;
    }
    else if(Count == 1 && head->next == NULL)
    {
        delete head->next;
        head->next = NULL;
    }
    else
    {
        struct node<T> *temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next; 
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}

template<class T>
void generic_DoublyLinear<T>::InsertAtPosDL(T no, int pos)
{
    if(pos < 0 || pos > (Count+1))
    {
        cout<<"Invalid Position!!"<<endl;
        return;
    }
    if(pos == 1)
    {
        InsertFirstDL(no);
    }
    else if(pos == (Count+1))
    {
        InsertLastDL(no);
    }
    else
    {
        struct node<T> *newn = NULL;
        newn = new node<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        struct node<T> *temp = head;
        for(int i=1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        Count++;
    }
}

template<class T>
void generic_DoublyLinear<T>::DeleteAtPosDL(int pos)
{
     if(pos < 0 || pos > (Count))
    {
        cout<<"Invalid Position!!"<<endl;
        return;
    }
    if(pos == 1)
    {
        DeleteFirstDL();
    }
    else if(pos == (Count+1))
    {
        DeleteLastDL();
    }
    else
    {
        struct node<T> *temp = head;
        for(int i=1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        struct node<T> *tempDelete = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        delete tempDelete;
    }
    Count--;
}

template<class T>
int generic_DoublyLinear<T>::CountNodeDL()
{
    return Count;
}

template<class T>
void generic_DoublyLinear<T>::DisplayDL()
{
    cout<<"Element In The LL Are : "<<endl;
    struct node<T> *temp = head;
    cout<<"NULL";
    while(temp!= NULL)
    {
        cout<<"<-|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
///////////////////////////////////////////////////////////SINGLY CIRCULAR /////////////////////////////////////////////////
template<class T>
generic_SinglyCLL<T>:: generic_SinglyCLL()
{
	head = NULL;
	tail= NULL;
	iCnt1= 0;	
}

template<class T>
void generic_SinglyCLL<T>::InsertFirstSC(T no)
{

	iCnt1++;
	struct node<T> *newn = NULL;
	
	newn = new node<T>;

	if(newn == NULL)
	{
		return;
	}

	newn->data = no;
	newn->next = NULL;

	if((head == NULL) && (tail == NULL))	//if cll is empty
	{
		head = newn;
		tail = newn;
	} 
	else							//if cll contains atleast one node
	{
		newn->next = head;
		head = newn;
	}

	tail->next = head;	// this is most important and will not give error if written anywhere
}

template<class T>
void generic_SinglyCLL<T>:: InsertLastSC(T no)
{
	iCnt1++;
	struct node<T> *newn = NULL;
	struct node<T> *temp = NULL;
	
	newn = new node<T>;

	if(newn == NULL)
	{
		return;
	}

	newn->data = no;
	newn->next = NULL;

	if((head == NULL) && (tail == NULL))	//if cll is empty
	{
		head = newn;
		tail = newn;
	} 
	else							//if cll contains atleast one node
	{
		tail->next = newn;
		tail = newn;	
	}

	tail->next = head;
}

template<class T>
void generic_SinglyCLL<T>:: InsertAtPosSC(T no,int pos)
{
	int iSize = CountSC();
 
	if((pos < 0) || (pos > iSize+1))
	{
		cout<<"INVALID POSITION!!"<<endl;
		return;
	}

	struct node<T> *newn = NULL;
	newn = new node<T>;

	if(newn == NULL)
	{
		return;
	}

	newn->data = no;
	newn->next = NULL;

	if(pos == 1)
	{
		InsertFirstSC(no);
	}
	else if(pos == iSize+1)
	{
		InsertLastSC(no);
	}
	else
	{
		iCnt1++;
		int i = 0;
		struct node<T> *temp = head;

		for(i = 1; i < pos-1; i++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		temp->next = newn;
	}
	
 
}

template<class T>
void generic_SinglyCLL<T>:: DeleteFirstSC()
{
	if((head == NULL) && (tail == NULL))
	{
		return;	 
	}
	iCnt1--;

	head = head->next;
	delete tail->next;
	tail->next = head;
}

template<class T>
void generic_SinglyCLL<T>:: DeleteLastSC()
{
	if((head == NULL) && (tail == NULL))
	{
		return;
	}	
	iCnt1--;

	struct node<T> *temp = head;

	while(temp->next != tail)
	{
		temp = temp->next;
	}

	delete(temp->next);
	temp->next = head;
	tail = temp;
}

template<class T>
void generic_SinglyCLL<T>:: DeleteAtPosSC(int pos)
{
	int iSize = CountSC();
 
	if((pos < 0) || (pos > iSize))
	{
		cout<<"INVALID POSITION!!"<<endl;
		return;
	}

	if(pos == 1)
	{
		DeleteFirstSC();
	}
	else if(pos == iSize)
	{
		DeleteLastSC();
	}
	else
	{
		iCnt1--;

		int i = 0;
		struct node<T> *temp = head;

		for(i = 1; i < pos-1 ; i++)
		{
			temp = temp->next;
		} 

		struct node<T> *tempdelete = temp->next;
		temp->next = tempdelete->next;
		delete tempdelete;
	}
	
}

template<class T>
void generic_SinglyCLL<T>:: DisplaySC()
{
	struct node<T> *temp = head;
	
	do
	{
		cout<<"<-|"<<temp->data<<"|->";
		temp = temp->next;
	}
	while(temp != head);	

	cout<<endl;
}

template<class T>
int generic_SinglyCLL<T>:: CountSC()
{
	return iCnt1;
}

template<class T>
void generic_SinglyCLL<T>:: HeadTailSC()
{
	T Head, Tail;
	Head = head->data;
	Tail = tail->data;

	cout<<"HEAD : "<<Head<<endl;
	cout<<"TAIL : "<<Tail<<endl;
}
///////////////////////////////////////////////////////////SINGLY LINEAR /////////////////////////////////////////////////
template<class T>
SinglyLL<T>::SinglyLL()
{
	head = 0;
	cnt = 0;
}

template<class T>
void SinglyLL<T>::InsertFirstSL(T no)
{
	struct node<T> *newn = NULL;	 //creating newn pointer
	newn = new node<T>;

	newn->data = no;
	newn->next = NULL;

	if(head == NULL)
	{
		head = newn;
	}
	else
	{
		newn->next = head;
		head = newn;
	}
	cnt++;

}

template<class T>
void SinglyLL<T>::InsertLastSL(T no)
{
	struct node<T> *newn = NULL;
	newn = new node<T>;

	newn->data = no;
	newn->next = NULL;

	if(head == NULL)
	{
		head = newn;
	}
	else
	{
		struct node<T> *temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newn;
	}
	cnt++;

}

template<class T>
void SinglyLL<T>::DeleteFirstSL()
{
	if(head == NULL)
	{
		cout<<"LL is Empty Cannot Perform Operation!!!"<<endl;
		return;
	}
	else
	{
		struct node<T> *temp = head;
		head = head->next;
		delete temp;
	}

	cnt--;
}

template<class T>
void SinglyLL<T>::DeleteLastSL()
{
	if(head == NULL)
	{
		cout<<"LL is Empty Cannot Perform Operation!!!"<<endl;
		return;
	}
	else if(head->next == NULL)
	{
		delete head;
		head = NULL;

		cnt--;	
	}
	else
	{
		struct node<T> *temp = head;
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}

		delete temp->next;
		temp->next = NULL;
	}
	cnt--;
}

template<class T>
void SinglyLL<T>::InsertAtPosSL(T no, int pos)
{
	if(pos < 0 || pos > (cnt+1))
	{
		cout<<"Inavalid Position!!"<<endl;
		return;
	}

	if(pos == 1)
	{
		InsertFirstSL(no);
	}
	else if(pos == (cnt+1))
	{
		InsertLastSL(no);
	}
	else
	{
		struct node<T> *newn = NULL;
	
		newn = new node<T>;

		newn->data = no;
		newn->next = NULL;

		struct node<T> *temp = head;
		for(int i= 1; i < pos-1; i++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;	
		temp->next = newn; 
	
		cnt++;
	}

}

template<class T>
void SinglyLL<T>::DeleteAtPosSL(int pos)
{
	if(pos < 0 || pos > cnt)
	{
		cout<<"Inavalid Position!!"<<endl;
		return;
	}

	if(pos == 1)
	{
		DeleteFirstSL();
	}
	else if(pos == cnt)
	{
		DeleteLastSL();
	}
	else
	{
		struct node<T> *tempdelete = NULL;
		
		struct node<T> *temp = head;
		for(int i= 1; i < pos-1; i++)
		{
			temp = temp->next;
		}

		tempdelete = temp->next;
		temp->next = temp->next->next;	
		delete tempdelete; 
	
		cnt--;
	}

}

template<class T>
void SinglyLL<T>::DisplaySL()
{
	cout<<"Element In Linked List : "<<endl;

	struct node<T> *temp = head;
	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}
template<class T>
int SinglyLL<T>::CountNodeSL()
{
	return cnt;
}

////////////////////////////////////////////////////////////////QUEUE/////////////////////////////////////////////////////////


template<class T>
Queue<T>::Queue()
{
    Head = NULL;
    Count = 0;
}



template<class T>
void Queue<T>::Enqueue(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
            struct node<T> *temp = Head;
            while(temp->next != NULL)
            {
                temp = temp -> next;
            }

            temp->next = newn;
    }
    Count++;
}



template <class T>
void Queue<T>::Dequeue()    // deletefirst 
 {  

   T no;

   if ( Count == 0) // Head == NULL
   {  
  
     cout<<"queue is empty"<<endl;
     return;

   }

  
   if ( Count == 1) 
   {  
         no = Head->data;
         delete Head;
         Head = NULL;
    

     }
  else 

   {

        no=Head->data;
        struct node <T> *temp = Head;
        Head = Head->next;
        delete temp;
 



   }
 Count--;
 cout<<"removed element is "<<no<<endl;
 

 }



template<class T>
void Queue<T>::DisplayQ()
{
    cout<<"Elements from queue are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


template<class T>
int Queue<T>::CountNodeQ()
{
    return Count;
}

////////////////////////////////////////////////////////STACK//////////////////////////////////////////////////////////////////

template<class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void Stack<T>::Push(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = Head;
    Head = newn;
    Count++;
}

template <class T>
void Stack<T>::Pop()       // Deletefirst
{
    T no;   // int no;

    if(Count == 0)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }

    no = Head -> data;
    struct node<T> *temp = Head;
    Head = Head->next;
    delete temp;

    Count--;
    cout<<"Removed element is : "<<no<<endl;
}

template<class T>
void Stack<T>::DisplayS()
{
    cout<<"Elements from Stack are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
int Stack<T>::CountNodeS()
{
    return Count;
}