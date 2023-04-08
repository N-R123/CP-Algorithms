#include <bits/stdc++.h>
using namespace std;


class Person 
{      public:
	 
    int a;
    int b;
   
    Person(int x, int y): a(x), b(y)
    {   }
};

        // redefine < operator for Person class & reverse, for opposite working of max priority queue
bool operator<(const Person &p1, const Person& p2)
{   
    if(p1.a != p2.a) 
    return (p1.a > p2.a);  
    else
    return (p1.b > p2.b);
}
 
 
int main()
{ 
	int n;
	cout<<"Enter size of min priority queue: ";
	cin>>n;
 
	priority_queue<int, vector<int>, greater<int>> p;

    cout<<"Enter elements: ";
	while(n--)
	{  int x;
	   cin>>x;
	   p.push(x);	 }
 

    cout<<p.size()<<p.top()<<endl;
    cout<<"Elements of min priority queue (in sorted order): ";
    while(!p.empty())
    {  cout<<p.top()<<" ";
	   p.pop();  }
    cout<<endl<<endl; 
    
    

    priority_queue<Person> pq;
    pq.push( Person(2,55) );
    pq.push( Person(7,1) ); 
    while(!pq.empty())
    {  cout<<pq.top().a<<" "<<pq.top().b<<endl;
	   pq.pop();  }
    cout<<endl<<endl; 
}

           








