#include <iostream>
#include<vector>
using namespace std;
typedef vector<int>::iterator it;
int main()
{
    vector<int> numque;
    int n;
    cin>>n;
    numque.resize(n);
    int sum=0;
    it start=numque.begin();
    it endnum=numque.end();
    it tsta=start;
    int temp=0;
    bool tag=false,tag2=false;
    for(it i=numque.begin();i!=numque.end();i++)
    {
        cin>>*i;
        if(tag)
        {
             tsta=i;
             tag=false;
        }
        if(*i>=0)
            tag2=true;
        temp+=*i;
        if(temp>sum)
        {
            sum=temp;
            endnum=i;
            start=tsta;
        }
        else if(temp<0)
        {
            tag=true;
            temp=0;
        }
    }
    if(sum==0)
    {
      if(tag2==false)
        {
            cout<<0<<" "<<numque[0]<<" "<<numque[n-1]<<endl;
        }
        else
            cout<<"0 0 0\n";
    }

    else
        cout<<sum<<" "<<*start<<" "<<*endnum<<endl;

//    cout << "Hello world!" << endl;
    return 0;
}
