/*
 * File:   CommonDefs.h
 * Author: ajay.kumar
 *
 * Created on 17 March 2018, 15:31
 */

#ifndef COMMONDEFS_H
#define	COMMONDEFS_H

#include <map>
#include "TradeRecord.h"
#include "RefrenceDataMapping.h"
#include <iostream>

typedef std::map<std::string, TradeRecord*> TradeRecordMap;
typedef std::map<std::string, TradeRecordMap> TradeCache;
typedef std::map<std::string, ReferenceDataMapping*> RefDataMap;

//static const char* getlocaltime(time_t now)
//{
//	static char* localtm(asctime(localtime(&now)));
//	*std::remove(localtm, localtm + strlen(localtm), '\n') = '\0';
//	return localtm;
//
//	//return localtime(&now);
//}



#endif	/* COMMONDEFS_H */

