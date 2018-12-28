#ifndef QUEUE_BASE_H
#define QUEUE_BASE_H

#include <algorithm>

class QueueBase 
{ 
public:    
	QueueBase( unsigned int capacity );   
	QueueBase( const QueueBase & other );
	
	int		Size() const;   
	bool    IsEmpty() const; 
	bool    IsFull() const; 
	int		GetCapacity() const;

protected:
	void	Swap( QueueBase & other );   
	
	static const int kEmptyQueueValue = -1;

	int m_Capacity;   
	int m_Head; 
	int m_Tail;
};

inline QueueBase::QueueBase( unsigned int capacity )
	:m_Capacity(capacity), m_Head(kEmptyQueueValue), m_Tail(kEmptyQueueValue)				// when queue is empty, values of head and tail are kEmptyQueueValue.
{}

inline QueueBase::QueueBase( const QueueBase & other )
	:m_Capacity(other.m_Capacity), m_Head(other.m_Head), m_Tail(other.m_Tail)
{
}

inline int QueueBase::Size() const
{
	int size = 0;
	if ( m_Head >= 0 )
	{
		size = m_Tail >= m_Head ?  (m_Tail - m_Head + 1) :  (m_Capacity - (m_Head - m_Tail - 1));
	}

	return size;
}

inline bool QueueBase::IsEmpty() const
{
	return m_Head == kEmptyQueueValue;
}

inline bool QueueBase::IsFull() const
{
	return ( (m_Head == 0) && (m_Tail == (m_Capacity-1)) )		// head is first element, tail is last element in array
		   || ( (m_Head - m_Tail) == 1 );						// tail is right behind head ( circular queue )
}

inline int QueueBase::GetCapacity() const
{
	return m_Capacity;
}

inline void	QueueBase::Swap( QueueBase & other )
{
	std::swap( m_Capacity, other.m_Capacity );
	std::swap( m_Head, other.m_Head );
	std::swap( m_Tail, other.m_Tail );
}

#endif