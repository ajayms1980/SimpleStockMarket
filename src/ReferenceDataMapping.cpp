#include "RefrenceDataMapping.h"

ReferenceDataMapping::ReferenceDataMapping (const std::string& epic,
	DIV_TYPE type,
	double lastDividend,
	double fixedDividend,
	double parValue) :
		_epic(epic),
		_type(type),
		_lastDividend(lastDividend),
		_fixedDividend(fixedDividend),
		_parValue(parValue)
{
	//std::cout << "Creating RefData for Epic" << _epic << std::endl;
}

ReferenceDataMapping::~ReferenceDataMapping()
{
}

