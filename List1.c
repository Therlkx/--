//线性表的顺序存储
#include <stdio.h>
#include <malloc.h>
typedef struct LNode* List;
typedef int ElementType; // ElementType可以指定为任何类型
#define MAXSIZE  20

struct LNode {
	ElementType Data[MAXSIZE];
	int Last;
};
struct LNode L;
List PtrL;

List MakeEmpty();//初始化顺序表
int Find(ElementType X, List PtrL);//查找
void Insert(ElementType X, int i, List PtrL);//插入
ElementType FindIth(int i, List PtrL);//返回下标为i的当前值
void Delete(int i, List PtrL);//删除
int Length(List PtrL);//顺序表长度


int main() {
	int i = 0;
	//初始化
	PtrL = MakeEmpty();
	Insert(15, 1, PtrL);
	Insert(16, 2, PtrL);
	Insert(17, 3, PtrL);
	Insert(18, 4, PtrL);
	for (i = 0; i < Length(PtrL); i++)
		printf("%d", PtrL->Data[i]);
	printf("\n");
	Delete(1, PtrL);
	Delete(1, PtrL);
	for (i = 0; i < Length(PtrL); i++)
		printf("%d", PtrL->Data[i]);
	printf("\n");

	return 0;
}

//初始化顺序表
List MakeEmpty() {
	List PtrL;
	PtrL = (List)malloc(sizeof(struct LNode));//分配内存空间
	PtrL->Last = -1;
	return PtrL;
}

//查找
int Find(ElementType X, List PtrL){
	int i = 0;
	while (i <= PtrL->Last && PtrL->Data != X)
		i++;
	if (i > PtrL->Last)
		return -1;	//如果没找到返回-1
	else
		return i;	//如果找到返回存储位置
}

//插入
void Insert(ElementType X, int i, List PtrL){
	int j;
	if (PtrL->Last == MAXSIZE - 1) {
		printf("表满");
		return;
	}
	if (i<1 || i > PtrL->Last + 2) {
		printf("位置不合法");
		return;
	}
	for (j = PtrL->Last; j >= i - 1; j--) {
		PtrL->Data[j + 1] = PtrL->Data[j];//倒序后移
	}
	PtrL->Data[i - 1] = X;//新元素插入
	PtrL->Last++;
	return;
}

//返回下标为i的当前值
ElementType FindIth(int i, List PtrL) {
	if (i<1 || i>PtrL->Last + 1) {
		printf("不存在第%d个元素", i);
		return;
	}
	else
		return PtrL->Data[i];
}

//删除
void Delete(int i, List PtrL) {
	int j;
	if (i<1 || i>PtrL->Last + 1) {
		printf("不存在第%d个元素", i);
		return;
	}
	for (j = i; j <= PtrL->Last; j++)
		PtrL->Data[j - 1] = PtrL->Data[j];//将删除的元素后面的元素依次向前移
	PtrL->Last--;
	return;
}

//顺序表的长度
int Length(List PtrL) {
	int Length = PtrL->Last+1;
	return Length;
}
