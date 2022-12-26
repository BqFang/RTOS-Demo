#include <stdio.h>

/* 宏定义 */
#define NVIC_INT_CTRL   0xE000ED04
#define NVIC_PENDSVSET  0x10000000
#define NVIC_SYSPRI2    0xE000ED22
#define NVIC_PENDSV_PRI 0x000000FF

#define MEM32(addr)     *(volatile unsigned long *)(addr)
#define MEM8(addr)      *(volatile unsigned char *)(addr)


/* 变量声明 */
int flag = 0;

/* 函数声明*/
static void Delay(int count);
static void TriggerPendSVC(void);


/* 栈定义 */
typedef struct _BlockType_t {
	unsigned long *StackPtr;
}BlockType_t;

static BlockType_t *blockPtr = NULL;

/* 缓冲区定义 */
static unsigned long stackBuffer[1024];
static BlockType_t block;

int main(void)
{
	block.StackPtr = &stackBuffer[1024];
	blockPtr = (BlockType_t *)&stackBuffer;

	for(;;)
	{
		flag = 1;
		Delay(100);
		flag = 0;
		Delay(100);
		
		TriggerPendSVC();
	}
}
	
/* 函数实现 */
static void Delay(int count)
{
	while(--count > 0);
}

static void TriggerPendSVC(void)
{
	MEM8(NVIC_SYSPRI2) = NVIC_PENDSV_PRI;
	MEM32(NVIC_INT_CTRL) = NVIC_PENDSVSET;
}

