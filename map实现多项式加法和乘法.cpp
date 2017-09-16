#include <iostream>
#include<vector>
#include<map>
using namespace std;
typedef map<int,int>::iterator it;
typedef map<int,int>::reverse_iterator it1;
/*运用反向迭代器使之能够降序输出*/
void print(it1 i,it1 j,map<int,int>::size_type n);
int main()
{/*map存储的内容用迭代器访问时默认按照升序访问*/
    map<int,int> numque1,numque2,ians,jans;
    /*first 表示指数  second 表示系数*/
    int m,n;
    int co,ex;/*co表示系数，ex表示指数*/
    cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>co;
            cin>>ex;
            numque1[ex]=co;
        }
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>co;
            cin>>ex;
            numque2[ex]=co;
    }
//    for(it1 i=numque1.rbegin();i!=numque1.rend();i++)
//        cout<<i->second<<" "<<i->first<<endl;
//    for(it1 j=numque2.rbegin();j!=numque2.rend();j++)
//        cout<<j->second<<" "<<j->first<<endl;
    for(it i=numque1.begin();i!=numque1.end();i++)
        for(it j=numque2.begin();j!=numque2.end();j++)
    {
        ex=i->first+j->first;//指数相加
        int temp=ians[ex]+i->second*j->second;//系数相乘
        if(temp!=0)
            ians[ex]=temp;
        else
            ians.erase(ex);
//        cout<<ex<<" "<<ians[ex]<<endl;
    }
    /*加法运算*/
    it i=numque1.begin(),j=numque2.begin();
    while(i!=numque1.end()&&j!=numque2.end())
    {
        if(i->first==j->first)
            {/*寻找同类项，如果系数和不为零则存入结果多项式*/
                 if(i->second+j->second!=0)
                {
                    jans[i->first]=i->second+j->second;
                }
                i++;j++;
            }

        else if(i->first<j->first)
        {
            jans[i->first]=i->second;
            i++;
        }
            else
            {
                jans[j->first]=j->second;
                j++;
            }
    }
    while(i!=numque1.end())
    {
        jans[i->first]=i->second;
        i++;
    }
    while(j!=numque2.end())
    {
        jans[j->first]=j->second;
        j++;
    }
    print(ians.rbegin(),ians.rend(),ians.size());
    print(jans.rbegin(),jans.rend(),jans.size());
    return 0;
}
void print(it1 i,it1 j,map<int,int>::size_type n)
{
    map<int,int>::size_type t=1;
    if(n==0)
    {
        cout<<"0 0\n";
        return;
    }
    while(i!=j)
    {
        if(t++==n)
            cout<<i->second<<" "<<i->first<<endl;
        else
        cout<<i->second<<" "<<i->first<<" ";
        i++;
    }

}
