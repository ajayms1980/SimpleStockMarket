
#include <time.h>

#include "TradeService.h"
#include <string.h>
#include <algorithm>
#include <map>

TradeService::TradeService() : _tradeRecord(), _tradeCache(), _localTime(NULL)
{
	std::cout << "TradeService: Creating TradeService" << std::endl;
}

TradeService::~TradeService()
{
	std::cout << "TradeService: Destroying Trade Service" << std::endl;

	if (_localTime != NULL)
	{
		_localTime = NULL;
	}

	for (TradeCache::const_iterator itr = _tradeCache.begin(); itr != _tradeCache.end(); ++itr)
	{
		_tradeRecord = itr->second;

		for (TradeRecordMap::const_iterator it = _tradeRecord.begin(); it != _tradeRecord.end(); ++it)
		{

			//std::cout << "Deleting Trade " << it->first << std::endl;

			delete it->second;

		}

	}
	std::cout << "TradeService: Destroyed Trade Service" << std::endl;

}

void TradeService::bookTrade(const std::string& epic,
	double quantity,
	double price,
	BS_IND	bs_ind	)
{
	//Slow
	time_t now = time(0);
	std::stringstream tradeId;
	tradeId << now << epic;

	this->getlocaltime(now);

	//_tradeCache[epic][tradeId.str()] = new TradeRecord(epic, tradeId.str(), quantity, price, bs_ind, static_cast<long long> (now));

	_tradeCache[epic].insert(std::pair<std::string, TradeRecord*>(tradeId.str(), new TradeRecord(epic, tradeId.str(), quantity, price, bs_ind, static_cast<long long> (now))  ));

	std::cout << "Trade Booked for Epic " << epic << "[" << tradeId.str() << "] [" << quantity << "@" << price << " " << BuySell[bs_ind] << "" << " ] Time [" << _localTime << "]" << std::endl;

}

bool TradeService::getTradeData()
{
	//std::cout << _tradeCache.size() << std::endl;
	for (TradeCache::const_iterator itr = _tradeCache.begin(); itr != _tradeCache.end(); ++itr)
	{
		_tradeRecord = itr->second;

		for (TradeRecordMap::const_iterator it = _tradeRecord.begin(); it != _tradeRecord.end(); ++it)
		{
			TradeRecord* record = it->second;
			this->getlocaltime(record->getTradeTimeStamp());
			std::cout << record->getEpic() << " " << record->getTradeId() << " " << BuySell[record->getBuySellInd()] << " " << record->getQuantity() << " " << record->getPrice() << " " << _localTime << std::endl;
		}

	}
	return true;
}

void TradeService::getlocaltime(time_t now)
{
	_localTime = asctime(localtime(&now));
	*std::remove(_localTime, _localTime + strlen(_localTime), '\n') = '\0';
}


//const TradeRecordMap& TradeService::getTradeData(const std::string& epic)
//{
//	TradeCache::const_iterator it = _tradeCache.find(epic);
//	if (it != _tradeCache.end())
//	{
//		return it->second;
//	}
//}

