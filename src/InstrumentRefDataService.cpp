

#include "InstrumentRefDataService.h"

InstrumentRefDataService::InstrumentRefDataService()
{
	std::cout << "InstrumentRefDataService: Creating Instrument RefDataCache" << std::endl;
	this->loadRefData();
}

InstrumentRefDataService::~InstrumentRefDataService()
{
	std::cout << "InstrumentRefDataService: Destroying Instrument RefDataCache" << std::endl;

	for (RefDataMap::const_iterator it = _refDataCache.begin(); it != _refDataCache.end(); it++)
	{
		//std::cout << "Deleting Ref Data for Epic " << it->first << std::endl;
		delete it->second;
	}
	std::cout << "InstrumentRefDataService: Destroyed Instrument RefDataCache" << std::endl;

}

void InstrumentRefDataService::loadRefData(const std::string& epic, ReferenceDataMapping* record)
{
	_refDataCache.insert(std::pair<std::string, ReferenceDataMapping*>(epic, record));
}

void InstrumentRefDataService::loadRefData()
{
	std::cout << "Loading Reference Data......" << std::endl;
	_refDataCache.insert(std::pair<std::string, ReferenceDataMapping*>("TEA", new ReferenceDataMapping("TEA", NS::COMMON, 0, 0, 100)));
	_refDataCache.insert(std::pair<std::string, ReferenceDataMapping*>("POP", new ReferenceDataMapping("POP", NS::COMMON, 8, 0, 100)));
	_refDataCache.insert(std::pair<std::string, ReferenceDataMapping*>("ALE", new ReferenceDataMapping("ALE", NS::COMMON, 23, 0, 60)));
	_refDataCache.insert(std::pair<std::string, ReferenceDataMapping*>("GIN", new ReferenceDataMapping("GIN", NS::PREFERRED, 8, 2, 100)));
	_refDataCache.insert(std::pair<std::string, ReferenceDataMapping*>("JOE", new ReferenceDataMapping("JOE", NS::COMMON, 13, 0, 250)));
}

bool InstrumentRefDataService::recordExistsForEpic(const std::string& epic, ReferenceDataMapping*& record)
{
	RefDataMap::const_iterator it = _refDataCache.find(epic);

	if (it == _refDataCache.end())
	{
		return false;
	}

	record = it->second;

	//std::cout << " Ref Data Exists for Epic " << record->getEpic() << " " << (int) record->getType() << " " << record->getlastDividend() << " " << record->getfixedDividend() << " " << record->getparValue() << std::endl;

	return true;

}

void InstrumentRefDataService::getRefData()
{
	for (RefDataMap::const_iterator it = _refDataCache.begin(); it != _refDataCache.end(); it++)
	{
		ReferenceDataMapping* record = it->second;
		std::cout << "RefData: Epic " << record->getEpic() << " " << (int) record->getType() << " " << record->getlastDividend() << " " << record->getfixedDividend() << " " << record->getparValue() << std::endl;
	}
}


