/* 
 * File:   RefrenceDataMapping.h
 * Author: ajay.kumar
 *
 * Created on 10 March 2018, 10:12
 */

#ifndef REFRENCEDATAMAPPING_H
#define	REFRENCEDATAMAPPING_H

#include <iostream>
#include "StaticData.h"

class ReferenceDataMapping
{
public:
	ReferenceDataMapping(const std::string& epic,
		DIV_TYPE type,
		double lastDividend,
		double fixedDividend,
		double parValue);

	~ReferenceDataMapping();

	inline std::string& getEpic()
	{
		return _epic;
	}

	inline DIV_TYPE getType()
	{
		return _type;
	}

	inline double getlastDividend()
	{
		return _lastDividend;
	}

	inline double getfixedDividend()
	{
		return _fixedDividend;
	}

	inline double getparValue()
	{
		return _parValue;
	}

	//	inline void setEpic(std::string epic)
	//	{
	//		_epic = epic;
	//	}
	//
	//	inline void setType(DIV_TYPE type)
	//	{
	//		_type = type;
	//	}
	//
	//	inline void setlastDividend(double lastDividend)
	//	{
	//		_lastDividend = lastDividend;
	//	}
	//
	//	inline void setfixedDividend(double fixedDividend)
	//	{
	//		_fixedDividend = fixedDividend;
	//	}
	//
	//	inline void setparValue(double parValue)
	//	{
	//		_parValue = parValue;
	//	}

private:

	std::string _epic;
	DIV_TYPE	_type;
	double 		_lastDividend;
	double 		_fixedDividend;
	double 		_parValue;
} ;


#endif	/* REFRENCEDATAMAPPING_H */

