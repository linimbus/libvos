/********************************************
*
*  ���ϵͳ���ڴ����ģ��
*
*  �����ڴ����룬�ͷţ�����
*
********************************************/

#include "d_mem.h"
#include "d_base.h"

#include <stdlib.h>


VOID * NS_MemAlloc(UINT32 ulAllocMemSize)//�ڴ����
{
	return malloc(ulAllocMemSize);
}

UINT32 NS_MemFree(VOID * pFreeOne)//�ڴ��ͷ�
{
    (VOID)free(pFreeOne);
	return OK;
}

