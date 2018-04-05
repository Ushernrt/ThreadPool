 ///
 /// @file    Thread.h
 /// @author  xiu(1107040857@qq.com)
 /// @date    2018-03-20 22:11:26
 ///
 
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>
#include <functional>

namespace wd{

class Thread
: Noncopyable
{
	using ThreadCallback = std::function<void()>;
	public:
		Thread(ThreadCallback);
		~Thread();

		void start();
		void join();
	private:
		static void * threadFunc(void * arg);

	private:
		pthread_t _pthId;
		bool _isRunning;
		ThreadCallback _cb;

};



}//end of namespace wd

#endif

