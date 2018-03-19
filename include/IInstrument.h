/* 
 * File:   IInstrument.h
 * Author: ajay.kumar
 *
 * Created on 11 March 2018, 22:39
 */

#ifndef IINSTRUMENT_H
#define	IINSTRUMENT_H

#include "CommonDefs.h"
#include "IRefDataService.h"
#include "ITradeService.h"

class IInstrument
{
public:
	IInstrument();
	virtual ~IInstrument();

	virtual double getAllShareIndex(int interval) = 0;
	virtual double getDividendYield(const std::string& epic, double price) = 0;
	virtual double getPERatio(const std::string& epic, double price) = 0;
	virtual double getRollingVWAP(const std::string& epic, int interval) = 0;
} ;


#endif	/* IINSTRUMENT_H */

