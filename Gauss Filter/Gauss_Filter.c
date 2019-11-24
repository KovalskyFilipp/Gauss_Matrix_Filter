#include <stdio.h>
#include "stdlib.h"

int main(void)
{
	int a = 0;
	int width = 10;
	int kernelSize = 3;
	int height = 10;
	int result = 0;
	//float kernel[5][5] = { { 0.000789, 0.006581, 0.013347, 0.006581, 0.000789 },
	//					{ 0.006581, 0.054901, 0.111345, 0.054901, 0.006581 },
	//					{ 0.013347, 0.111345, 0.225821, 0.111345, 0.013347},
	//					{  0.006581, 0.054901, 0.111345, 0.054901, 0.006581 },
	//					{  0.000789, 0.006581, 0.013347, 0.006581, 0.000789 } };
	float kernel[3][3] = {
					{  0.054901, 0.111345, 0.054901},
					{  0.111345, 0.225821, 0.111345},
					{  0.054901, 0.111345, 0.054901}};
	int* inPtr;
	inPtr = (int*)malloc(width * height * sizeof(int));
	inPtr = (int*)malloc(width * height * sizeof(int));
	int* luma = inPtr;
	srand(time(0));
	for (int i = 0; i < height; i++)  // ���� �� �������
	{
		for (int j = 0; j < width; j++)  // ���� �� ��������
		{
			*(inPtr + i * width + j) = rand() % 255;
		}
	}

	for (int i = 0; i < height; i++)  // ���� �� �������
	{
		for (int j = 0; j < width; j++)  // ���� �� ��������
		{
			printf("%5d ", *(inPtr + i * width + j));
		}
		printf("\n");
	}
	printf("---------------------------------------\n");
	for (int i = 0; i < width - kernelSize; i++)  // ���� �� �������
	{
		for (int j = 0; j < height - kernelSize; j++)  // ���� �� ��������
		{
			for (int m = 0; m < kernelSize; m++)  // ���� �� �������
			{
				for (int n = 0; n < kernelSize; n++)  // ���� �� ��������
				{
					result = result + *(inPtr + (i+n) * width + j+m) * kernel[m][n];
				}

			}
			*(inPtr + (i+kernelSize/2) * width + j+kernelSize/2) = result;
			a = result;
			result = 0;
		}
	
	}
	for (int i = 0; i < width; i++)  // ���� �� �������
	{
		for (int j = 0; j < height; j++)  // ���� �� ��������
		{
			printf("%5d ", *(inPtr + i * width + j));
		}
		printf("\n");
	}


	printf("%5d ", 5/2);
	puts("Hello, World!");
	free(inPtr);
	return 0;
}