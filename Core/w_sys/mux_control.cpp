/*
 * mux_control.cpp
 *
 *  Created on: Apr 3, 2025
 *      Author: wilson
 */

#include <cstdint>



namespace w_sys
{
	static constexpr uint8_t MUX_CONTROL_STATE_INIT = 0x00U;
	static constexpr uint8_t MUX_CONTROL_STATE_GET_COMMAND = 0x01U;
	static constexpr uint8_t MUX_CONTROL_STATE_SET_MUX = 0x02U;
	static constexpr uint8_t MUX_CONTROL_STATE_WAIT = 0x04U;

	static uint8_t state = MUX_CONTROL_STATE_INIT;

	void mux_control_run()
	{
		switch(state)
		{
			case MUX_CONTROL_STATE_INIT:
			{
				break;
			}
			case MUX_CONTROL_STATE_GET_COMMAND:
			{
				break;
			}
			case MUX_CONTROL_STATE_SET_MUX:
			{
				break;
			}
			case MUX_CONTROL_STATE_WAIT:
			{
				break;
			}
			default:
			{
				break;
			}
		}
	}
}
