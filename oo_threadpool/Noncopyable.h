 ///
 /// @file    Noncopyable.h
 /// @author  xiu(1107040857@qq.com)
 /// @date    2018-03-20 12:09:55
 ///

#ifndef _WD_NONCOPYABLE_H__
#define _WD_NONCOPYABLE_H__

namespace wd{
class Noncopyable{
protected:
	Noncopyable(){}
	~Noncopyable(){}

	Noncopyable(const Noncopyable &) = delete;
	Noncopyable & operator=(const Noncopyable &) = delete;

};
}//end of namespace wd
#endif
