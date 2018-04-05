 ///
 /// @file    Noncopyable.h
 /// @author  xiu(1107040857@qq.com)
 /// @date    2018-03-20 21:27:22
 ///

#ifndef __WD_NONCOPYABLE_H__
#define __WD_NONCOPYABLE_H__

namespace wd{

class Noncopyable{
	protected:
		Noncopyable(){}
		~Noncopyable(){}

		//禁止复制
		Noncopyable(const Noncopyable &) = delete;
		Noncopyable & operator=(const Noncopyable &) = delete;
};

}// end of namespace wd

#endif

