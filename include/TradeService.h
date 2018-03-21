/*
 * File:   TradeService.h
 * Author: ajay.kumar
 *
 * Created on 12 March 2018, 22:28
 */

#ifndef TRADESERVICE_H
#define	TRADESERVICE_H

#include <iostream>
#include "ITradeService.h"
#include <map>
#include <sstream>

class TradeService : public ITradeService
{
public:
	TradeService();
	virtual ~TradeService();

	static int tradeIdCounter;
	void bookTrade(const std::string& epic,
		double quantity,
		double price,
		BS_IND	bs_ind);

	inline bool getTradeData(const std::string& epic, TradeRecordMap& tradeRecordMap)
	{
		TradeCache::const_iterator it = _tradeCache.find(epic);
		if (it != _tradeCache.end())
		{
			tradeRecordMap = it->second;
			return true;
		}
		return false;

	}

	virtual bool getTradeData();

private:
	TradeRecordMap _tradeRecord;
	TradeCache     _tradeCache;
	char*		   _localTime;
	void getlocaltime(time_t now);

} ;

//virtual void loadRefData(const std::string& epic, ReferenceDataMapping* record) = 0;
//
//virtual bool recordExistsForEpic(const std::string&, ReferenceDataMapping*& record) = 0;
//virtual void getRefData() = 0;







#endif	/* TRADESERVICE_H */

