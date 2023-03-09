#include <stdio.h>
#include "sqlist.h"

void test_insert(void);

int main(int argc,const char* argv[])
{
	test_insert();
	return 0;
}


void test_insert(void)
{
	SqLink L;
	//创建线性表
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



