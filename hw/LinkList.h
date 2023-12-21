#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct linknode
{
	int data;
	struct linknode* next;
};
//初始化链表
struct linknode* init_linklist();
//头插法
void inserthead(struct linknode* header, int oldval, int newval);
//删除值为value的结点
void Remove(struct linknode* header, int delval);
//遍历
void traverse(struct linknode* header);
//销毁
void destroy(struct linknode* header);
//清空
void clear(struct linknode* header);

