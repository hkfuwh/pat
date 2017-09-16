#include <iostream>
#include<stdio.h>
using namespace std;
//typedef map<int,int>::iterator it;


/*运用反向迭代器使之能够降序输出*/
struct node{
    int data;
    int next;
};
int Reverse(node* list,int pList,int n,int k);
void printlist(node* l,int head);
int countlist(node* l,int p);
int main()
{
    node L[100000];
    int m,n;
    int firstdata;
    int ad;
    cin>>firstdata>>m>>n;
    for(int i=0;i<m;i++)
    {
        cin>>ad;
        cin>>L[ad].data>>L[ad].next;
    }
    int num=countlist(L,firstdata);
    int newlist=Reverse(L,firstdata,num,n);
    printlist(L,newlist);
    return 0;
}
/*翻转链表,l表示链表，st第一个元素的地址，n表示元素的总个数，k表示翻转的区段长度
返回表的头结点*/
int Reverse(node* list,int pList,int n,int k)
{
   int prevNode, currNode, nextNode;
    prevNode = -1;
    currNode = pList;
    nextNode = list[currNode].next;
    int lastHead, head = -1;
    int i ,j;
    for( i = 0; i < n / k; i++){
            lastHead = head;//记录前一段的（未逆转的）头结点，以便连接到当前段的(未逆转的）尾节点
                head = currNode;//记录当前段的头结点
            for(j = 0; j < k; j++) { //k个结点逆转，后一节点指向前一节点
            list[currNode].next = prevNode;
                prevNode = currNode;
                currNode = nextNode;
                nextNode = list[nextNode].next;
            }
            if(i == 0)//第一段逆转后的头结点当作表头返回
                      pList = prevNode;
            else
               list[lastHead].next = prevNode;//连接逆转后的前后两段
   }
 list[head].next = currNode;    //不用逆转的剩余部分加上
    return pList;

}
void printlist(node* l,int p)
{

    while(l[p].next!=-1)
    {
        printf("%05d %d %05d\n",p,l[p].data,l[p].next);
        p=l[p].next;
    }
    printf("%05d %d %d\n",p,l[p].data,l[p].next);
}
int countlist(node* l,int p)//计算列表中的元素个数
{
    int cnt=1;
    while((p=l[p].next)!=-1)
        cnt++;
    return cnt;
}

