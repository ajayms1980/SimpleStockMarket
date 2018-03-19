/* 
 * File:   InstrumentRefDataService.h
 * Author: ajay.kumar
 *
 * Created on 10 March 2018, 10:18
 */

#ifndef INSTRUMENTREFDATASERVICE_H
#define	INSTRUMENTREFDATASERVICE_H

#include <iostream>
#include "IRefDataService.h"

class InstrumentRefDataService : public IRefDataService
{
public:
	InstrumentRefDataService();
	virtual ~InstrumentRefDataService();

	virtual bool recordExistsForEpic(const std::string&, ReferenceDataMapping*& record);
	virtual void loadRefData(const std::string& epic, ReferenceDataMapping* record);
	virtual void loadRefData();

	virtual void getRefData();

	inline const RefDataMap& getRefDataCache()
	{
		return _refDataCache;
	}


private:
	RefDataMap	_refDataCache;
} ;

#endif	/* INSTRUMENTREFDATASERVICE_H */

