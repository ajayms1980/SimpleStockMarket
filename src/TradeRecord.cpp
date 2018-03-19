#include "TradeRecord.h"

TradeRecord::TradeRecord(const std::string& epic,
	const std::string& tradeId,
	double quantity,
	double price,
	BS_IND	bs_ind,
	long long tradeTimeStamp) : _epic(epic), _tradeId(tradeId), _quantity(quantity), _price(price), _bs_ind(bs_ind),  _tradeTimeStamp(tradeTimeStamp)
{

}

TradeRecord::~TradeRecord()
{

}
