#include <iostream>
using namespace std;
string Vqueue[1005]; //V队列
int Vhead=0;         //首指针
int Vtail=0;         //尾指针

string Nqueue[1005]; //N队列
int Nhead=0;         //首指针
int Ntail=0;         //尾指针



void in(string name,string type)
{
    if(type=="V"){
        Vqueue[Vtail]=name;
        Vtail++;
    }
    else
    {
        Nqueue[Ntail]=name;
        Ntail++;
    }
}



bool out(string type)
{

    if(type=="V"){
        if(Vhead==Vtail) {
            //队伍没有人不能在出队了。
            return false ;
        }
        else{
            Vhead++;//head前的数据都是无效数据，无需删除，逻辑明确即可。
            return true;
        }

    }
    else
    {
        if(Nhead==Ntail) {
            //队伍没有人不能在出队了。
             return false;
        }
        else{
            Nhead++;//head前的数据都是无效数据，无需删除，逻辑明确即可。
            return true;
        }
    }
}

string  getHead(string type)
{

    if(type=="V"){
        return Vqueue[Vhead];
    }
    else
    {
       return Nqueue[Nhead];
    }
}


int main()
{
     freopen("input (5).txt","r",stdin);

    freopen("output (5).txt","w",stdout);
    int M;
    cin>>M;
    //cout<<M;
    while(M--) //
    {
        string op,name,type;
        cin>>op;
        if(op=="IN")
        {
            cin>>name>>type;
            in(name,type);
        }
        else
        {
            cin>>type;
            out(type);
        }
    }
    string s=getHead("V");
    while(out("V"))
    {
        cout<<s<<endl;
        s=getHead("V");
    }
    s=getHead("N");
    while(out("N"))
    {
        cout<<s<<endl;
        s=getHead("N");
    }

}
