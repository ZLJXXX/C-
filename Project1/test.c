#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main()
{
	int num = 0;
	scanf("%d", &num);
	int arr[4][4] = {
		1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15,
	};
	//遍历这个递增数组
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (num == arr[i][j])
			{
				printf("查找成功\n其位置:arr[%d][%d]\n",i,j);
				break;
			}
		}
	}
	system("pause");
	return 0;
}