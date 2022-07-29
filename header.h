#include<iostream>

using namespace std;

template<class T>
struct node
{
	T data;
	int iCnt;
	struct node *next;
	struct node *prev;
   
};

template<class T>
class generic_DoublyCircular
{

	private:
		struct node<T> *head;
		struct node<T> *tail;
		int iCnt;

	public:

		generic_DoublyCircular();
		void InsertFirstDC(T);
		void InsertLastDC(T);
		void InsertAtPosDC(T, int);
		void DeleteFirstDC();
		void DeleteLastDC();
		void DeleteAtPosDC(int);
		inline int CountDC();
		inline void DisplayDC();
		void Head_TailDC();
};

template<class T>
class generic_DoublyLinear
{
    private:
        struct node<T> *head;
        int Count;

    public:

        generic_DoublyLinear();
        void InsertFirstDL(T);
        void InsertLastDL(T);
        void DeleteFirstDL();
        void DeleteLastDL();
        void InsertAtPosDL(T,int);
        void DeleteAtPosDL(int);
        int CountNodeDL();
        void DisplayDL();
};

template<class T>
class generic_SinglyCLL
{
	private:			// characteristics
		struct node<T> *head;
		struct node<T> *tail;
		int iCnt1;

	public:			// Behaviours
		generic_SinglyCLL();
		void InsertFirstSC(T no);
		void InsertLastSC(T no);
		void InsertAtPosSC(T no,int pos);
		void DeleteFirstSC();
		void DeleteLastSC();
		void DeleteAtPosSC(int);
		void DisplaySC();	
		void HeadTailSC();
		int CountSC();
	
};

template<class T>
class SinglyLL
{
	private:
		struct node<T> *head;
		int cnt;

	public:
		SinglyLL();
		void InsertFirstSL(T);
		void InsertLastSL(T);
		void DeleteFirstSL();
		void DeleteLastSL();
		void InsertAtPosSL(T,int);
		void DeleteAtPosSL(int);
		void DisplaySL();
		int CountNodeSL();
};

template<class T>
class Queue
{
    public:
        struct node<T> *Head;
        int Count;

        Queue();
        void Enqueue(T);        // InsertLast
        void Dequeue();            // DeleteFirst
        void DisplayQ();
        int CountNodeQ();
};
 
template<class T>
class Stack
{
    public:
        struct node<T> *Head;
        int Count;

        Stack();
        void Push(T);        // InsertFirst
        void Pop();            // DeleteFirst
        void DisplayS();
        int CountNodeS();
};
