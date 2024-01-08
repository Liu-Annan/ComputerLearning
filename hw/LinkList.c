#include "LinkList.h"

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
        printf("请输入要插入的数据:\n");
        scanf("%d",&val);
        if(val==-1)
        {
            break;
        }
        //创造新结点
        struct linknode* newnode = (struct linknode*)malloc(sizeof(struct linknode)); 
        newnode->data=val;
        newnode->next=NULL;
        //将新结点插入到链表中
        pRear->next=newnode;
        //更新尾部指针
        pRear=newnode;
    }
    return header;
}
//头插法
void inserthead(struct linknode* header, int oldval, int newval)
{
    if(header==NULL)
    {
        return;
    }
    //需要两个辅助指针
    struct linknode* ppreview=header;
    struct linknode* pcurrent=ppreview->next;
    while(pcurrent!=NULL)
    {
        //找到要插入结点的地址就跳出循环
        if(pcurrent->data==oldval)
        {
            break;
        }
        //调整指针
        ppreview=pcurrent;
        pcurrent=pcurrent->next;
    }
    if(pcurrent==NULL)
    {
        return;
    }
    else
    {
        //创建新的结点
        struct linknode* newnode = (struct linknode*)malloc(sizeof(struct linknode)); 
        newnode->data=newval;
        newnode->next=NULL;
        //将结点插入链表
        ppreview->next=newnode;
        newnode->next=pcurrent;
    }
}
//删除值为value的结点
void Remove(struct linknode* header, int delval)
{
    if(header==NULL)
    {
        return;
    }
    //需要两个辅助指针
    struct linknode* ppreview=header;
    struct linknode* pcurrent=ppreview->next;
    while(pcurrent!=NULL)
    {
        //找到所要删除的结点就跳出循环
        if(pcurrent->data==delval)
        {
            break;
        }
        //调整指针
        ppreview=pcurrent;
        pcurrent=pcurrent->next;
    }
    if(pcurrent==NULL)
    {
        return;
    }
    else
    {
        //删除结点
        ppreview->next=pcurrent->next;
        free(pcurrent);
        pcurrent=NULL;
    }
}
//遍历
void traverse(struct linknode* header)
{
    if(header==NULL)
    {
        return;
    }
    //需要一个辅助指针
    struct linknode* pcurrent=header->next;
    while(pcurrent!=NULL)
    {
        printf("%d ",pcurrent->data);
        pcurrent=pcurrent->next;
    }
}
//销毁
void destroy(struct linknode* header)
{
    if(header==NULL)
    {
        return;
    }
    //需要一个辅助指针
    struct linknode* pcurrent=header;
    while(pcurrent!=NULL)
    {
        //保存当前结点的下一个结点的地址
        struct linknode* pnext=pcurrent->next;
        //释放当前结点
        free(pcurrent);
        //调整指针
        pcurrent=pnext;
    }
}
//清空
void clear(struct linknode* header)
{
    if(header==NULL)
    {
        return;
    }
    //需要一个辅助指针
    struct linknode* pcurrent=header->next;
    while(pcurrent!=NULL)
    {
        //保存当前结点的下一个结点的地址
        struct linknode* pnext=pcurrent->next;
        //释放当前结点
        free(pcurrent);
        //调整指针
        pcurrent=pnext;
    }
    header->next=NULL;
}
