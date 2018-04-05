 ///
 /// @file    Thread.cc
 /// @author  xiu(1107040857@qq.com)
 /// @date    2018-03-20 22:18:56
 ///

#include "Thread.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd{

	Thread::Thread(ThreadCallback cb)
	: _pthId(0)
	, _isRunning(false)
	, _cb(cb)
	{
	}

	void Thread::start()
	{
		pthread_create(&_pthId, NULL, threadFunc, this);
	}

	void * Thread::threadFunc(void * arg){
		Thread * pThread = static_cast<Thread*>(arg);
		if(pThread)
			pThread->_cb();

		return NULL;
	}

	void Thread::join(){
		pthread_join(_pthId, NULL);
		_isRunning = false;
	}

	Thread::~Thread(){
		if(_isRunning){
			pthread_detach(_pthId);
			_isRunning = false;
		}

		cout << "~Thread()" << endl;

	}

}//end of namespace wd









