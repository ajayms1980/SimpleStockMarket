/*
 * File:   ITradeService.h
 * Author: ajay.kumar
 *
 * Created on 12 March 2018, 22:00
 */

#ifndef ITRADESERVICE_H
#define	ITRADESERVICE_H

#include <iostream>
#include "CommonDefs.h"
#include <ctime>

class ITradeService
{
public:
	//	typedef std::map<std::string, TradeRecord*> TradeRecordMap;
	//	typedef std::map<std::string, TradeRecordMap> TradeCache;

	ITradeService();
	virtual ~ITradeService();
	virtual void bookTrade(const std::string& epic,
		double quantity,
		double price,
		BS_IND	bs_ind) = 0;

	virtual bool getTradeData(const std::string& epic, TradeRecordMap& tradeRecordMap) = 0;

	virtual bool getTradeData() = 0;

} ;

#endif	/* ITRADESERVICE_H */

