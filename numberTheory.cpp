#include<bits/stdc++.h>
using namespace std;


typedef long long ll;


int findPowerModulo(int x, int n, int m)
{
	if(x==0 || m==1)
	return 0;
	else if(n==0)
	return 1;
	 
	long r, t = findPowerModulo(x, n/2, m);
	 
	if(n%2 == 0)     
    r = (t*t)%m;
    else 
	r = ((t*t)%m * x%m)%m;         
	
	return (r+m)%m;                                            
}


ll findFactorialModulo(ll n, ll p)
{
    ll r = 1;
    
    for(ll i=n+1; i<=p-1; i++)                       // Wilson's Theorem
    {
        ll t = findPowerModulo(i, p-2, p);           // Fermat's Little Theorem
        r = (r*t)%p;
    }
    
    r *= -1;
    r += p;
    
    return r;
}



#define MAX 500001                // 1 <= N <= 500000
#define m 1000000007
#define pb push_back

typedef long long ll;

vector<int> sieveStoringPrimes()
{
	bool isPrime[MAX];

	vector<int> prime;
	for(int i=2; i<MAX; i++)
	isPrime[i] = true;
	
	for(int i=2; i*i<MAX; i++)
	{ 
		if(isPrime[i])
		{
			for(int j=i*i; j<MAX; j+=i)
			isPrime[j] = false;
		}
	}

	prime.pb(2);
	for(int i=3; i<MAX; i+=2)
	{
		if(isPrime[i])
		prime.pb(i);
	}
	
	return prime; 
}

ll countDivisorsOf_n_Factorial(int n, vector<int> &prime)
{
	ll c = 1;
	
	for(int i=0; prime[i]<=n; i++)
	{
		ll a=0, p=prime[i]; 
		
		while((n/p) != 0)                      // calculating a (power of prime[i] in n!) 
		{
			a = (a%m + (n/p)%m)%m;             
			p = p*prime[i];
		}
		
		c = (c%m * (a+1)%m)%m;                 // multiply the diviser contribution factor due to the current prime 
	}
	
	return c;
}


typedef long long ll;

  // SOE = Sieve of Eratosthenes, ETF = Euler Totient Function 

ll countCoprimesOf_n_using_ETFconcept_and_SOEconcept(ll n)             // { O(nlog(logn)) }
{ 
	bool isPrime[n+1];            
	for(int i=0; i<n+1; i++)              
	isPrime[i] = true;
		
		
	isPrime[0] = false;                   
	isPrime[1] = false;          
	for(int i=2; i<sqrt(n+1); i++)          
	{
		if(isPrime[i] == true)          
		{
			for(int j=(i*i); j<n+1; j+=i)    
			isPrime[j] = false; 
		}
	}


	ll r = n;
	for(int i=0; i<n+1; i++)
	{	
	    if(isPrime[i]==true && r%i==0)      // multiply the contributions of all prime divisor (i) 
		r = (r*(i-1))/i; 
    }
    
	return r; 
}


ll countCoprimesOf_n_using_ETFconcept_and_PrimeCheckconcept(ll n)  // { O(Vn) }
{ 
	ll c=n, i=n;
	
	for(int j=2; j<=sqrt(i+1); j++)
	{
		if(i%j == 0)                                               // j is prime factor of i
		{
			c = (c*(j-1))/j;                                       // multiply the contribution of prime j 
			
			while(i%j == 0)                                        // remove all powers of prime j from i
			i /= j; 
		}
	}
	
	if(i > 1)
    c = (c*(i-1))/i;
    
	return c;
}

 
int moduloOfPower_iterative(int x, int n, int m)
{
	if(x==0 || m==1)
	return 0;
	else if(n==0)
	return 1;
	
	
	long t=x%m, r=1;
	
	while(n != 0)
	{ 
		if(n&1 == 1) 
		r = (r*t)%m; 
		
		n = n>>1;           // or n = n/2 or right shift
		t = (t*t)%m;        // t = a^i
	}
	 
	return (r+m)%m;         // return positive (int) value of r [r can be negative in (x<0) case]                                            
} 

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        ll n, p;
        cin>>n>>p;
        
        if(n >= p)
        cout<<0<<endl;
        else
        cout<<findFactorialModulo(n,p)<<endl; 
    } 
}


// total ways to generate d using a and b

#include<bits/stdc++.h> 
using namespace std;


typedef long long ll;


class Triplet
{      public:
	ll x;
	ll y;
	ll gcd;
};


Triplet extendedEuclidAlgorithm(ll a, ll b)
{ 
	if(b==0)
	{	Triplet r;
		r.x = 1;
		r.y = 0;
		r.gcd = a;
		return r;	}
		
		
	Triplet t = extendedEuclidAlgorithm(b, a%b);
 

	Triplet r;
	r.gcd = t.gcd;
	r.x = t.y;
	r.y = t.x - (a/b)*t.y;
	return r;	
}

 
ll pmmi(ll a, ll m)         // positive Multiplicative Modulo Inverse i.e. positive (1/a)%m
{
    ll x = extendedEuclidAlgorithm(a, m).x;
    
    ll r = (x%m + m)%m;     // making Multiplicative Modulo Inverse positive
    return r;
}


int main()
{ 
	int t;
	cin>>t;
	
	while(t--)
	{
		ll a, b, d;               // finding count of all (x,y) in (ax + by = d)                    
		cin>>a>>b>>d;
		
        if(d == 0)
		{	cout<<1<<endl;
			continue;	}
		
		
		ll gcd = __gcd(a,b);         
 
		if(d%gcd != 0)            // Non Diophantine Equation so no solution                                  
		{	cout<<0<<endl;
			continue;	}
		else if(d%gcd == 0)       // Diophantine Equation (all are divisible by gcd so simplify the equation)
		{	a /= gcd;
		    b /= gcd;
		    d /= gcd;	}
  
  
		ll y1 = ((d%a) * pmmi(b,a))%a;      // min value of y
		ll n = (d/b - y1)/a;                // no of values of y other than y1 

		if((d/b - y1) < 0)
		cout << 0 <<endl;
		else
	 	cout << n+1 <<endl; 
	} 
}










