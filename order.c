#include<stdio.h>

#define MAXSIZE 10
#define true 1
#define false 0

typedef int Status;

typedef struct { // 要进行排序的数组的数据结构
	int r[MAXSIZE + 1];
	int length;
} SqList;

void swap(SqList *L, int i, int j){ // 用于两个元素交换
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void BubbleSort(SqList *L){ // 冒泡排序
	int i;
	int j;
	for(i = 1; i < L->length; i++){
		for(j = L->length; j > i; j--){
			if(L->r[i] > L->r[j]){
				swap(L, i, j);
			}
		}
	}
}

void SelectSort(SqList *L){ // 简单选择排序
	int i;
	int j;
	int min;
	for(i = 1; i < L->length; i++){
		min = i;
		for(j = i + 1; j <= L->length; j++){
			if(L->r[i] > L->r[j]){
				min = j;
			}
		}
		if(i != min){
			swap(L, i, min);
		}
	}
}

void InsertSort(SqList *L){ // 直接插入排序
	int i;
	int j;
	for(i = 2; i < L->length; i++){
		if(L->r[i - 1] > L->r[i]){
			L->r[0] = L->r[i];
			for(j = i - 1; L->r[j] > L->r[0]; j--){
				L->r[j + 1] = L->r[j];
			}
			L->r[j + 1] = L->r[0];
		}
	}
}

void ShellSort(SqList *L){ // 希尔排序
	int i;
	int j;
	int gap;
	for(gap = L->length / 2; gap >= 1; gap = gap / 2){
		for(i = gap + 1; i <= L->length; i++){
			if(L->r[i - gap] > L->r[i]){
				L->r[0] = L->r[i];
				for(j = i - gap; (j >= 0)&&(L->r[j] > L->r[0]); j = j - gap){
					L->r[j + gap] = L->r[j];
				}
				L->r[j + gap] = L->r[0];
			}
		}
	}
}

void HeapAdjust(SqList *L, int cur, int length){ // 递归实现
	// 进行堆调整，将序列转换成大顶堆
	int j = 2 * cur;
	if(j <= length){ // 若当前节点含有左节点
		if(j + 1 <= length){ // 若当前节点含有右节点
			if(L->r[j] < L->r[j + 1]){ // 从左右节点中选取具有最大关键字的节点
				j++;
			}
		}
		if(L->r[cur] >= L->r[j]){ // 当前节点与具有最大关键字的子节点进行对比
			// 满足大顶堆的条件时返回上一层
			return;
		}else{
			swap(L, cur, j);
			HeapAdjust(L, j, length);
		}
	}
}

void HeapSort(SqList *L){ // 堆排序
	int i;
	int length = L->length;
	// 第一步，将待排序序列转换成大顶堆
	for(i = length / 2; i > 0; i--){
		HeapAdjust(L, i, length);
	}
	// 第二步，进行堆排序
	for(i = length; i > 0; i--){
		swap(L, 1, i);
		HeapAdjust(L, 1, i - 1);
	}
}

int main(){
	return 0;
}
