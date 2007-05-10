#ifndef DEBUG_H
#define DEBUG_H
//#define TEST

#include <assert.h>

#ifdef _DEBUG
	#include <iostream>
	using std::cout;
	using std::endl;
	using std::cin;
	
	#define READ(I) cin>>I;
	#define PAUSE cin.get();

	#define PRINT(T) cout<<T;
	#define PRINTL(L) cout<<L<<endl;
	#define REDUCE(R) cout<<"Reduz "<<R<<endl;
#else
	#define READ(I) ;
	#define PAUSE ;

	#define PRINT(T) ;
	#define PRINTL(L) ;
	#define REDUCE(R) ;
	
	//#define NDEBUG //To turn off assertions
#endif

#endif //DEBUG_H
