#include <map>
#include <iostream>

#include "StockMarketActivity.h"
#include "InstrumentRatios.h"

StockMarketActivity::StockMarketActivity(
	IRefDataService* refDataService,
	ITradeService*	 tradeService) :
		_refDataService(refDataService),
		_tradeService(tradeService),
		_instrumentService(new InstrumentRatios(refDataService, tradeService))
{
	std::cout << "StockMarketActivity: Creating StockMarketActivity" << std::endl;
}

StockMarketActivity::~StockMarketActivity()
{

	if (_instrumentService != NULL)
	{
		std::cout << "StockMarketActivity: Destroying Instrument Service" << std::endl;
		delete _instrumentService;
		_instrumentService = NULL;
	}

	if (_tradeService != NULL)
	{
		std::cout << "StockMarketActivity: Destroying Trade Service" << std::endl;
		delete _tradeService;
		_tradeService = NULL;
	}

	if (_refDataService != NULL)
	{
		std::cout << "StockMarketActivity: Destroying Reference Data Service" << std::endl;
		delete _refDataService;
		_refDataService = NULL;
	}

	std::cout << "StockMarketActivity: Destroyed  StockMarketActivity" << std::endl;
}

bool StockMarketActivity::newOrderIn(const std::string& epic,
	const double quantity,
	const double price,
	BS_IND bs_ind)
{

	ReferenceDataMapping* record;

	if (!_refDataService->recordExistsForEpic(epic, record))
	{
		std::cout << "Epic " << epic << " is not valid for order entry" << std::endl;
		return false;
	}

	if (!quantity || !price)
	{
		std::cout << "Please input valid quantity or price" << std::endl;
		return false;
	}

	_tradeService->bookTrade(epic, quantity, price, bs_ind);

	this->getInstrumentRatio(epic, price);
	return true;
}

void StockMarketActivity::getInstrumentRatio(const std::string& epic, double price)
{
	std::cout << std::endl << "Instrument Numbers:" << std::endl;
	std::cout << "Div Yield:" << _instrumentService->getDividendYield(epic, price) << std::endl;
	std::cout << "PE Ratio:" << _instrumentService->getPERatio(epic, price) << std::endl;
	std::cout << "Rolling VWAP:" << _instrumentService->getRollingVWAP(epic, price) << std::endl;
	std::cout << "Instrument Numbers End." << std::endl << std::endl;
}

void StockMarketActivity::getAllRefData()
{
	_refDataService->getRefData();
}

void StockMarketActivity::getEpicRefData(const std::string& epic)
{
	ReferenceDataMapping* record;
	_refDataService->recordExistsForEpic(epic, record);
	std::cout << "Ref Data: Epic " << record->getEpic() << " " << (int) record->getType() << " " << record->getlastDividend() << " " << record->getfixedDividend() << " " << record->getparValue() << std::endl;

	//if (record)
	//	std::cout << " Ref Data Exists for Epic " << record->getEpic() << " " << (int) record->getType() << " " << record->getlastDividend() << " " << record->getfixedDividend() << " " << record->getparValue() << std::endl;
}

void StockMarketActivity::getTradeData()
{
	std::cout << std::endl << "Printing All Trades: Start" << std::endl;
	_tradeService->getTradeData();
	std::cout << std::endl << "Printing All Trades:End" << std::endl;
}

void StockMarketActivity::getTradeData(const std::string& epic)
{
	//TODO: Make class vars
	TradeRecordMap   epicTradeCache;
	TradeRecord*	 epicTradeData;

	if (_tradeService->getTradeData(epic, epicTradeCache))
	{
		for (TradeRecordMap::const_iterator it = epicTradeCache.begin(); it != epicTradeCache.end(); ++it)
		{
			epicTradeData = it->second;
			std::cout << epicTradeData->getTradeId()
				<< " " << epicTradeData->getEpic()
				<< " " << epicTradeData->getPrice()
				<< " " << epicTradeData->getQuantity()
				<< " " << BuySell[epicTradeData->getBuySellInd()]
				<< " " << epicTradeData->getTradeTimeStamp()
				<< std::endl;
		}

	}


}

double StockMarketActivity::getGBCEAllShareIndex(int interval)
{
	return _instrumentService->getAllShareIndex(interval);
}




