/* 
 * File:   IRefDataService.h
 * Author: ajay.kumar
 *
 * Created on 10 March 2018, 10:15
 */


#ifndef IREFDATASERVICE_H
#define	IREFDATASERVICE_H

#include <iostream>
#include "CommonDefs.h"
#include "RefrenceDataMapping.h"

class IRefDataService
{
public:
	IRefDataService();
	virtual ~IRefDataService();

	//typedef std::map<std::string, ReferenceDataMapping*> RefDataMap;

	virtual void loadRefData(const std::string& epic, ReferenceDataMapping* record) = 0;
	virtual void loadRefData() = 0;

	virtual bool recordExistsForEpic(const std::string&, ReferenceDataMapping*& record) = 0;
	virtual void getRefData() = 0;

	virtual const RefDataMap& getRefDataCache() = 0;
} ;

#endif	/* IREFDATASERVICE_H */
