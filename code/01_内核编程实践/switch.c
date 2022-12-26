__asm void PendSV_Handler(void)
{
    /* IMPORT 类似于C语言extern */
    IMPORT blockPtr;

    /* 在blockPtr地址中获取前四位放置到R0寄存器中 */
    LDR R0, =blockPtr
    LDR R0, [R0]
    LDR R0, [R0]

    /* 从R0地址连续读取内容存储到R4~R11寄存器中 */
    STMDB R0!, {R4-R11}

    /* 将R0的值存储到R1地址中 */
    LDR R1, =blockPtr
    LDR R1, [R1]
    STR R0, [R1]

    /* 测试代码，随便进行计算，无实际意义 */
    ADD R4, R4, #1
    ADD R5, R5, #1

    LDMIA R0!, {R4-R11}

    BX LR
}

