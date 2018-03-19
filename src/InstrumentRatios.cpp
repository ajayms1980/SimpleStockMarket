#include <map>
#include "InstrumentRatios.h"
#include "ITradeService.h"

InstrumentRatios::InstrumentRatios(IRefDataService* refDataService, ITradeService* tradeDataService) :
		_refDataService(refDataService),
		_tradeDataService(tradeDataService),
		_record(NULL),
		_tradeRecord(NULL),
		_refDataCache(_refDataService->getRefDataCache()),
		_tradeRecordMap(), // dependent on Epic
		_currentTime(0),
		_totalPrice(0),
		_totalQty(0)
{
	std::cout << "InstrumentRatios: Creating Instrument Ratios" << std::endl;
}

InstrumentRatios::~InstrumentRatios()
{
	std::cout << "InstrumentRatios: Destroying Instrument Ratios" << std::endl;
}

double InstrumentRatios::getDividendYield(const std::string& epic, double price)
{
	if (this->validInputData(epic, price))
	{
		if (_record->getType() == NS::COMMON)
		{
			return getCommonDividendYield(price);
		}
		else
		{
			return getPreferredDividendYield(price);
		}
	}

	return 0;

}

double InstrumentRatios::getCommonDividendYield(double price)
{
	if (_record != NULL)
	{
		return (_record->getlastDividend() / price);
	}
	return 0;
}

double InstrumentRatios::getPreferredDividendYield(double price)
{
	if (_record != NULL)
	{
		return ((_record->getfixedDividend() * _record->getparValue())  / (price * 100));
	}
	return 0;
}

double InstrumentRatios::getPERatio(const std::string& epic, double price)
{
	if (this->validInputData(epic, price))
	{
		double divYield = this->getDividendYield(epic, price);

		if (divYield)
		{
			return (price / this->getDividendYield(epic, price));
		}
	}
	return 0;
}

double InstrumentRatios::getRollingVWAP(const std::string& epic, int interval)
{
	//Sum of Trade Price * Quantity / Sum Quantity
	_currentTime = static_cast<long long> (time(0));
	_totalPrice	 = 0;
	_totalQty    = 0;

	if (_tradeDataService->getTradeData(epic, _tradeRecordMap))
	{
		for (TradeRecordMap::const_iterator it = _tradeRecordMap.begin(); it != _tradeRecordMap.end(); ++it)
		{
			_tradeRecord = it->second;

			if (_tradeRecord->getTradeTimeStamp() > (_currentTime - interval))
			{
				_totalPrice += _tradeRecord->getPrice() * _tradeRecord->getQuantity();
				_totalQty += _tradeRecord->getQuantity();
			}
		}
		if (_totalQty)
		{
			return (_totalPrice / _totalQty);
		}
	}

	return 0;
}

double InstrumentRatios::getAllShareIndex(int interval)
{
	double totalVWAP = 0;

	if (_refDataCache.size())
	{
		for (RefDataMap::const_iterator it = _refDataCache.begin(); it != _refDataCache.end(); it++)
		{
			_record = it->second;

			totalVWAP += this->getRollingVWAP(_record->getEpic(), interval);

			//std::cout << record->getEpic() << " " << (int) record->getType() << " " << record->getlastDividend() << " " << record->getfixedDividend() << " " << record->getparValue() << std::endl;
		}

		if (totalVWAP)
		{
			return std::pow(totalVWAP, 1.0 / (_refDataCache.size()) );
		}

	}
	return 0;


}

bool InstrumentRatios::validInputData(const std::string& epic, double price)
{
	if (!price)
		return false;

	return _refDataService->recordExistsForEpic(epic, _record);

}

