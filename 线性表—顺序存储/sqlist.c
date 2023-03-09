#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlist.h"

/*作用:   创建线性表
 *传入参数：无
 *返回参数：返回创建线性表的结构体指针
 */
SqLink list_create(void)
{
	//建立线性表
	SqLink L;
	L = (SqLink)malloc(sizeof(SqList));
	//确认线性表是否存在
	if(L == NULL)
	{
		printf("list is not creat!\n");
	}
	//线性表存在，将其内容清空
	//注意，这两句别写反了，否则last会变成0。
	memset(L , 0 , sizeof(SqList));
	L -> length = -1;  //last表示线性表的指向位置，因为在C语言中，下标是从0开始，所以当为空表是last=-1
	//返回线性表
	return L;
}

/*作用:   删除线性表
 *传入参数：
 *	L: 线性表的结构体指针
 *返回参数：线性表不存在返回fail，线性表成功删除返回success
 */
int list_delete(SqLink L)
{
	if(L==NULL)
	{
		return fail;
	}
	free(L);
	L=NULL;
	return success;
}


/*作用:   清空线性表
 *传入参数：
 *	L: 线性表的结构体指针
 *返回参数：成功返回succes,失败返回fail
 */
int list_clear(SqLink L)
{
	//确认线性表是否存在
	if(L == NULL)
	{
		printf("list is not creat!\n");
		return fail;
	}
	//线性表存在，将其内容清空
	//注意，这两句别写反了，否则last会变成0。
	memset(L , 0 , sizeof(SqList));
	L -> length = -1;  //last表示线性表的指向位置，因为在C语言中，下标是从0开始，所以当为空表是last=-1
	return success;
}

/*作用:   判读线性表是否为空(因为使用者并不知道函数实现具体细节，所以需要加上这个)
 *传入参数：
 *	L: 线性表的结构体指针
 *返回参数：线性表为空返回succes,否则返回fail
 */
int list_if_empty(SqLink L)
{
	if(L -> length ==-1)
	{
		printf("list is empty!\n");
		return success;
	}
	return fail;
}

/*作用:   查看当前线性表长度
 *传入参数：
 *	L: 线性表的结构体指针
 *返回参数：返回当前线性表的长度
 */
int list_get_length(SqLink L)
{
	if(L->length==-1)
	{
		return -1;
	}
	return (L->length+1);
}

/*作用:   判断value是否在线性表中
 *传入参数：
 *	L:线性表的结构体指针
 *  value:需要查看线性表中是否存在的值
 *返回参数：value在线性表中存在返回succes,否则返回fail
 */
int list_value_if_locate(SqLink L,ElemType value)
{
	
	return 0;
}

/*作用:   插入数据，在线性表L的pos处插入数据value
 *传入参数：
 *	L: 线性表的结构体指针
 *  value: 需要插入线性表的值
 *  pos： 需要插入的位置
 *返回参数：返回当前线性表的长度
 */
int list_insert(SqLink L,ElemType value,int pos)
{
	int i; 
	//如果线性表满了
	if(L->length == MAXSIZE-1)
	{
		printf("list is full\n");
		return fail;
	}
	//判断插入的位置是否合法
	if(pos<0 || pos > L->length+1)
	{
		printf("pos is invaild\n");
	}
	//移动
	for(i = L -> length;i >= pos;i--)
	{
		L->data[i+1]=L->data[i];
	}
	//更新length和插入部分数值
	L->data[pos]=value;
	L->length++;
	
	return success;
}

/*作用: 显示线性表中的值
 *传入参数：
 *	L: 线性表的结构体指针
 *返回参数：线性表为空，返回fail
 */
int list_show(SqLink L)
{
	int i;
	if(L==NULL)
	{
		return fail;
	}
	if(L->length==-1)
	{
		printf("list is empty\n");
	}
	for(i=0;i<=L->length;i++)
	{
		printf("%d ",L->data[i]);
	}
	printf("\n");
	return success;
}


