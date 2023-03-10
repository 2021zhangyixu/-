#ifndef __sqlist_H
#define __sqlist_H	

#define success 0
#define fail  -1
#define MAXSIZE 20          /* 存储空间初始分配量 */

typedef int ElemType;       /* ElemType类型根据实际情况而定，这里假设为int */

typedef struct
{
    ElemType data[MAXSIZE]; /* 数组，存储数据元素 */
    int last;             /* 线性表当前位置，last+1=length */
}SqList,*SqLink;     /*SqList是定义线性表，SqLink是定义线性表的结构体指针*/


SqLink list_create(void); //创建线性表，返回一个结构体指针
int list_if_exist(SqLink L);//判断线性表是否存在
int list_delete(SqLink L);//删除线性表，线性表不存在返回fail，线性表成功删除返回success
int list_clear(SqLink L); //清空线性表，成功返回succes,失败返回fail
int list_if_empty(SqLink L);//判读线性表是否为空
int list_get_length(SqLink L); //查看当前线性表长度
int list_value_if_locate(SqLink L,ElemType value);//判断value是否在线性表中
int list_insert(SqLink L,ElemType value,int pos);//在线性表L的pos处插入数据value
int list_delete_pos_value(SqLink L,int pos);//删除指定位置的元素
int list_merge(SqLink L1,SqLink L2,SqLink L3);//L1和L2并集，将并集值给到L3
int list_purge(SqLink L);//删除线性表中的重复文件
int list_pos_value(SqLink L,int pos);//返回指定位置的值
int list_show(SqLink L);//显示线性表中的值

#endif

