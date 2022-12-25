#include <stdio.h>

static volatile int flag;
void Delay(int count);

int main(void)
{
	for(;;)
	{
		flag = 0;
		Delay(100);
		flag = 1;
		Delay(100);
	}
}
	
void Delay(int count)
{
	while(--count > 0);
}

