/*
 * multiplexer.h
 *
 *  Created on: Apr 3, 2025
 *      Author: wilson
 */

#include <cstdint>
#include "../etl/string.h"

#ifndef W_DRV_MULTIPLEXER_H_
#define W_DRV_MULTIPLEXER_H_

class multiplexer
{
	public:

		static constexpr uint8_t ID_STR_LEN = 8U;
		etl::string<ID_STR_LEN> device_name;

		// device model name
		// operating voltages
		// abs max voltage
		//
		multiplexer();
		virtual ~multiplexer();
};

#endif /* W_DRV_MULTIPLEXER_H_ */
