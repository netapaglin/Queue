#include <stdio.h>/* for prints*/
#include<stdlib.h>/* size_t malloc*/
#include "genQ.h"

struct Queue
{
	void** m_que;
	size_t m_size;
	size_t m_head; /* Index of head in m_que. */
	size_t m_tail; /* Index of tail in m_que. */
	size_t m_nItems;
};


Queue* QueueCreate(size_t _size)
{
	Queue* que;
	void**  temp;
	if(_size == 0)
	 {
		 return NULL;
	 }
	que = (Queue*)malloc( sizeof(Queue));
	 if(que == NULL)
	 {
		 return NULL;
	 }
	 temp = (void**)malloc( _size * sizeof(void*));
	  if(temp == NULL)
	  {
	  		free(que);
	    	return NULL;
	  }
	 que ->m_que = temp;
	 que-> m_size = _size ;
     que-> m_head = 0;
     que-> m_tail = 0;
     que->m_nItems = 0;
	 return que;
}

void QueueDestroy(Queue** _queue, DestroyItem _itemDestroy)
{
	size_t i;
	if (_queue != NULL && *_queue != NULL)
	{
	if(_itemDestroy != NULL)
	{
		for(i=0 ; i <(*_queue) -> m_nItems ; ++i)
		{
			_itemDestroy((*_queue) ->m_que[i]);			
		}
	}
	free((*_queue) -> m_que);
	free(*_queue);
	*_queue = NULL;
	}
}


QueueResult QueueInsert(Queue* _queue,void* _item)
{
	if(_queue == NULL )
	{
		return QUEUE_UNINITIALIZED_ERROR;
	}
	if(_item == NULL )
	{
		return QUEUE_DATA_UNINITIALIZED_ERROR;
	}
	 if (_queue -> m_nItems == _queue -> m_size )
 	{
 		return QUEUE_OVERFLOW_ERROR;
 	}
	_queue ->m_que[_queue-> m_tail] = _item;
	_queue -> m_tail = (_queue-> m_tail +1)%_queue-> m_size;
	++_queue -> m_nItems;
	return QUEUE_SUCCESS;
}

QueueResult QueueRemove(Queue* _queue,void** _item)
{
	if(_queue == NULL )
	{
		return QUEUE_UNINITIALIZED_ERROR;
	}
	if(_item == NULL )
	{
		return QUEUE_DATA_UNINITIALIZED_ERROR;
	}
	 if (_queue -> m_nItems == 0 )
 	{
 		return QUEUE_UNDERFLOW_ERROR;
 	}
 	*_item = _queue ->m_que[_queue-> m_head] ;
	_queue -> m_head = (_queue-> m_head +1)%_queue-> m_size;
	--_queue -> m_nItems;
	return QUEUE_SUCCESS;
}

size_t QueueIsEmpty(Queue* _queue)
{
	if (_queue != NULL)
	{
		if (_queue -> m_nItems == 0)
		{
			return 1;
		}
		return 0;
	}
}

size_t QueueForEach(Queue* _queue, ActionFunction _action, void* _context)
{
	size_t i , j;
	if(_queue == NULL || _action == NULL)
	{
		return;
	}
	for( i = _queue -> m_head, j= 0  ; j <_queue -> m_nItems ; i = ((i+1) % _queue -> m_size), ++j)
	{
		if(_action(_queue -> m_que[i] , _context) == 0)
		{
			break;	
		}
	}
	return i;
}


size_t GetQueueSize(Queue *_queue)
{
	return _queue -> m_size;
}

size_t GetQueueHead(Queue *_queue)
{
	return _queue -> m_head;
}

size_t GetQueueNumItems(Queue *_queue)
{
	return _queue -> m_nItems;
}

size_t GetQueueTail(Queue *_queue)
{
	return _queue -> m_tail;
}






