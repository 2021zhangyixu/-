#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlist.h"

/*作用:   创建线性表
 *传入参数：无
 *返回参数：创建失败打印错误报告，创建成功返回创建线性表的结构体指针
 */
SqLink list_create(void)
{
	//建立线性表
	SqLink L;
	L = (SqLink)malloc(sizeof(SqList));
	//确认线性表是否存在
	if(L == NULL)
	{
		printf("list malloc failed!\n");
		return L;
	}
	//线性表存在，将其内容清空
	//注意，这两句别写反了，否则last会变成0。
	memset(L , 0 , sizeof(SqList));
	L -> last = -1;  //last表示线性表的指向位置，因为在C语言中，下标是从0开始，所以当为空表是last=-1
	//返回线性表
	return L;
}

/*作用:   判断线性表是否存在
 *传入参数：
 *	@L: 线性表的结构体指针
 *返回参数：线性表不存在返回fail，线性表存在返回success
 */
int list_if_exist(SqLink L)
{
	if(L==NULL)
	{
		printf("list is not exist!\n");
		return fail;
	}
	return success;
}


/*作用:   删除线性表
 *传入参数：
 *	@L: 线性表的结构体指针
 *返回参数：线性表不存在返回fail，线性表成功删除返回success
 */
int list_delete(SqLink L)
{
	if(L==NULL)
	{
		printf("list is not exist!\n");
		return fail;
	}
	free(L);
	L=NULL;
	return success;
}


/*作用:   清空线性表
 *传入参数：
 *	@L: 线性表的结构体指针
 *返回参数：成功返回succes,失败返回fail
 */
int list_clear(SqLink L)
{
	//确认线性表是否存在
	if(L == NULL)
	{
		printf("list is not exist!\n");
		return fail;
	}
	//线性表存在，将其内容清空
	//注意，这两句别写反了，否则last会变成0。
	memset(L , 0 , sizeof(SqList));
	L -> last = -1;  //last表示线性表的指向位置，因为在C语言中，下标是从0开始，所以当为空表是last=-1
	return success;
}

/*作用:   判读线性表是否为空(因为使用者并不知道函数实现具体细节，所以需要加上这个)
 *传入参数：
 *	@L: 线性表的结构体指针
 *返回参数：线性表为空返回succes,否则返回fail
 */
int list_if_empty(SqLink L)
{
	//确认线性表是否存在
	if(L==NULL)
	{
		printf("list is not exist!\n");
		return fail;
	}
	if(L -> last ==-1)
	{
		printf("list is empty!\n");
		return success;
	}
	return fail;
}

/*作用:   查看当前线性表长度
 *传入参数：
 *	@L: 线性表的结构体指针
 *返回参数：返回当前线性表的长度
 */
int list_get_length(SqLink L)
{
	//确认线性表是否存在
	if(L==NULL)
	{
		printf("list is not exist!\n");
		return fail;
	}
	return (L->last+1);
}

/*作用:   判断value是否在线性表中
 *传入参数：
 *	@L:线性表的结构体指针
 *  @value:需要查看线性表中是否存在的值
 *		@可输入值范围受到ElemType决定
 *返回参数：value在线性表中存在返回succes,value不在线性表中或线性表不存在返回fail
 */
int list_value_if_locate(SqLink L,ElemType value)
{
	int i;
	//确认线性表是否存在
	if(L==NULL)
	{
		printf("list is not exist!\n");
		return fail;
	}
	//逐个判断线性表中的值
	for(i = 0;i<=L->last;i++)
	{
		if(L->data[i]==value)
		{
			return success;
		}
	}

	return fail;
}

/*作用:   插入数据，在线性表L的pos处插入数据value
 *传入参数：
 *	@L: 线性表的结构体指针
 *  @value: 需要插入线性表的值
 *		@可输入值范围受到ElemType决定
 *  @pos：需要插入的位置
 *		@插入位置范围受到MAXSIZE限制
 *返回参数：返回当前线性表的长度
 */
int list_insert(SqLink L,ElemType value,int pos)
{
	int i; 
	//确认线性表是否存在
	if(L==NULL)
	{
		printf("list is not exist!\n");
		return fail;
	}
	//如果线性表满了
	if(L->last == MAXSIZE-1)
	{
		printf("list is full\n");
		return fail;
	}
	//判断插入的位置是否合法
	if(pos<0 || pos > L->last+1)
	{
		printf("pos is invaild\n");
	}
	//向后移动
	for(i = L -> last;i >= pos;i--)
	{
		L->data[i+1]=L->data[i];
	}
	//更新last和插入部分数值
	L->data[pos]=value;
	L->last++;
	
	return success;
}

/*作用:   删除指定位置的元素
 *传入参数：
 *	@L: 线性表的结构体指针
 *  @pos： 需要删除的数据的位置
 *		@插入位置范围受到MAXSIZE限制
 *返回参数：删除失败返回fail，成功删除返回success
 */
int list_delete_pos_value(SqLink L,int pos)
{
	int i;
	//确认线性表是否存在
	if(L==NULL)
	{
		printf("list is not exist!\n");
		return fail;
	}
	//检测是否为空表
	if(L->last==-1)
	{
		printf("list is empty!\n");
		return fail;
	}
	//检测删除位置是否合理
	if(pos < 0 || pos > L->last)
	{
		printf("pos is invalid！\n");
		return fail;
	}
	//向前移动
	for(i=pos+1;i<=L->last;i++)
	{
		L->data[i-1]=L->data[i];
	}
	//更改last
	L->last--;
	
	return success;
}

/*作用: L1和L2并集，将并集值给到L3
 *传入参数：
 *	@L1，L2: 两个不同的线性表
 *  @L3： L1和L2并集
 *返回参数：失败返回fail，成功返回success
 */
int list_merge(SqLink L1,SqLink L2,SqLink L3)
{
	int i;
	//判断L1，L2，L3是否存在
	list_if_exist(L1);
	list_if_exist(L2);
	list_if_exist(L3);
	//判断L1，L2,是否为空
	list_if_empty(L1);
	list_if_empty(L2);
	//将L1中的所有元素存放到L3中
	for(i = 0; i <= L1->last;i++)
	{
		list_insert(L3, L1->data[i],L3->last+1);
	}
	
	for(i = 0; i <= L2->last;i++)
	{
		//判读L2中的每一个元素是否在L1中,如果不在，就存入到L3中
		if(list_value_if_locate(L1,L2->data[i])==-1)
		{
			//如果L3满了，提前结束
			if(list_insert(L3,L2->data[i],L3->last+1)==fail)
			{
				return fail;
			}
		}
	}
	return success;
}

/*作用:删除线性表中重复元素
 *传入参数：
 *	@L1 : 线性表的结构体指针
 *返回参数：删除成功返回success
 */
int list_purge(SqLink L)
{
	int i,j;
	//确认线性表是否存在
	if(L==NULL)
	{
		printf("list is not exist!\n");
		return fail;
	}
	//如果当前线性表只有一个元素，就没有必要判断了
	if(L->last==0)
	{
		return success;
	}
	//让i不断向后移动
	for(i=1;i<=L->last;i++)
	{
		//将位置i之前的元素与i处元素进行判断，相同就删除
		for(j=i-1;j>=0;j--)
		{
			//如果发现前面有与位置i相同的元素，删除，保持i不动
			if(L->data[i]==L->data[j])
			{
				//位置i与前面有重复，就删除位置i的值
				list_delete_pos_value(L,i);
				//因为需要保持位置i不动，而for语句中有i++，所以这里用i--抵消
				i--;
				break;
			}
		}
	}
	return success;
}

/*作用: 返回指定位置的值
 *传入参数：
 *	@L: 线性表的结构体指针
 *  @pos：指定位置
 *		@插入位置范围受到MAXSIZE限制
 *返回参数：线性表为空，返回fail。成功打印返回success
 */
int list_pos_value(SqLink L,int pos)
{
	//判断线性表是否存在
	if(L==NULL)
	{
		printf("list is not exist!\n");
		return fail;
	}
	//判断是否为空表
	if(L->last==-1)
	{
		printf("list is empty!\n");
	}
	//判断获取数据的位置是否合法
	if(pos<0 || pos > L->last+1)
	{
		printf("pos is invaild\n");
	}
	//返回指定位置值
	return (L->data[pos]);
}


/*作用: 显示线性表中的值
 *传入参数：
 *	@L: 线性表的结构体指针
 *返回参数：线性表为空，返回fail。成功打印返回success
 */
int list_show(SqLink L)
{
	int i;
	//判断线性表是否存在
	if(L==NULL)
	{
		printf("list is not exist!\n");
		return fail;
	}
	//判断是否为空表
	if(L->last==-1)
	{
		printf("list is empty!\n");
	}
	//将线性表中的值打印出来
	for(i=0;i<=L->last;i++)
	{
		printf("%d ",L->data[i]);
	}
	printf("\n");
	return success;
}


