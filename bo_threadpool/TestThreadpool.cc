 ///
 /// @file    TestThreadpool.cc
 /// @author  xiu(1107040857@qq.com)
 /// @date    2018-03-20 23:36:08
 ///

#include "Threadpool.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

class Producer{

	public:
		void getNumber(){
			::srand(::time(NULL));
			int number = ::rand() % 100;
			cout << pthread_self() << " > produce a number : " << number << endl;
			::sleep(1);
		}

};


int main(){

	wd::Threadpool threadpool(4,10);
	threadpool.start();

	int cnt = 20;
	while(cnt -- ){
		threadpool.addTask(std::bind(&Producer::getNumber,Producer()));

	}

threadpool.stop();
return 0;


}
