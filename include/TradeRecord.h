/*
 * File:   TradeRecord.h
 * Author: ajay.kumar
 *
 * Created on 11 March 2018, 08:34
 */

#ifndef TRADERECORD_H
#define	TRADERECORD_H

#include <iostream>
#include "StaticData.h"

class TradeRecord
{
public:

	TradeRecord(const std::string& epic,
		const std::string& tradeId,
		double quantity,
		double price,
		BS_IND	bs_ind,
		long long tradeTimeStamp);
	~TradeRecord();

	inline std::string& getEpic()
	{
		return _epic;
	}

	inline std::string& getTradeId()
	{
		return _tradeId;
	}

	inline double getQuantity()
	{
		return _quantity;
	}

	inline double getPrice()
	{
		return _price;
	}

	inline BS_IND getBuySellInd()
	{
		return _bs_ind;
	}

	inline long long getTradeTimeStamp()
	{
		return _tradeTimeStamp;
	}

	//	inline void setEpic(std::string& epic)
	//	{
	//		_epic = epic;
	//	}
	//
	//	inline void setTradeId(std::string& tradeId)
	//	{
	//		_tradeId = tradeId;
	//	}
	//
	//	inline void setQuantity(double quantity)
	//	{
	//		_quantity = quantity;
	//	}
	//
	//	inline void setPrice(double price)
	//	{
	//		_price = price;
	//	}
	//
	//	inline void setBuySellInd(BS_IND bs_ind)
	//	{
	//		_bs_ind = bs_ind;
	//	}
	//
	//	inline void setTradeTimeStamp(long long tradeTimeStamp)
	//	{
	//		_tradeTimeStamp = tradeTimeStamp;
	//	}


private:
	std::string _epic;
	std::string _tradeId;
	double		_quantity;
	double		_price;
	BS_IND		_bs_ind;
	long long	_tradeTimeStamp;

} ;


#endif	/* TRADERECORD_H */


