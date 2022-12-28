#define NVIC_INT_CTRL   0xE000Ed04    // 中断控制及状态寄存器
#define NVIC_PENDSVSET  0x10000000    // 触发软件中断的值
#define NVIC_SYSPRI2    0xE000ED22    // 系统优先级寄存器
#define NVIC_PENDSV_PRI 0x000000FF    // 配置优先级

#define MEM32(addr)     *(volatile unsigned long *)(addr)
#define MEM8(addr)      *(volatile unsigned char *)(addr)



int flag = 0;


static void Delay(int count);
static void TriggerPendSVC(void);



typedef struct _BlockType_t {
	unsigned long *StackPtr;
}BlockType_t;

BlockType_t *blockPtr ;

static unsigned long stackBuffer[1024];
static BlockType_t block;

int main(void)
{
	blockPtr = (BlockType_t *)&stackBuffer;

	for(;;)
	{
		flag = 1;
		Delay(100);
		flag = 0;
		Delay(100);
		
		block.StackPtr = &stackBuffer[1024];
		TriggerPendSVC();
	}
}
	

static void Delay(int count)
{
	while(--count > 0);
}

static void TriggerPendSVC(void)
{
	MEM8(NVIC_SYSPRI2) = NVIC_PENDSV_PRI;
	MEM32(NVIC_INT_CTRL) = NVIC_PENDSVSET;
}

