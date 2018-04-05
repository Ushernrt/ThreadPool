 ///
 /// @file    Thread.cc
 /// @author  xiu(1107040857@qq.com)
 /// @date    2018-03-20 19:41:06
 ///

#include "Thread.h"
#include <iostream>

using std::cout;
using std::endl;

namespace wd{

	Thread::Thread()
	: _pthId(0)
	, _isRunning(false)
	{
	}

	void Thread::start(){
		pthread_create(&_pthId, NULL, threadFunc, this);
		_isRunning = true;
	}
	
	void * Thread::threadFunc(void * arg){
		Thread * pThread = static_cast<Thread *>(arg);
		if(pThread)
			pThread->run();

		return NULL;
	}

	void Thread::join(){
		pthread_join(_pthId, NULL);
		_isRunning = false;
	}

	Thread::~Thread(){
		if(_isRunning)
		{
			pthread_detach(_pthId);
			_isRunning = false;
		}

	}


}// end of namespace wd


