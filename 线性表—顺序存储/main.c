#include <stdio.h>
#include "sqlist.h"

void test_insert(void);
void test_delete_pos_value(void);
void test_merge(void);
void test_purge(void);
void test_pos_value(void);

int main(int argc,const char* argv[])
{
	test_pos_value();
	printf("\n*******new test**********\n");
	test_insert();
	printf("\n*******new test**********\n");
	test_delete_pos_value();
	printf("\n*******new test**********\n");
	test_merge();
	printf("\n*******new test**********\n");
	test_purge();
	return 0;
}

/*
 *用于测试list_pos_value(SqLink L,int pos)
 */
void test_pos_value(void)
{
	//创建线性表
	SqLink L;
	L = list_create();
	//插入数据
	list_insert(L,10,0);
	list_insert(L,20,0);
	list_insert(L,30,0);
	list_insert(L,40,0);
	//显示线性表
	list_show(L);
	//显示指定位置值
	printf("下标为3的元素是：%d\n",list_pos_value(L,3));
	//删除线性表
	list_delete(L);
}


/*
 *用于测试list_insert()
 */
void test_insert(void)
{
	//创建线性表
	SqLink L;
	L = list_create();
	//插入数据
	list_insert(L,10,0);
	list_insert(L,20,0);
	list_insert(L,30,0);
	list_insert(L,40,0);
	list_insert(L,50,22);
	//显示线性表
	list_show(L);
	//删除线性表
	list_delete(L);
}

/*作用：用于测试list_insert()
 *传入参数：无
 *返回参数：无
 */
void test_delete_pos_value(void)
{
	//创建线性表
	SqLink L;
	L = list_create();
	//插入数据
	list_insert(L,10,0);
	list_insert(L,20,0);
	list_insert(L,30,0);
	list_insert(L,40,0);
	list_insert(L,50,0);
	//显示线性表
	list_show(L);
	//删除有效位置元素
	list_delete_pos_value(L,3);
	//显示线性表
	list_show(L);
	//删除无效位置元素
	list_delete_pos_value(L,10);
	//显示线性表
	list_show(L);
	//删除线性表
	list_delete(L);
}

/*作用：用于测试list_merge()
 *传入参数：无
 *返回参数：无
 */
void test_merge(void)
{
	//创建线性表
	SqLink L1,L2,L3;
	L1 = list_create();
	L2 = list_create();
	L3 = list_create();
	//插入数据
	list_insert(L1,10,0);
	list_insert(L1,20,0);
	list_insert(L1,30,0);
	list_insert(L1,40,0);
	list_insert(L1,50,0);
	
	list_insert(L2,60,0);
	list_insert(L2,70,0);
	list_insert(L2,80,0);
	list_insert(L2,50,0);
	list_insert(L2,20,0);

	//显示线性表
	list_show(L1);
	list_show(L2);
	printf("***************\n");
	//求并集
	list_merge(L1,L2,L3);
	list_show(L3);
	//删除线性表
	list_delete(L1);
	list_delete(L2);
	list_delete(L3);
}


/*作用：用于测试list_purge()
 *传入参数：无
 *返回参数：无
 */
void test_purge(void)
{
	//创建线性表
	SqLink L;
	L = list_create();
	//插入数据
	list_insert(L,10,0);
	list_insert(L,10,0);
	list_insert(L,10,0);
	list_insert(L,10,0);
	list_insert(L,10,0);
	list_show(L);
	//将线性表L中的重复元素删除
	list_purge(L);
	list_show(L);
	//删除线性表
	list_delete(L);
}

