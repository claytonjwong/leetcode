#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "QueueBase.h"
#include "Exceptions.h"

template <typename T> class Queue : public QueueBase 
{  
public:    

	Queue ( unsigned int size );
	Queue ( const Queue & other );
	~Queue();

	void  Push ( const T & e );    

	T  Pop ();  

	Queue & operator = ( const Queue<T> & other );

	template<typename T2>
	Queue & operator = ( const Queue<T2> & other );

private:   
	template <typename T2> friend class Queue;

	void	Grow();
	void	Swap( Queue<T> & other );
	void	CopyData( T * const dest, const T * src, int srcStartIdx, int srcEndIdx );

	T * m_Array; 

};

// include cpp file here since we want template definition to be visible at place of instantiation
// as we are not using the export keyword.
#include "Queue.cpp"

/*
template<typename T>
Queue<T>::Queue(unsigned int capacity)
:QueueBase(capacity), m_Array( new T[m_Capacity] )
{
}

template<typename T>
Queue<T>::~Queue()
{
    delete [] m_Array;
}

// Copy constructor
template<typename T>
Queue<T>::Queue( const Queue<T> & other )
:QueueBase( other ), m_Array( new T[m_Capacity] )
{
    for ( int ii = 0; ii < m_Capacity; ++ ii )
    {
        m_Array[ ii ] = other.m_Array[ ii ];
    }
}

template<typename T>
Queue<T> & Queue<T>::operator = ( const Queue<T> & other )
{
    if ( &other != this )
    {
        Queue<T> temp( other );        // create a copy of other in temp.
        Swap( temp );                // swap temp with this.
        // Now, temp will get destructed here, taking its memory away, which really was this's memory to start with
    }
    
    return *this;
}

template<typename T>
template<typename T2>
Queue<T> & Queue<T>::operator = ( const Queue<T2> & other )
{
    // no need to guard against self assignment since other is not even the same type as this.
    int newCapacity = other.GetCapacity();
    T * buffer = new T[ newCapacity ];
    
    for ( int ii = 0; ii < newCapacity; ++ ii )
    {
        buffer[ ii ] = other.m_Array[ ii ];
    }
    
    // If we are here, then everything is ok so far.
    delete [] m_Array;
    
    m_Array = buffer;
    m_Head = other.m_Head;
    m_Tail = other.m_Tail;
    
    return *this;
}

template<typename T>
void Queue<T>::Swap( Queue<T> & other )
{
    QueueBase::Swap( other );
    std::swap( m_Array, other.m_Array );
}

template<typename T>
void Queue<T>::Push( const T & e )
{
    if ( m_Tail == QueueBase::kEmptyQueueValue )
    {
        m_Tail = m_Head = 0;
    }
    else
    {
        if ( IsFull() )
        {
            Grow();
        }
        
        m_Tail = (m_Tail + 1) % m_Capacity;  // either tail is incremented by 1, or if tail has reached end, then tail will go to begining
    }
    
    m_Array[ m_Tail ] = e;
}

template<typename T>
T Queue<T>::Pop ()
{
    T returnValue = T();        // assign default value of T
    
    if ( ! IsEmpty() )
    {
        returnValue = m_Array[ m_Head ];
        if ( m_Head ==  m_Tail )
        {
            m_Head = m_Tail = QueueBase::kEmptyQueueValue;
        }
        else
        {
            m_Head = (m_Head + 1) % m_Capacity;
        }
    }
    else
    {
        throw QueueEmpty();
    }
    
    return returnValue;
}

template<typename T>
void Queue<T>::Grow()
{
    // placing grow factor here. If this needs to be configurable, then we cannot put it here.
    const double kGrowFactor = 1.5;
    
    // 1. Allocate new memory.  Grow internal storage by a factor kGrowFactor
    int newCapacity = (int) ( m_Capacity * kGrowFactor );            // TODO: Guard against int overflow
    T * newArray = new T [ newCapacity ];
    
    
    // 2. Now that we have allocated the new memory, we will copy the elements over.
    int numElements = Size();        // store this for use later below
    
    if ( m_Tail > m_Head )            // then copy from m_Head to m_Tail, both inclusive
    {
        CopyData( newArray, m_Array, m_Head, m_Tail );
    }
    else                            // copy from head to end of old array(m_Array), and 0 to tail (inclusive)
    {
        CopyData( newArray, m_Array, m_Head, m_Capacity-1 );
        CopyData( newArray + (m_Capacity-m_Head), m_Array, 0, m_Tail );
    }
    
    m_Capacity = newCapacity;
    m_Head = 0;                    // head is now 0
    m_Tail = numElements - 1;    // tail is the index of the last element in the new array
    
    
    // 3. Release old memory and point to new memory
    delete [] m_Array;
    m_Array = newArray;
}

// Assumption: Input parameters are valid... memory is properly and sufficienctly allocated
// srcEndIdx is inclusive
template<typename T>
void Queue<T>::CopyData( T * const dest, const T * src, int srcStartIdx, int srcEndIdx )
{
    int destIdx = 0;
    while ( srcStartIdx <= srcEndIdx )                // srcEndIdx is inclusive
    {
        dest[ destIdx ++ ] = src[ srcStartIdx ++ ];
    }
}

*/
#endif
