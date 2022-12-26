
/* 头文件 */
#include "tinyOS.h"

/* 任务结构 */
tTask tTask1;
tTask tTask2;
tTaskStack task1Env[1024];
tTaskStack task2Env[1024];

/* 任务初始化函数 */
void tTaskInit(tTask *task, void (*entry)(void *), void *param, tTaskStack *stack)
{
	task->stack = stack;
}

/* 任务功能函数实现 */
void Task1(void *param)
{
	for(;;)
	{
	
	}
	
}

void Task2(void *param)
{
	for(;;)
	{
	
	}
	
}

int main(void)
{
	tTaskInit(&tTask1, Task1, (void *)0x11111111, &task1Env[1024]);
	tTaskInit(&tTask2, Task2, (void *)0x22222222, &task2Env[1024]);
	
	for(;;)
	{
	
	}

	return 0;
}

