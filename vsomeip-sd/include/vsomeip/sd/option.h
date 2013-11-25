//
// option.h
//
// Date: 	Oct 31, 2013
// Author: 	Lutz Bichler
//
// This file is part of the BMW Some/IP implementation.
//
// Copyright © 2013 Bayerische Motoren Werke AG (BMW). 
// All rights reserved.
//

#ifndef __VSOMEIP_SD_OPTION_H__
#define __VSOMEIP_SD_OPTION_H__

#include <vsomeip/serializable.h>
#include <vsomeip/types.h>

namespace vsomeip {

namespace sd {

enum class OptionType : uint8_t {
	CONFIGURATION = 0x1,
	LOAD_BALANCING = 0x2,
	PROTECTION = 0x3,
	IP4_ENDPOINT = 0x4,
	IP6_ENDPOINT = 0x6,
	UNKNOWN = 0xFF
};

class Option : virtual public Serializable {
public:
	virtual ~Option() {};
	virtual bool operator==(const Option& a_option) const = 0;

	virtual uint16_t getLength() const = 0;
	virtual OptionType getType() const = 0;
};

} // namespace sd

} // namespace vsomeip

#endif // __VSOMEIP_SD_OPTIONBASE_H__
