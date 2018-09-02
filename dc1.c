#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#define NUM 4
int main()
{
	int i, j, n, count, cubed, sum = 0;
	bool result = true; // 用于存放验证结果
	char answer;
	int**array;
	printf("请输入一个整数：");
	scanf_s("%d", &count);
	getchar();
	array = (int**)malloc((count+1) * sizeof(int));
	for (i = 0; i < (count+1); i++)
	{
		array[i] = (int*)malloc(NUM * sizeof(int)); 
	}
	// 变长数组无法再定义是初始化，只能手动了...
	for (n = 3; n < count; n++)
	{
		// 初始化第一列，因为后边用于验证 
		array[n][0] = 0;
	}

	for (n = 3; n <=count; n++)
	{
		cubed = n * n * n;
		for (i = 1; i < cubed; i += 2)
		{
			for (j = i; j < cubed; j += 2)
			{
				sum += j;
				if (sum == cubed)
				{
					array[n][0] = cubed;
					array[n][1] = i;
					array[n][2] = i + 2;
					array[n][3] = j;

					goto FINDIT;
				}

				if (sum > cubed)
				{
					sum = 0;
					break;
				}
			}
		}

	FINDIT:
		; // 空语句
	}

	// 检查
	for (n = 3; n <= count; n++)
	{
		if (array[n][0] == 0)
		{
			result = false;
			break;
		}
	}

	if (result)
	{
		printf("经验证，3 ~ %d 之间所有的整数均符合尼科彻斯定理！\n\n", count);
		printf("是否打印所有式子(y/n)：");
		answer=getchar();
		
	}
	else
	{
		printf("验证失败：整数 %d 无法找到对应的连续奇数！\n",n);
	}

	if (answer == 'y')
	{
		// 打印
		for (n = 3; n <= count; n++)
		{
			if (array[n][3] - array[n][1] > 4)
			{
				printf("%d^3 == %d == %d + %d +... + %d\n", n, array[n][0], array[n][1], array[n][2], array[n][3]);
			}
			else
			{
				printf("%d^3 == %d == %d + %d + %d\n", n, array[n][0], array[n][1], array[n][2], array[n][3]);
			}
		}
	}
	for (i = 0; i <= count; i++)
	{
		free(array[i]);
	}
	free(array);
	return 0;
}