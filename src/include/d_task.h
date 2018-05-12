/********************************************
*
*
*  �������ģ��
*
*
********************************************/

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


#include <pthread.h>
#include "d_base.h"


#ifndef _TASK_H_
#define _TASK_H_

typedef VOID * TASK_HANDLE;

#define NS_MAX_NAME_LEN 32

#define NS_ERR_TASK_SAME_NAME    NS_ERROR_OFFSET(NS_TASK_MODULE,1)
#define NS_ERR_TASK_NO_FIND      NS_ERROR_OFFSET(NS_TASK_MODULE,2)


///"TASK"
#define NS_TASK_HANDLE_MAGIC      0x5441534B

#define NS_TASK_STATUS_BLOCK      0x1
#define NS_TASK_STATUS_RUN        0x2
#define NS_TASK_STATUS_SLEEP      0x3


/*

�̵߳ĵ��������ֲ��ԣ�SCHED_OTHER��SCHED_RR��SCHED_FIFO��Policy
����ָ��ʹ�����ֲ��ԡ�����򵥵�˵��һ�������ֵ��Ȳ��ԡ�

SCHED_OTHER

����Ĭ�ϵ��̷߳�ʱ���Ȳ��ԣ����е��̵߳����ȼ�����0��
�̵߳ĵ�����ͨ����ʱ����ɵġ��򵥵�˵�����ϵͳʹ�����ֵ��Ȳ��ԣ�
�����޷������̵߳����ȼ�����ע�⣬���ֵ��Ȳ���Ҳ����ռʽ�ģ�
�������ȼ����߳�׼�����е�ʱ�򣬵�ǰ�߳̽�����ռ������ȴ����С�
���ֵ��Ȳ��Խ��������߳��ڿ������̶߳����еľ�����ͬ���ȼ����̵߳����д���

SCHED_FIFO

����һ��ʵʱ���Ƚ��ȳ����ò��ԣ���ֻ���ڳ����û������С����ֵ��ò���
������ʹ�������ȼ�����0���̡߳�����ζ�ţ�ʹ��SCHED_FIFO�Ŀ������߳̽�
һֱ��ռʹ��SCHED_OTHER�������߳�J������SCHED_FIFO��һ���Ƿ�ʱ�ļ�
���Ȳ��ԣ���һ���̱߳�ɿ�����״̬��������׷�ӵ���Ӧ���ȼ����е�β��
((POSIX 1003.1)�������и����ȼ����߳���ֹ��������ʱ�����������С�����
��ͬ���ȼ�����̣߳����ռ򵥵��Ƚ������еĹ������С����ǿ���һ�ֺܻ���
����������������ͬ���ȼ����̵߳ȴ�ִ�У�Ȼ������ִ�е��߳�����ֹ����
������������ô�����߳����޷�ִ�еģ����ǵ�ǰ�̵߳�����pthread_yield֮
��ĺ�����������ʹ��SCHED_FIFO��ʱ��ҪС�Ĵ�����ͬ�����̵߳Ķ�����

SCHED_RR

����SCHED_FIFO���Ȳ��Ե�һЩȱ�㣬SCHED_RR��SCHED_FIFO������һЩ��ǿ
���ܡ���ʵ���Ͽ���������SCHED_FIFO���ò��ԡ���ʹ���������ʱ��������
��ǰ���̵����У�������ʱ����ڵ����������ʱ���ʱ�򣬵�ǰ�߳̽�����
������������ͬ���ȼ����е�����������ĺô�������������ͬ������߳�
���ڡ���˽���߳���ִ�С�

*/

typedef enum tagTaskModule {
    /* ����ʵʱ���Ȳ��� */
    NS_TASK_SCH_FIFO   = SCHED_FIFO,
    NS_TASK_SCH_RR     = SCHED_RR,
    /* Ĭ��һ����Ȳ��� */
    NS_TASK_SCH_NORMAL = SCHED_OTHER,
}NS_TASK_SCHEDULE;



typedef enum tagTaskPriority {
    /* ʵʱ���ȵ����ȼ� */
    NS_TASK_PRIORITY_9  = 99,
    NS_TASK_PRIORITY_8  = 80,
    NS_TASK_PRIORITY_7  = 70,
    NS_TASK_PRIORITY_6  = 60,
    NS_TASK_PRIORITY_5  = 50,
    NS_TASK_PRIORITY_4  = 40,
    NS_TASK_PRIORITY_3  = 30,
    NS_TASK_PRIORITY_2  = 20,
    NS_TASK_PRIORITY_1  = 10,
    NS_TASK_PRIORITY_0  =  0,
}NS_TASK_PRIORITY;


typedef VOID (*TASK_FUNC)(UINT32 ulParam,VOID * pParam);



TASK_HANDLE NS_TaskCurrentGet();

UINT32 NS_TaskBlock(TASK_HANDLE TaskHandle , UINT32 ulMsec);

UINT32 NS_TaskWakeup(TASK_HANDLE TaskHandle);

CHAR * NS_TaskNameGet(TASK_HANDLE TaskHandle);

UINT32 NS_TaskHandleValid(TASK_HANDLE TaskHandle);

UINT32 NS_TaskIDGet(CHAR * pcTaskName,TASK_HANDLE * pTaskHandle);

UINT32 NS_TaskDelete(TASK_HANDLE TaskHandle);

UINT32 NS_TaskJoin(TASK_HANDLE TaskHandle);

UINT32 NS_TaskCreate(TASK_HANDLE *  pTaskHandle,
					  CHAR        *  pcTaskName,
					  TASK_FUNC      pTaskFunc,
					  UINT32         ulParam,
					  VOID        *  pParam);

UINT32 NS_TaskCreateEx(TASK_HANDLE     * pTaskHandle,
    			        CHAR            * pcTaskName,
                        NS_TASK_SCHEDULE eTaskModule,
                        NS_TASK_PRIORITY eTaskPrior,
    				    TASK_FUNC         pTaskFunc,
    				    UINT32            ulParam,
    				    VOID            * pParam);

VOID NS_TaskDelay(UINT32 ulMillisecond);


#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

