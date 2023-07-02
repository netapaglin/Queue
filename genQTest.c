#include <stdio.h>/* for prints*/
#include "genQ.h"

static void TestCreateNormal();
static void TestcreateSizeZero();
static void TestcreateParams();

static void TestDoubleDestroy();
static void TestIDestroyqueNull();
static void TestIDestroyNormal();

static void TestInsertNormal();
static void TestInsertOverFlow();
static void TestInsertQueNull();
static void TestInsertItemNull();

static void TestRemoveNormal();
static void TestRemoveNotFound();
static void TestRemoveQueNull();
static void TestRemoveItemNull();

static void TestIfEmpty();
static void TestIfEmpty2();

static void TestForEach();

static void PlayTests();

int main (void)
{
	TestCreateNormal();
	TestcreateSizeZero();
	TestcreateParams();
	
	TestDoubleDestroy();
	TestIDestroyqueNull();
	TestIDestroyNormal();
	
	TestInsertNormal();
	TestInsertOverFlow();
	TestInsertQueNull();
	TestInsertItemNull();
	
	TestRemoveNormal();
	TestRemoveNotFound();
	TestRemoveQueNull();
	TestRemoveItemNull();
	
	TestIfEmpty();
	TestIfEmpty2();
	
	TestForEach();
	
	PlayTests();
	
	return 1;
}


/************************************************************************/

static int PrintQue(void* _element, void* _context )
{
	printf("%d" , *(int*)_element);
	return 1;
}

static void PlayTests()
{
 	Queue *  que;
 	int *b;
 	int i,arr[] ={1,2,3,4,5,6,7,8,9,10,11,12};
	que = QueueCreate(4);
	for( i =0 ; i < 3; ++i)
	{
		QueueInsert(que, &arr[i]);
	}
	printf("tail-%ld  ", GetQueueTail(que));
	printf("head-%ld  ", GetQueueHead(que));
	printf("\n" );
	QueueForEach(que, PrintQue, NULL);
	printf("\n" );
	
	QueueInsert(que, &arr[3]);
	printf("tail-%ld  ", GetQueueTail(que));
	printf("head-%ld  ", GetQueueHead(que));
	printf("\n" );
	QueueForEach(que, PrintQue, NULL);
	printf("\n" );
	
	QueueRemove(que, (void*)&b);
	QueueRemove(que, (void*)&b);
	QueueInsert(que, &arr[4]);
	QueueInsert(que, &arr[5]);
	QueueRemove(que, (void*)&b);
	QueueRemove(que, (void*)&b);
	QueueRemove(que, (void*)&b);
	QueueInsert(que, &arr[5]);
	QueueInsert(que, &arr[5]);			
		QueueInsert(que, &arr[5]);	
				QueueInsert(que, &arr[5]);	
	printf("tail-%ld  ", GetQueueTail(que));
	printf("head-%ld  ", GetQueueHead(que));
	printf("\n" );
	QueueForEach(que, PrintQue, NULL);
	printf("\n" );
	printf("\n******************************\n" );
	

	 QueueDestroy(&que , NULL);
}



static void TestForEach()
{
 	Queue *  que;
 	int i,arr[] ={9,3,5,6,8};
	que = QueueCreate(6);
	for( i =0 ; i < 5; ++i)
	{
		QueueInsert(que, &arr[i]);
	}
	QueueForEach(que, PrintQue, NULL);
	printf("\n" );
	 QueueDestroy(&que , NULL);
}

static void TestIfEmpty2()
{
 	Queue *  que;
 	int i,arr[] ={9,3,5,6,8};
	que = QueueCreate(6);
	for( i =0 ; i < 5; ++i)
	{
		QueueInsert(que, &arr[i]);
	}
	 if (QueueIsEmpty(que) != 1)
	 {
	 	printf("test empty2- PASS\n");

	 }else
	 {
		printf("test empty2- FAIL\n"); 
	 }
	 QueueDestroy(&que , NULL);
}

static void TestIfEmpty()
{
 	Queue *  que;
	 que = QueueCreate(10);
	 if (QueueIsEmpty(que) == 1)
	 {
	 	printf("test empty- PASS\n");

	 }else
	 {
		printf("test empty- FAIL\n"); 
	 }
	 QueueDestroy(&que , NULL);
}

static void TestRemoveItemNull()
{
	int i;
	int a;
 	void * b =&a;
 	Queue *  que;
 	int arr[] ={9,3,5,6,8};
	que = QueueCreate(6);
	for( i =0 ; i < 5; ++i)
	{
		QueueInsert(que, &arr[i]);
	}
	QueueRemove(que, (void*)&b);
	QueueRemove(que, (void*)&b);
	QueueRemove(que, (void*)&b);
	 if (QueueRemove(que, NULL) == QUEUE_DATA_UNINITIALIZED_ERROR )
	 {
	 	printf("test remove item null - PASS\n");

	 }else
	 {
		printf("test remove item null - FAIL\n"); 
	 }
	 QueueDestroy(&que , NULL);
}


static void TestRemoveQueNull()
{
	int i;
	int a;
 	void * b =&a;
 	Queue *  que;
 	int arr[] ={9,3,5,6,8};
	que = QueueCreate(6);
	for( i =0 ; i < 5; ++i)
	{
		QueueInsert(que, &arr[i]);
	}
	QueueRemove(que, (void*)&b);
	QueueRemove(que, (void*)&b);
	QueueRemove(que, (void*)&b);
	 if (QueueRemove(NULL, (void*)&b) == QUEUE_UNINITIALIZED_ERROR )
	 {
	 	printf("test remove que null - PASS\n");

	 }else
	 {
		printf("test remove que null - FAIL\n"); 
	 }
	 QueueDestroy(&que , NULL);
}


static void TestRemoveNotFound()
{
	int i;
	int a;
 	void * b =&a;
 	Queue *  que;
 	int arr[] ={9,3,5,6,8};
	que = QueueCreate(6);
	for( i =0 ; i < 5; ++i)
	{
		QueueInsert(que, &arr[i]);
	}
	QueueRemove(que, (void*)&b);
	QueueRemove(que, (void*)&b);
	QueueRemove(que, (void*)&b);
	QueueRemove(que, (void*)&b);
	QueueRemove(que, (void*)&b);
	 if (QueueRemove(que, (void*)&b) == QUEUE_UNDERFLOW_ERROR )
	 {
	 	printf("test remove under flow- PASS\n");

	 }else
	 {
		printf("test remove under flow- FAIL\n"); 
	 }
	 QueueDestroy(&que , NULL);
}



static void TestRemoveNormal()
{
	int i;
	int a;
 	void * b =&a;
 	Queue *  que;
 	int arr[] ={9,3,5,6,8};
	que = QueueCreate(6);
	for( i =0 ; i < 5; ++i)
	{
		QueueInsert(que, &arr[i]);
	}
	QueueRemove(que, (void*)&b);
	 if (GetQueueNumItems(que) &&
	 	*(int*)b== 9
	 )
	 {
	 	printf("test remove normal - PASS\n");

	 }else
	 {
		printf("test remove normal - FAIL\n"); 
	 }
	 QueueDestroy(&que , NULL);
}


static void TestInsertItemNull()
{
	int i;
 	Queue *  que;
 	int arr[] ={9,3,5,6,8};
 	int x = 7;
	que = QueueCreate(5);
	for( i =0 ; i < 5; ++i)
	{
		QueueInsert(que, &arr[i]);
	}
	 if (QueueInsert(que,NULL) == QUEUE_DATA_UNINITIALIZED_ERROR )
	 {
	 	printf("test insert item null - PASS\n");

	 }else
	 {
		printf("test insert item null   - FAIL\n"); 
	 }
	 QueueDestroy(&que , NULL);
}


static void TestInsertQueNull()
{
	int i;
 	Queue *  que;
 	int arr[] ={9,3,5,6,8};
 	int x = 7;
	que = QueueCreate(5);
	for( i =0 ; i < 5; ++i)
	{
		QueueInsert(que, &arr[i]);
	}
	 if (QueueInsert(NULL, &x) == QUEUE_UNINITIALIZED_ERROR )
	 {
	 	printf("test insert que null - PASS\n");

	 }else
	 {
		printf("test insert que null   - FAIL\n"); 
	 }
	 QueueDestroy(&que , NULL);
}



static void TestInsertOverFlow()
{
	int i;
 	Queue *  que;
 	int arr[] ={9,3,5,6,8};
 	int x = 7;
	que = QueueCreate(5);
	for( i =0 ; i < 5; ++i)
	{
		QueueInsert(que, &arr[i]);
	}
	 if (QueueInsert(que, &x) == QUEUE_OVERFLOW_ERROR )
	 {
	 	printf("test insert overflow - PASS\n");

	 }else
	 {
		printf("test insert overflow - FAIL\n"); 
	 }
	 QueueDestroy(&que , NULL);
}

static void TestInsertNormal()
{
	int i;
 	Queue *  que;
 	int arr[] ={9,3,5,6,8};
	que = QueueCreate(6);
	for( i =0 ; i < 4; ++i)
	{
		QueueInsert(que, &arr[i]);
	}
	 if (  QueueInsert(que, &arr[4]) == QUEUE_SUCCESS && GetQueueNumItems(que) == 5 )
	 {
	 	printf("test insert normal - PASS\n");

	 }else
	 {
		printf("test insert normal - FAIL\n"); 
	 }
	 QueueDestroy(&que , NULL);
}


static void TestIDestroyNormal()
{
	int i;
 	Queue *  que;
 	int arr[] ={9,3,5,6,8};
	que = QueueCreate(6);
	for( i =0 ; i < 5; ++i)
	{
		QueueInsert(que, &arr[i]);
	}
	QueueDestroy(&que, NULL);
	 if (que == NULL )
	 {
	 	printf("test destroy normal - PASS\n");

	 }else
	 {
		printf("test destroy normalL - FAIL\n"); 
	 }
}


static void TestIDestroyqueNull()
{
	int i;
 	Queue *  que;
 	int arr[] ={9,3,5,6,8};
	que = QueueCreate(6);
	for( i =0 ; i < 5; ++i)
	{
		QueueInsert(que, &arr[i]);
	}
	QueueDestroy(NULL, NULL);
	 if (que )
	 {
	 	printf("test destroy que NULL - PASS\n");

	 }else
	 {
		printf("test destroy que NULL - FAIL\n"); 
	 }
	 QueueDestroy(&que , NULL);
}

static void TestDoubleDestroy()
{
 	Queue *  que;
	que = QueueCreate(5);
	QueueDestroy(&que , NULL);
	QueueDestroy(&que , NULL);
	printf("test double destroy- PASS\n");
	
}
static void TestcreateParams()
{
 	Queue *  que;
	que = QueueCreate(5);
	 if (GetQueueSize(que)  == 5 &&
	 	GetQueueHead(que)  == 0 &&
	 	GetQueueNumItems(que)  == 0 &&
	 	GetQueueTail(que)  == 0
	 )
	 {
	 	printf("test create params - PASS\n");

	 }else
	 {
		printf("test create params - FAIL\n"); 
	 }
	 QueueDestroy(&que , NULL);
}


static void TestcreateSizeZero()
{
 	Queue *  que;
	que = QueueCreate(0);
	 if (que == NULL )
	 {
	 	printf("test create size zero - PASS\n");

	 }else
	 {
		printf("test create size zero- FAIL\n"); 
	 }
	 QueueDestroy(&que , NULL);
}


static void TestCreateNormal()
{
 Queue *  que;
	 que = QueueCreate(10);
	 if (que != NULL )
	 {
	 	printf("test create normall - PASS\n");

	 }else
	 {
		printf("test create normall - FAIL\n"); 
	 }
	 QueueDestroy(&que , NULL);
}

