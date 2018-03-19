/* 
 * File:   StockMarketActivity.h
 * Author: ajay.kumar
 *
 * Created on 12 March 2018, 21:55
 */

#ifndef STOCKMARKETACTIVITY_H
#define	STOCKMARKETACTIVITY_H

#include "IRefDataService.h"
#include "ITradeService.h"
#include "IInstrument.h"
#include <iostream>

class StockMarketActivity
{
public:
	StockMarketActivity(
		IRefDataService* _refDataService,
		ITradeService*	 _tradeService);

	~StockMarketActivity();

	bool newOrderIn(const std::string& epic,
		double quantity,
		double price,
		BS_IND bs_ind);

	double getGBCEAllShareIndex(int interval);
	void getEpicRefData(const std::string& epic);
	void getInstrumentRatio(const std::string& epic, double price);
	void getAllRefData();
	void getTradeData();
	void getTradeData(const std::string& epic);

private:
	IRefDataService* _refDataService;
	ITradeService*	 _tradeService;
	IInstrument*	 _instrumentService;



} ;



#endif	/* STOCKMARKETACTIVITY_H */

