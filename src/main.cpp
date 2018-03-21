/*
 * File:   main.cpp
 * Author: ajay.kumar
 *
 * Created on 09 March 2018, 10:43
 */

#include "InstrumentRefDataService.h"
#include "TradeService.h"
#include "StockMarketActivity.h"

int main(int argc, char** argv)
{

	//	InstrumentRefDataService* refDataService = new InstrumentRefDataService();
	//
	//
	//	refDataService->loadRefData("TEA", new ReferenceDataMapping("TEA", NS::COMMON, 0, 0, 100));
	//	refDataService->loadRefData("POP", new ReferenceDataMapping("POP", NS::COMMON, 8, 0, 100));
	//	refDataService->loadRefData("ALE", new ReferenceDataMapping("ALE", NS::COMMON, 23, 0, 60));
	//	refDataService->loadRefData("GIN", new ReferenceDataMapping("GIN", NS::PREFERRED, 8, 2, 100));
	//	refDataService->loadRefData("JOE", new ReferenceDataMapping("JOE", NS::COMMON, 13, 0, 250));

	StockMarketActivity* superSimpleStockMarket = new StockMarketActivity(new InstrumentRefDataService(), new TradeService());


	//superSimpleStockMarket->getEpicRefData("ALE");
	superSimpleStockMarket->newOrderIn("ALE", 2500, 179, NS::BUY);
	superSimpleStockMarket->newOrderIn("ALE", 200, 185, NS::SELL);
	superSimpleStockMarket->newOrderIn("ALE", 400, 164, NS::BUY);
	superSimpleStockMarket->newOrderIn("ALE", 100, 161, NS::SELL);
	superSimpleStockMarket->newOrderIn("ALE", 5000, 172, NS::BUY);
	superSimpleStockMarket->newOrderIn("ALE", 8000, 159, NS::SELL);


	superSimpleStockMarket->newOrderIn("POP", 500, 240, NS::BUY);
	superSimpleStockMarket->newOrderIn("POP", 700, 244, NS::SELL);
	superSimpleStockMarket->newOrderIn("POP", 900, 241, NS::BUY);
	superSimpleStockMarket->newOrderIn("POP", 600, 236, NS::SELL);
	superSimpleStockMarket->newOrderIn("POP", 1000, 272, NS::BUY);
	superSimpleStockMarket->newOrderIn("POP", 9000, 259, NS::SELL);

	superSimpleStockMarket->newOrderIn("GIN", 3500, 311, NS::BUY);
	superSimpleStockMarket->newOrderIn("GIN", 1000, 305, NS::SELL);
	superSimpleStockMarket->newOrderIn("GIN", 700, 326, NS::BUY);
	superSimpleStockMarket->newOrderIn("GIN", 300, 335, NS::SELL);
	superSimpleStockMarket->newOrderIn("GIN", 200, 312, NS::BUY);
	superSimpleStockMarket->newOrderIn("GIN", 80, 333, NS::SELL);

	superSimpleStockMarket->newOrderIn("JOE", 5000, 432, NS::BUY);
	superSimpleStockMarket->newOrderIn("JOE", 1000, 456, NS::SELL);
	superSimpleStockMarket->newOrderIn("JOE", 4000, 422, NS::BUY);
	superSimpleStockMarket->newOrderIn("JOE", 1000, 471, NS::SELL);
	superSimpleStockMarket->newOrderIn("JOE", 3000, 411, NS::BUY);
	superSimpleStockMarket->newOrderIn("JOE", 2000, 445, NS::SELL);

	superSimpleStockMarket->newOrderIn("TEA", 500, 11, NS::BUY);
	superSimpleStockMarket->newOrderIn("TEA", 400, 10, NS::SELL);
	superSimpleStockMarket->newOrderIn("TEA", 900, 15, NS::BUY);
	superSimpleStockMarket->newOrderIn("TEA", 10000, 9, NS::SELL);
	superSimpleStockMarket->newOrderIn("TEA", 2000, 12, NS::BUY);
	superSimpleStockMarket->newOrderIn("TEA", 8050, 11.5, NS::SELL);


	superSimpleStockMarket->getAllRefData();
	//superSimpleStockMarket->getTradeData();

	int rollingVWAPInterval = 300; //5 minutes
	superSimpleStockMarket->getInstrumentRatio("ALE", 160, rollingVWAPInterval);
	superSimpleStockMarket->getInstrumentRatio("POP", 230, rollingVWAPInterval);
	superSimpleStockMarket->getInstrumentRatio("TEA", 320, rollingVWAPInterval);
	superSimpleStockMarket->getInstrumentRatio("JOE", 450, rollingVWAPInterval);
	superSimpleStockMarket->getInstrumentRatio("GIN", 12, rollingVWAPInterval);

	std::cout << "GBCE All Share Index: " << superSimpleStockMarket->getGBCEAllShareIndex(time(NULL)) << std::endl; //time(NULL) = All Trades upto Current Time

	if (superSimpleStockMarket != NULL)
	{
		delete superSimpleStockMarket;
	}

	return 0;
}
