#include <stdio.h>
#include "stdlib.h"
#define KERNEL_SIZE 5

int main(void)
{
	int a = 0;
	int width = 10;
	int i = 0;
	int j = 0;
	int m = 0;
	int n = 0 ;
	int height = 10;
	int result = 0;
	float kernel_matrix[KERNEL_SIZE][KERNEL_SIZE] = { { 0.000789, 0.006581, 0.013347, 0.006581, 0.000789 },
						{ 0.006581, 0.054901, 0.111345, 0.054901, 0.006581 },
						{ 0.013347, 0.111345, 0.225821, 0.111345, 0.013347},
						{  0.006581, 0.054901, 0.111345, 0.054901, 0.006581 },
						{  0.000789, 0.006581, 0.013347, 0.006581, 0.000789 } };
	//float kernel_matrix[][3] = {
	//				{  0.054901, 0.111345, 0.054901},
	//				{  0.111345, 0.225821, 0.111345},
	//				{  0.054901, 0.111345, 0.054901}};
	int* inPtr;
	int* new_luma;
	inPtr = (int*)malloc(width * height * sizeof(int));
	inPtr = (int*)malloc(width * height * sizeof(int));
	new_luma = (int*)malloc(width * height * sizeof(int));
	int* luma = inPtr;
	//srand(time(0));
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

	for (i = 0; i < height - (KERNEL_SIZE >> 1); i++)
	{
		for (j = 0; j < width - (KERNEL_SIZE >> 1); j++)
		{
			for (m = 0; m < KERNEL_SIZE; m++)
			{
				for (n = 0; n < KERNEL_SIZE; n++)
				{
					result = result + *(luma + (i + n) * width + j + m) * kernel_matrix[m][n];

				}

			}
			*(new_luma + (i + (KERNEL_SIZE >> 1)) * width + j + (KERNEL_SIZE >> 1)) = result;
			result = 0;
		}

	}

	for (i = KERNEL_SIZE >> 1; i < height - (KERNEL_SIZE >> 1); i++)
	{
		for (j = KERNEL_SIZE >> 1; j < width - (KERNEL_SIZE >> 1); j++)
		{
			*(luma + (i  * width + j)) = *(new_luma + (i * width + j));
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
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	for (int i = KERNEL_SIZE >> 1; i < height - (KERNEL_SIZE >> 1); i++)  // ���� �� �������
	{
		for (int j = KERNEL_SIZE >> 1; j < width - (KERNEL_SIZE >> 1); j++)  // ���� �� ��������
		{
			printf("%5d ", *(new_luma + i * width + j));
		}
		printf("\n");
	}


	printf("%5d ", 5/2);
	puts("Hello, World!");
	free(inPtr);
	free(new_luma);
	return 0;
}