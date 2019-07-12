# C-list
A simple list use C language

how to use

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
