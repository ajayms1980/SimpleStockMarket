/*
 * File:   StaticData.h
 * Author: ajay.kumar
 *
 * Created on 12 March 2018, 22:44
 */

#ifndef STATICDATA_H
#define	STATICDATA_H

#include <iostream>

namespace NS {

enum BUY_SELL
{
	BUY ,
	SELL
} ;

enum DIV_TYPES
{
	COMMON,
	PREFERRED
} ;
}

static const char * const BuySell[] = {
	"Buy",
	"Sell"
};

static const char * const DivTypes[] = {
	"Common",
	"Preferred"
};


typedef NS::BUY_SELL BS_IND;
typedef NS::DIV_TYPES DIV_TYPE;


#endif	/* STATICDATA_H */

