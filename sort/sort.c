/*****************************************************
File name��Quicksort
Author��Xiayaxian    Version:1.0    Date: 2017/11/07
Description: ��������п�������
Funcion List: ʵ�ֿ��������㷨
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>  
#include <stdint.h>

/**************************************************
*��������display
*���ã���ӡ����Ԫ��
*������array - ��ӡ�����飬maxlen - ����Ԫ�ظ���
*����ֵ����
**************************************************/
void display(int array[], int maxlen)
{
	int i;

	for (i = 0; i < maxlen; i++)
	{
		printf("%-10d", array[i]);
	}
	printf("\n");

	return;
}

/********************************
*��������swap
*���ã�������������ֵ
*������������������
*����ֵ����
********************************/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

	return;
}
/********************************
*��������random
*���ã����������
*����������
*����ֵ����
********************************/
void random(int array[], uint64_t len)
{   
	//int array[BUF_SIZE];
	srand((int)time(0));
    for (int i = 0; i<len; i++)
		array[i]=rand();
	//random(array);
}
/************************************
*��������quicksort
*���ã����������㷨
*������
*����ֵ����
************************************/
//void quicksort(int array[], int maxlen, int begin, int end)
//{
//	int i, j;
//
//	if (begin < end)
//	{
//		i = begin + 1;  // ��array[begin]��Ϊ��׼������˴�array[begin+1]��ʼ���׼���Ƚϣ�
//		j = end;        // array[end]����������һλ
//
//		while (i < j)
//		{
//			if (array[i] > array[begin])  // ����Ƚϵ�����Ԫ�ش��ڻ�׼�����򽻻�λ�á�
//			{
//				swap(&array[i], &array[j]);  // ����������
//				j--;
//			}
//			else
//			{
//				i++;  // �����������һλ���������׼���Ƚϡ�
//			}
//		}
//
//		/* ����whileѭ����i = j��
//		* ��ʱ���鱻�ָ����������  -->  array[begin+1] ~ array[i-1] < array[begin]
//		*                           -->  array[i+1] ~ array[end] > array[begin]
//		* ���ʱ������array�ֳ��������֣��ٽ�array[i]��array[begin]���бȽϣ�����array[i]��λ�á�
//		* ���array[i]��array[begin]���������������ָ�ֵ������Դ����ƣ�ֱ�����i = j�������������˳���
//		*/
//
//		if (array[i] >= array[begin])  // �������Ҫȡ�ȡ�>=������������Ԫ������ͬ��ֵʱ������ִ���
//		{
//			i--;
//		}
//
//		swap(&array[begin], &array[i]);  // ����array[i]��array[begin]
//
//		quicksort(array, maxlen, begin, i);
//		quicksort(array, maxlen, j, end);
//	}
//}

void quicksort(int* A, int n)
{
    typedef struct
    {
        int beg;
        int end;
    }sbe;

    sbe* arr = (sbe *)malloc(n * sizeof(sbe));
	int  m;
	int p;
	int beg, end, i, j;

	m = 0;
	arr[0].beg = 0;
	arr[0].end = n - 1;

	for (;;)
	{
		if (m < 0)
			break;
		beg = arr[m].beg;
		end = arr[m--].end;

		if (beg >= end)
			continue;

		// partition   
		p = A[beg];
		i = beg;
		j = end + 1;
		for (;;)
		{
			while (++i <= end && A[i] < p);  // ! while( A[++i] < p ); error  
			while (A[--j] > p);
			if (i > j)
				break;
			swap(&A[i], &A[j]);
		}
		swap(&A[j], &A[beg]);

		arr[++m].beg = beg;
		arr[m].end = j - 1;
		arr[++m].beg = j + 1;
		arr[m].end = end;
	}

	free(arr);
}
/************************************
*��������insertion_sort
*���ã����������㷨
*������
*����ֵ����
************************************/
void insertion_sort(int *a, int n)//aΪ���飬nΪ�������  
{
	int i, j, key;

	for (j = 1; j < n; j++) {
		key = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
}
/************************************
*��������merge_sort
*���ã��鲢�����㷨
*������
*����ֵ����
************************************/
void merge_sort(int *list, int length)
{
	int i, left_min, left_max, right_min, right_max, next;
	//int tmp[BUF_SIZE];
	int *tmp = (int*)malloc(sizeof(int) * length);

	if (tmp == NULL)
	{
		fputs("Error: out of memory\n", stderr);
		abort();
	}

	for (i = 1; i < length; i *= 2) // iΪ������1,2,4,8����
	{
		for (left_min = 0; left_min < length - i; left_min = right_max)
		{
			right_min = left_max = left_min + i;
			right_max = left_max + i;

			if (right_max > length)
				right_max = length;

			next = 0;
			while (left_min < left_max && right_min < right_max)
				tmp[next++] = list[left_min] > list[right_min] ? list[right_min++] : list[left_min++];

			while (left_min < left_max)
				list[--right_min] = list[--left_max];

			while (next > 0)
				list[--right_min] = tmp[--next];
		}
	}

	free(tmp);

}

// ������
int main()
{
    FILE *result = fopen("result.txt", "w");
    uint64_t max_buffer_size = 1024*1024*16;
    uint64_t min_buffer_size = 1024;
	int n =5;                         //���Դ���
	int *Q_array = NULL, *I_array = NULL, *M_array = NULL;
    Q_array = (int *)malloc(sizeof(int) * max_buffer_size);
    I_array = (int *)malloc(sizeof(int) * max_buffer_size);
    M_array = (int *)malloc(sizeof(int) * max_buffer_size);

	//printf("����ǰ������\n");
	//display(Q_array, maxlen);
	clock_t Q_start, Q_finish, I_start, I_finish,M_start, M_finish;
	double Q_duration, I_duration = 0, M_duration = 0, Q_sum = 0, I_sum = 0, M_sum = 0, Q_avg = 0, I_avg = 0, M_avg = 0;
	double duration;

    printf("start testing......\n");
    int count = 0;
    printf("%d%%\r", count * 100 / 8);
    for (int arrlen = min_buffer_size; arrlen <= max_buffer_size; arrlen *= 4) {
        int buffer_len = arrlen / 1024;
        if (buffer_len<1024) {
            fprintf(result, "%dK��������ʱ��:\n", buffer_len);
        }
        else {
            buffer_len /= 1024;
            fprintf(result, "%dM��������ʱ��:\n", buffer_len);
        }
        for (int time = 1; time <= n; time++) {
            random(Q_array, arrlen);
            memcpy(I_array, Q_array, sizeof(int) * max_buffer_size);
            memcpy(M_array, Q_array, sizeof(int) * max_buffer_size);
            Q_duration = 0;
            I_duration = 0;
            M_duration = 0;

            Q_start = clock();
            quicksort(Q_array, arrlen);  // ��������
            Q_finish = clock();
            Q_duration = (double)(Q_finish - Q_start) / CLOCKS_PER_SEC;

            if (arrlen < 64000) {
                I_start = clock();
                insertion_sort(I_array, arrlen);
                I_finish = clock();
                I_duration = (double)(I_finish - I_start) / CLOCKS_PER_SEC;
            }

            M_start = clock();
            merge_sort(M_array, arrlen);
            M_finish = clock();
            M_duration = (double)(M_finish - M_start) / CLOCKS_PER_SEC;

            duration = (double)(M_finish - Q_start) / CLOCKS_PER_SEC;

            //display(Q_array, maxlen);
            fprintf(result, "��%d�ο���������ʱ�� %f seconds\n", time, Q_duration);
            fprintf(result, "��%d�β���������ʱ�� %f seconds\n", time, I_duration);
            fprintf(result, "��%d�ι鲢������ʱ�� %f seconds\n", time, M_duration);
            fprintf(result, "��ʱ�� %f seconds\n", duration);
            fprintf(result, "\n");
        }
        fprintf(result, "\n");
        count++;
        printf("%d%%\r", count*100/8);
    }
    printf("\nend\n");
	free(Q_array);
	free(I_array);
	free(M_array);
    fclose(result);
	system("pause");
	return 0;
}