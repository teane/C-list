#ifndef __CLIST_H__
#define __CLIST_H__

#include <stdbool.h>

typedef struct Node{ 
    void* data; 
    struct Node* pNext;
	struct Node* pPrev; 
	bool (*pCmp)(void*,void*);
} *PNODE;


//return header
PNODE cList_Create();

/* delete all nodes [pHeader,pTail],
 *  
 */
void cList_Clear(PNODE pHeader);

//delete pNode,return pNode->pNext
PNODE cList_Delete(PNODE pNode);

// insert back to pNode,return the insterted Node
PNODE cList_Insert_Back(PNODE pNode,void* data,bool (*cmp)(void* data1,void* data2));

// data is  exists in [PList,pTail],need set cmp fun
bool cList_IsExists(void* data,PNODE pList);

#endif // __CLIST_H__
