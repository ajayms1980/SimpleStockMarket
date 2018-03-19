/*
 * File:   main.cpp
 * Author: ajay.kumar
 *
 * Created on 09 March 2018, 10:43
 */

#include "InstrumentRefDataService.h"
#include "TradeService.h"
#include "StockMarketActivity.h"
//#include <unistd.h>

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

	//superSimpleStockMarket->getAllRefData();
	//superSimpleStockMarket->getEpicRefData("ALE");
	superSimpleStockMarket->newOrderIn("ALE", 2500, 179, NS::BUY);

	sleep(1);

	superSimpleStockMarket->newOrderIn("POP", 200, 563, NS::SELL);

	sleep(2);

	superSimpleStockMarket->newOrderIn("GIN", 400, 784, NS::SELL);

	sleep(3);

	superSimpleStockMarket->newOrderIn("ALE", 10, 162, NS::BUY);

	sleep(1);

	superSimpleStockMarket->newOrderIn("GIN", 20, 796, NS::BUY);

	//superSimpleStockMarket->getInstrumentRatio("ALE", 796);
	superSimpleStockMarket->getTradeData();
	std::cout << "GBCE All Share Index " << superSimpleStockMarket->getGBCEAllShareIndex(300) << std::endl;


	if (superSimpleStockMarket != NULL)
	{
		delete superSimpleStockMarket;
	}

	return 0;
}
