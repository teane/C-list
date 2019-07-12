#include "cList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

PNODE cList_Create()
{
	PNODE pHeader = malloc(sizeof(struct Node));
	pHeader->pNext = NULL;
	pHeader->pPrev = NULL;
	pHeader->data = NULL;
	return pHeader;
}

void cList_Clear(PNODE pHeader)
{
	// NULL or list header
	if( pHeader == NULL || pHeader->pPrev == NULL)
	{
		return;
	}
	
	PNODE pNode = pHeader;
	PNODE pNext = NULL;
	
	while(pNode)
	{
		pNext = pNode->pNext;
		cList_Delete(pNode);
		pNode = pNext;
		
	}
}

PNODE cList_Delete(PNODE pNode)
{
	if( pNode == NULL )
	{
		return NULL;
	}
	
	PNODE pNodePrev = pNode->pPrev;
	PNODE pNodeNext = pNode->pNext;
	if(pNodePrev == NULL)
	{
		printf("Header Node can not delete\n");
		return pNodeNext;
	}
	pNodePrev->pNext = pNode->pNext;
	if(pNodeNext != NULL)
	{
		pNodeNext->pPrev = pNodePrev;
	}
	if(pNode->data)
	{
		//printf("cList_Delete  pNode->data = %s\n",(char *)(pNode->data));
		free(pNode->data);
		pNode->data = NULL;
	}
	free(pNode);
	pNode = NULL;
	return pNodeNext;
}


PNODE cList_Insert_Back(PNODE pNode,void* data,bool (*cmp)(void* , void*))
{
	if(pNode == NULL)
	{
		return NULL;
	}
	
	PNODE pNew = malloc(sizeof(struct Node));
	PNODE pNodeNext = pNode->pNext;
	
	pNew->pNext = pNodeNext;
	pNode->pNext = pNew;
	
	pNew->pPrev = pNode;
	pNew->data = data;
	if(cmp == NULL){
		printf("cList_Insert_Back cmp == null \n");
	}
	pNew->pCmp = cmp;
	
	if(pNodeNext != NULL)
	{
		pNodeNext->pPrev = pNew;
	}
	return pNew;
}

bool cList_IsExists(void* data,PNODE pList)
{
	if(pList == NULL || data == NULL)
	{
			return false;
	}
	
	PNODE pListNode = pList;
	
	while(pListNode){
		
		if(pListNode->data != NULL || pListNode->pCmp != NULL)
		{
			if(pListNode->pCmp(data,pListNode->data)){
				return true;
			}	
		}
		
		pListNode = pListNode->pNext;
	}
	return false;
}

bool cmpTest(void* data1,void* data2)
{
	if(data1 == NULL || data2 == NULL)
	{
		return false;
	}
	
	return strcmp((char*)data1,(char*)data2) == 0;
}

void test()
{
	PNODE pHeader = cList_Create();
	
	printf("XXXX begin insert, check meme XXXX \n");
	//sleep(20);
	for(int i=0;i<10;i++)
	{
		char* data = malloc(2048*500);
		memset(data,0,2048*500);
		sprintf(data,"%d",i);
		cList_Insert_Back(pHeader,data,cmpTest);
	}
	
	PNODE pNode = pHeader->pNext;
	while(pNode){
		if(pNode->data)
		{
			printf("printf data = %s\n",(char *)(pNode->data));
		}
		pNode = pNode->pNext;
	}
	printf("0 cList_IsExists = %d \n",cList_IsExists("0",pHeader));
	printf("1 cList_IsExists = %d \n",cList_IsExists("1",pHeader));
	printf("2 cList_IsExists = %d \n",cList_IsExists("2",pHeader));
	printf("9 cList_IsExists = %d \n",cList_IsExists("9",pHeader));
	printf("10 cList_IsExists = %d \n",cList_IsExists("10",pHeader));
	printf("100 cList_IsExists = %d \n",cList_IsExists("100",pHeader));
	
	printf("XXXX inserted ,check meme XXXX \n");
	//sleep(20);
	
	
	cList_Clear(pHeader->pNext);
	
	printf("XXXX cleared ,check meme XXXX \n");
	//sleep(50000);
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */
