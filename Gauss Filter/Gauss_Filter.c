#include <stdio.h>
#include "stdlib.h"
#define KERNEL_SIZE 5

int main(void)
{
	int a = 0;
	int width = 10;
	//int kernel_matrixSize = 5;
	int height = 10;
	int result = 0;
	int i = 0;
	int j = 0;
	int m = 0;
	int n = 0;
	//float kernel_matrix[5][5] = { { 0.000789, 0.006581, 0.013347, 0.006581, 0.000789 },
	//					{ 0.006581, 0.054901, 0.111345, 0.054901, 0.006581 },
	//					{ 0.013347, 0.111345, 0.225821, 0.111345, 0.013347},
	//					{  0.006581, 0.054901, 0.111345, 0.054901, 0.006581 },
	//					{  0.000789, 0.006581, 0.013347, 0.006581, 0.000789 } };
	//float kernel_matrix[3][3] = {
	//				{  0.054901, 0.111345, 0.054901},
	//				{  0.111345, 0.225821, 0.111345},
	//				{  0.054901, 0.111345, 0.054901}};\
	
	float kernel_matrix[KERNEL_SIZE] = { 0.028087, 0.23431, 0.475207, 0.23431, 0.028087 };

	int* inPtr;
	inPtr = (int*)malloc(width * height * sizeof(int));
	//inPtr = (int*)malloc(width * height * sizeof(int));
	int* new_luma;
	new_luma = (int*)malloc(width * height * sizeof(int));
	int* buf_luma;
	buf_luma = (int*)malloc(width * height * sizeof(int));
	memset(new_luma, 0, width * height);
	memset(buf_luma, 0, width * height);
	int* luma = inPtr;
	srand(time(0));
	for (int i = 0; i < height; i++)  // цикл по строкам
	{
		for (int j = 0; j < width; j++)  // цикл по столбцам
		{
			*(inPtr + i * width + j) = rand() % 255;
		}
	}

	for (int i = 0; i < height; i++)  // цикл по строкам
	{
		for (int j = 0; j < width; j++)  // цикл по столбцам
		{
			printf("%5d ", *(inPtr + i * width + j));
		}
		printf("\n");
	}
	printf("---------------------------------------\n");
	//for (i = 0; i < height - KERNEL_SIZE + 1; i++)
	//{
	//	for (j = 0; j < width - KERNEL_SIZE + 1; j++)
	//	{
	//		for (m = 0; m < KERNEL_SIZE; m++)
	//		{
	//			for (n = 0; n < KERNEL_SIZE; n++)
	//			{
	//				result = result + *(luma + (i + n) * width + j + m) * kernel_matrix[m][n];

	//			}

	//		}
	//		*(new_luma + (i + (KERNEL_SIZE >> 1)) * width + j + (KERNEL_SIZE >> 1)) = result;
	//		result = 0;
	//	}

	//}

	//for (i = 1; i < height - 1; i++)
	//{
	//	for (j = 1; j < width - 1; j++)
	//	{
	//		*(luma + (i  * width + j)) = *(new_luma + (i * width + j));
	//	}

	//}
	//
	//for (int i = 0; i < height; i++)  // цикл по строкам
	//{
	//	for (int j = 0; j < width; j++)  // цикл по столбцам
	//	{
	//		printf("%5d ", *(inPtr + i * width + j));
	//	}
	//	printf("\n");
	//}
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	//for (int i = 1; i < height - 1; i++)  // цикл по строкам
	//{
	//	for (int j = 1; j < width - 1; j++)  // цикл по столбцам
	//	{
	//		printf("%5d ", *(new_luma + i * width + j));
	//	}
	//	printf("\n");
	//}
	puts("Hello, World!");

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			*(buf_luma + (i * width + j)) = *(luma + (i * width + j));
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			*(new_luma + (i * width + j)) = *(luma + (i * width + j));
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j <= width - KERNEL_SIZE; j++)
		{
			for (m = 0; m < KERNEL_SIZE; m++)
			{
				result = result + *(luma + i * width + j + m) * kernel_matrix[m];

			}
			*(buf_luma + (i * width) + j + (KERNEL_SIZE / 2)) = result;
			result = 0;
		}

	}
	for (int i = 0; i < height; i++)  // цикл по строкам
	{
		for (int j = 0; j < width; j++)  // цикл по столбцам
		{
			printf("%5d ", *(buf_luma + i * width + j));
		}
		printf("\n");
	}

	for (i = 0; i <= height - KERNEL_SIZE; i++)
	{
		for (j = 0; j < width; j++)
		{
			for (m = 0; m < KERNEL_SIZE; m++)
			{
				result = result + *(buf_luma + (i + m) * width + j) * kernel_matrix[m];

			}
			*(new_luma + ((i + KERNEL_SIZE / 2) * width) + j) = result;
			result = 0;
		}

	}
	printf("---------------------------------------------------------------------------\n");




	for (int i = 0; i < height; i++)  // цикл по строкам
	{
		for (int j = 0; j < width; j++)  // цикл по столбцам
		{
			printf("%5d ", *(new_luma + i * width + j));
		}
		printf("\n");
	}

	free(inPtr);
	return 0;
}