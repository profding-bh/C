#include<time.h>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int
main()
{
   	clock_t t1 = clock();

for(int i = 0;i<10000;++i)
{
	ifstream infile("data.txt",ios::in);

	vector<int> v;
	for(int a;infile>>a;v.push_back(a))
		; 

	cout<<v.size()<<endl;

#if 0
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<' ';
	cout<<endl;
#endif
     infile.close();
 
}    
	clock_t t2 = clock();

	cout<<"TotalTime is:"<<(t2-t1)*1000/CLOCKS_PER_SEC<<"ms"<<endl;
	return 0;
}
