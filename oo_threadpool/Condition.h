 ///
 /// @file    Condition.h
 /// @author  xiu(1107040857@qq.com)
 /// @date    2018-03-20 17:40:30
 ///

#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__

#include <pthread.h>

namespace wd{

class MutexLock;

class Condition
{
	public:
		Condition(MutexLock &);
		~Condition();

		void wait();
		void notify();
		void notifyall();

	private:
		pthread_cond_t _cond;
		MutexLock & _mutex;

};


}

#endif
