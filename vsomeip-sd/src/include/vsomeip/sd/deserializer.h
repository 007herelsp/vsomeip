//
// deserializer.h
//
// Date: 	Nov 5, 2013
// Author: 	Lutz Bichler
//
// This file is part of the BMW Some/IP implementation.
//
// Copyright © 2013 Bayerische Motoren Werke AG (BMW). 
// All rights reserved.
//

#ifndef __VSOMEIP_SD_DESERIALIZER_H__
#define __VSOMEIP_SD_DESERIALIZER_H__

#include <vsomeip/deserializer.h>

namespace vsomeip {

namespace sd {

class Entry;
class Option;

class Deserializer : virtual public vsomeip::Deserializer {
public:
	virtual ~Deserializer() {};

	virtual Entry * deserializeEntry() = 0;
	virtual Option * deserializeOption() = 0;
};

} // namespace sd

} // namespace vsomeip

#endif // __VSOMEIP_SD_DESERIALIZER_H__
