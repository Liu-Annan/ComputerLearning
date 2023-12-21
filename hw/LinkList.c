#include "linklist.h"

//初始化链表
struct linknode* init_linklist()
{
    struct linknode* header = (struct linknode*)malloc(sizeof(struct linknode));
    header->data=-1;
    header->next=NULL;

    //尾部指针
    struct linknode* pRear = header;
    int val=-1;
    while(true)
    {
        printf("请输入要插入的数据:\\n");
        scanf("%d",&val);
        if(val==-1)
        {
            break;
        }
        //创造新结点
        struct linknode* newnode = (struct linknode*)malloc(sizeof(struct linknode)); 
        newnode->data=val;
        newnode->next=NULL;
        

    }
}
//尾插法
void insertafter(struct linknode* header, int oldval, int newval);
//删除值为value的结点
void remove(struct linknode* header, int delval);
//遍历
void traverse(struct linknode* header);
//销毁
void destroy(struct linknode* header);
//清空
void clear(struct linknode* header);
