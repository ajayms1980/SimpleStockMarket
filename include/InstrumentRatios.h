/* 
 * File:   InstrumentRatios.h
 * Author: ajay.kumar
 *
 * Created on 11 March 2018, 22:37
 */

#ifndef INSTRUMENTRATIOS_H
#define	INSTRUMENTRATIOS_H
#include "IInstrument.h"
#include <iostream>
#include <ctime>
#include <cmath>

class InstrumentRatios : public IInstrument
{
public:
	InstrumentRatios(IRefDataService* refDataService, ITradeService* tradeDataService);
	virtual ~InstrumentRatios();

	double getDividendYield(const std::string& epic, double price);
	double getPERatio(const std::string& epic, double price);
	double getRollingVWAP(const std::string& epic, int interval);
	double getAllShareIndex(int interval);


private:
	IRefDataService*	  _refDataService;
	ITradeService*		  _tradeDataService;
	ReferenceDataMapping* _record;
	TradeRecord*		  _tradeRecord;
	RefDataMap			  _refDataCache;
	TradeRecordMap		  _tradeRecordMap;
	long long			  _currentTime;
	double			      _totalPrice;
	double				  _totalQty;
	double getCommonDividendYield(double price);
	double getPreferredDividendYield(double price);
	bool   validInputData(const std::string& epic, double price);

} ;

#endif	/* INSTRUMENTRATIOS_H */

