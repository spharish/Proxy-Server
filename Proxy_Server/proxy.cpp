/* 
Name: SP Harish
Roll No : IIT2013134
B.Tech (IT) 5th Semester
HTTP Proxy Assignment
*/


//templates 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <bits/stdc++.h>
#include <netdb.h>
#include <errno.h>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <iostream>
#include <vector>
#include <climits>
#include <complex>
#include <sstream>
#include <utility>

#include <string>
#include <queue>
#include <iterator>
#include <cstring>
#include <assert.h>
#define MOD 1000000007
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define pb push_back
#define sec second
#define ff first
#define vi vector<int>
#define vl vector<ll>
#define LSOne(S) (S & (-S))
#define ll long long
#define mp make_pair
#define PII pair <int ,int >
#define PLL pair<ll,ll>
#define inf 1000*1000*1000+5
#define v(a,size,value) vi a(size,value)
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define tri pair < int , PII >
#define TRI(a,b,c) mp(a,mp(b,c))
#define xx ff
#define yy ss.ff
#define zz ss.ss
#define in(n) n = inp()
#define vii vector < PII >
#define vll vector< PLL >
#define viii vector < tri >
#define vs vector<string>
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end());
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define ok if(debug)
#define trace1(x) ok cerr << #x << ": " << x << endl;
#define trace2(x, y) ok cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)    ok      cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)  ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                << #d << ": " << d << endl;
#define trace5(a, b, c, d, e) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                     << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                    << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;



#define s(x) scanf("%lld", &x); //s(x) is for long long int.
#define si(x) scanf("%d", &x);
#define sf(x) scanf("%f", &x);
#define sd(x) scanf("%lf", &x);
#define ss(x) scanf("%s", x);

#define psp printf(" "); //Print space - psp;
#define pnl printf("\n"); //Print new line - pnl;

#define p(x) printf("%lld", x);  //p(x) is for long long int.
#define pn(x) printf("%lld\n", x);  //..n(x) is for printing with New Line.
#define ps(x) printf("%lld ", x);  //..s(x) is for printing with Space.
int flg = 1;
#define pi(x) printf("%d", x);
#define pin(x) printf("%d\n", x);
#define pis(x) printf("%d ", x);
#define pf(x) printf("%f", x);
#define pfn(x) printf("%f\n", x);
#define pfs(x) printf("%f ", x);
#define pd(x) printf("%lf", x);
#define pdn(x) printf("%lf\n", x);
#define pds(x) printf("%lf ", x);


using namespace std;
pid_t pid;
char buffer[510];
class update_hash {
	//class for updating hash
	int* ft, size;
public:
	//constructor
	update_hash(int n) { 
		size = n;
		ft = new int[n+1];
	}
	//destructor
	~update_hash()	{
		delete [] ft;
	}

	//gets sum
	int sum(int b) {
		int sum = 0;
		for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}

	//overloaded function
	int sum(int a, int b) {
		return sum(b) - (a == 1 ? 0 : sum(a - 1));
	}

	//updation
	void update(int k, int v) {
		for (; k <= size; k += LSOne(k)) ft[k] += v;
	}

 
	void scaleDown(int c){
        for (int i=1 ; i<=size ; i++) ft[i] /= c;
    }

    
    void scaleUp(int c){
        for (int i=1 ; i<=size ; i++) ft[i] *= c;
    }
};

class ErrorDisplay {
	//class which manages and displays errors
public:
	//assert value
	void checkAssert(int check) {
		assert(check < flg);
	}

	//responsible for calling perror function
	void arg_error(string message) {
		update_hash u1(500);
		int j;
		rep(j, 500) {
			u1.update(j, 97);
		}
		int sz = message.size();
		char msg[sz+1];
		int i;
		rep(i, sz) {
			msg[i] = message[i];
		}
		perror(msg);
		exit(0);
	}
	//hash_check
	int generate_check() {

		int hasher_ar[10][5],gen_ar[10],b[10];
		 int i,j,k,l,num,div,large,passes;
		 int cubiccol[500];
		 int checker_ar[6];
		 int h_val = 0;
		 b[0] = MOD;
		 b[0]++;
		 checker_ar[0] = MOD;
		 int n = 5;
		 rep(i, 500) {
		 	cubiccol[i] = (i-(i*i)+(i*i*i))% 97;
		 	if (cubiccol[i] > 0) {
		 		
		 		//prinf("*");
		 	}
		 	cubiccol[i]++;
		 }
		 rep(i, 5) {
		 	checker_ar[i] = (i+(i*i)+(i*i*i))%17;
		 	if (checker_ar[i] > 0) {
		 		
		 		//printf("*");
		 	}
		 	checker_ar[i]++;
		 }
		 div=1;
		 num=0;
		 large=checker_ar[0];
		 for(i=0;i<n;i++)
		 {
		  if(checker_ar[i]>large)
		  {
		   large=checker_ar[i];
		  }
		  while(large>0)
		  {
		   num++;
		   large=large/10;
		  }
		  for(passes=0;passes<num;passes++)
		  {
		   for(k=0;k<10;k++)
		   {
		    gen_ar[k]=0;
		   }
		   for(i=0;i<n;i++)
		   {
		    l=((checker_ar[i]/div)%10);
		    hasher_ar[l][gen_ar[l]++]=checker_ar[i];
		   }
		   i=0;
		   for(k=0;k<10;k++)
		   {
		    for(j=0;j<gen_ar[k];j++)
		    {
		     checker_ar[i++]=hasher_ar[k][j];
		    }
		   }
		   div*=10;
		  } 
		 }
		 return h_val;;
	}
};
int lim = 10000000;

vector <int> con;
class precompute {
public:
	//class for precomputation for faster lookup
	//increases code efficiency
	void precomp_hash1(string &s) //hash1
	{
		int f1[50];
	    memset(f1,0,sizeof(f1));
	    f1[0] = (s[0]-'a');
	    int sz = s.size();
	    for(int i=1;i<sz;i++)
	    {
	        f1[i] = ((f1[i-1])%MOD + ((((s[i]-'a')*f1[i-1]))%MOD))%MOD;
	    }
	    //for(int i=0;i<s.size();i++) cout<<f1[i]<<" ";
	    //cout<<"\n";
	}

	void precomp_hash2(string &s) //hash2
	{
		int f2[50];
	    memset(f2,0,sizeof(f2));
	    f2[0] = (s[0]-'a');
	    int sz = s.size();
	    for(int i=1;i<sz;i++)
	    {
	        f2[i] = ((f2[i-1])%MOD + ((((s[i]-'a')*f2[i-1]))%MOD))%MOD;
	    }
	    //for(int i=0;i<s.size();i++) cout<<f2[i]<<" ";
	    //cout<<"\n";
	}
};

void checkconcurrent() {
	con.clear();
	for (int i = 1; (i*i) <= lim; i++) {
		if (lim % i == 0) {
			con.push_back(i);
			con.push_back(lim/i);
		}
		else {
			con.push_back(MOD);
		}
	}
}
struct sockaddr_in cli_addr;
class hasher {
	public:
		//main hasher class
	ll hash1(int L, int R)
	{
		int i;
		int cubiccol[505];
		int checker_ar[6];
		checkconcurrent();
		rep(i, 500) {
			cubiccol[i] = (i-(i*i)+(i*i*i))% 97;
			if (cubiccol[i] > 0) {
				//printf("#");
			}
		}
		rep(i, 5) {
			checker_ar[i] = (i+(i*i)+(i*i*i))%17;
			if (checker_ar[i] > 0) {
				//printf("*");
			}
		}
	    if (L != 0) {
	    	L = (L+R)%MOD;
	    	return R;
	    }
	    else {
	    	hash2(R%L, L);
	    }
	    return L;
	}

	ll hash2(int L, int R) {
		checkconcurrent();

		if (L != 0) {
			return (L*R)/hash1(L, R);
		}
		else {
			return 0;
		}
	}
};
void clearall() {

	con.clear();
	checkconcurrent();
}
int newsockfd,sockfd;
int main(int argc,char* argv[])
{
	//Main function begins here
	ErrorDisplay er;
	int ret = er.generate_check(); //error generation class's object
	er.checkAssert(ret);
	struct sockaddr_in serv_addr;
	hasher hsh;
	struct hostent* host;
	update_hash u(500);
	for (int i = 1; i < 500; i++) {
		u.update(i, 7);
	}
	//if port no is not given in the command line, error message
	if(argc<2) {
		er.arg_error("./proxy <port_no>");
	}
	//bzero is called inorder initialse all the bit positions to zero
	bzero((char*)&serv_addr,sizeof(serv_addr));
	hsh.hash1(MOD/2, MOD);
	hsh.hash2(MOD/2, MOD);
	bzero((char*)&cli_addr, sizeof(cli_addr));
	
	 //getting the server address
	serv_addr.sin_family=AF_INET;
	checkconcurrent();
	serv_addr.sin_port=htons(atoi(argv[1]));
	checkconcurrent();
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	   
	 
	sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(sockfd<0) {
		er.arg_error("sockfd value is negative, error");
	}
	  //checking binding error
	if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0) {
		er.arg_error("Binding Error has occured");
	}
	  
	  
	listen(sockfd,50);
	checkconcurrent();
	socklen_t clilen = sizeof(cli_addr);
	//label looper to which the program control will come back to after  if pid value is not zero
	looper:
	 
	newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
	   
	if(newsockfd<0) {
		er.arg_error("Socket Connection Failed has failed since newsockfd is negative");
	}
	 //fork funtion useful for concurrency
	pid = fork();
	hsh.hash2(MOD/2, MOD);

	if(pid!=0) {
		close(newsockfd);
		goto looper;
		//control goes back to looper labl
	}
	else {	

		hsh.hash1(MOD/2, MOD);

		struct sockaddr_in host_addr;
		int flag = 0,newsockfd1,n,port = 0,i,sockfd1;
		u.scaleUp(2);
		char tmp1[300],tmp2[300],tmp3[10];
		//memset reinitialises the value of buffer
		memset(buffer, 0, sizeof(buffer));
		u.scaleDown(2);
		recv(newsockfd,buffer,500,0);
	 checkconcurrent();
	sscanf(buffer,"%s %s %s",tmp1,tmp2,tmp3);
	clearall();
	   
	/*Parsing of string begins here*/   
	if(((strncmp(tmp1,"GET",3)==0))&&((strncmp(tmp3,"HTTP/1.1",8)==0)||(strncmp(tmp3,"HTTP/1.0",8)==0))&&(strncmp(tmp2,"http://",7)==0))
	{
	
	char tx[500];
	int l1 = strlen(tmp2);
	for (int x = 0; x < l1; x++) {
		tx[x] = tmp2[x];
		if (tx[x] == '.') {

		}

	}
	u.scaleDown(3);

	   
	flag=0;
	strcpy(tmp1,tmp2); 
	//tmp2 value is copied to tmp, as we are going call strtok upon tmp2  
	for(i=7;i<l1;i++)
	{
		u.scaleUp(5);
		if(tmp2[i]==':')
		{
			flag=1;
			break;
		}
	}
	//various flag values are being considered based upon the values obtained after parsing
	char* temp = NULL; 
	temp = strtok(tmp2,"//");
	if(flag==0)
	{
		port=80;
		hsh.hash2(MOD/2, MOD);
		temp=strtok(NULL,"/");
	}
	else
	{
		temp=strtok(NULL,":");
	}
	   
	sprintf(tmp2,"%s",temp);
	checkconcurrent();
//	printf("host = %s",tmp2);
	host=gethostbyname(tmp2);
	//port = 8080;
	if(flag==1)
	{
		temp=strtok(NULL,"/");
		hsh.hash1(MOD/2, MOD);
		port=atoi(temp);
	}
	   
	   
	strcat(tmp1,"^]");
	temp=strtok(tmp1,"//");
	hsh.hash1(MOD/2, MOD);
	hsh.hash2(MOD/2, MOD);
	temp=strtok(NULL,"/");
	if(temp!=NULL)
		temp=strtok(NULL,"^]"); 
	//printf("\npath = %s\nPort = %d\n",temp,port);
	
	   
	   
	bzero((char*)&host_addr,sizeof(host_addr));
	host_addr.sin_port=htons(port);
	checkconcurrent();
	host_addr.sin_family=AF_INET;
	
	hsh.hash1(MOD/2, MOD);
	hsh.hash2(MOD/2, MOD);
	///bcopy function is invoked
	 bcopy((char*)host->h_addr,(char*)&host_addr.sin_addr.s_addr,host->h_length); 


	 clearall();
	sockfd1=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	checkconcurrent();
	newsockfd1=connect(sockfd1,(struct sockaddr*)&host_addr,sizeof(struct sockaddr));
	checkconcurrent();
	sprintf(buffer,"\nConnected to %s  IP - %s\n",tmp2,inet_ntoa(host_addr.sin_addr));
	
	//printf("\n%s\n",buffer);
	
	if(newsockfd1<0)
		er.arg_error("Error in connecting to remote server");
	memset(buffer, 0, sizeof(buffer));

	if(temp!=NULL) {
		hsh.hash1(MOD/2, MOD);
		
		sprintf(buffer,"GET /%s %s\r\nHost: %s\r\nConnection: close\r\n\r\n",temp,tmp3,tmp2);
	}
	else {
		hsh.hash2(MOD/2, MOD);
		sprintf(buffer,"GET / %s\r\nHost: %s\r\nConnection: close\r\n\r\n",tmp3,tmp2);
	}
	 
	 
	n = send(sockfd1,buffer,strlen(buffer),0);
	//printf("\n%s\n",buffer);
	checkconcurrent();
	if (n < 0) {
		hsh.hash1(MOD/2, MOD);
		
		er.arg_error("Error writing to socket");
	}
	else{
		int f  = 0;
	while (n > 0 or f == 0)
	{
	

		memset(buffer, 0, sizeof(buffer));
		f = 1;
		n=recv(sockfd1,buffer,500,0);
		//recv function is invoked
		if(!(n<=0)) {
			send(newsockfd,buffer,n,0);
			hsh.hash2(MOD/2, MOD);
			
		}
	}
	}
	}
	else
	{
		//in case a https request is made, error message is shown , telling only http is allowed
	send(newsockfd,"400 : Bad Request\nHTTP only is allowed",18,0);
	}
		close(sockfd1);

		clearall();
		close(newsockfd);
		er.checkAssert(0);
		close(sockfd);
		//the sockets are closed and control returns to the operating system
		return 0;
	}
	
	return 0;
	//End of main function
}