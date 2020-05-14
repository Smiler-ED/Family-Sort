#include<iostream>

using namespace std;


void orden (int num[])
{
    for (int i=0;i<10;i++)
    {
        int numeropeque=i;
        for(int j=i+1;j<10;++j)
        {
            if(num[j]<num[numeropeque])
                numeropeque=j;
        }
        swap(num[i],num[numeropeque]);
    }
}

int main ()
{
    cout<<"Valores del arreglo -> 132,45,23,29,30,31,27,8,1,3"<<endl;
    int num[10]={132,45,23,29,30,31,27,8,1,3};

    orden (num);
    for(int z=0;z<10;++z)
    {
        cout<<num[z]<<" ";
    }
    return 0;
}
