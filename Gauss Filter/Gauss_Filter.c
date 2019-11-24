#include <stdio.h>
#include "stdlib.h"
#define KERNEL_SIZE 5;

int main(void)
{
	int a = 0;
	int width = 10;
	int i = 0;
	int j = 0;
	int m = 0;
	int n = 0 ;
	int kernelSize = 3;
	int height = 10;
	int result = 0;
	//float kernel[5][5] = { { 0.000789, 0.006581, 0.013347, 0.006581, 0.000789 },
	//					{ 0.006581, 0.054901, 0.111345, 0.054901, 0.006581 },
	//					{ 0.013347, 0.111345, 0.225821, 0.111345, 0.013347},
	//					{  0.006581, 0.054901, 0.111345, 0.054901, 0.006581 },
	//					{  0.000789, 0.006581, 0.013347, 0.006581, 0.000789 } };
	float kernel_matrix[3][3] = {
					{  0.054901, 0.111345, 0.054901},
					{  0.111345, 0.225821, 0.111345},
					{  0.054901, 0.111345, 0.054901}};
	int* inPtr;
	int* new_luma;
	inPtr = (int*)malloc(width * height * sizeof(int));
	inPtr = (int*)malloc(width * height * sizeof(int));
	new_luma = (int*)malloc(width * height * sizeof(int));
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

	for (i = 0; i < height - KERNEL_SIZE + 1, i++)
	{
		for (j = 0; j < width - KERNEL_SIZE + 1; j++)
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

	for (i = 1; i < height - 1; i++)
	{
		for (j = 1; j < width - 1; j++)
		{
			*(luma + (i  * width + j)) = *(new_luma + (i * width + j));
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
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	for (int i = 1; i < height - 1; i++)  // цикл по строкам
	{
		for (int j = 1; j < width - 1; j++)  // цикл по столбцам
		{
			printf("%5d ", *(new_luma + i * width + j));
		}
		printf("\n");
	}


	printf("%5d ", 5/2);
	puts("Hello, World!");
	free(inPtr);
	return 0;
}