#include<iostream>
#include<map>

using namespace std ;

// map 
int
main()
{
    int n;
    while(cin>>n)
     {
        map<int,int> m;
        while(n--)
        {
            int key,value;
            cin>>key>>value;
            if(!m[key]){ // m[key] == 0 ? 表示不存在，如果值就是为0呢？可以直接赋值。
                m[key]= value;
            }else
                m[key] += value; 
        }
       // 输出map
       for(map<int,int>::iterator it=m.begin(); it != m.end();++it)
                cout<<it->first<<' '<<it->second<<endl;
        
    }
    return 0;
}
