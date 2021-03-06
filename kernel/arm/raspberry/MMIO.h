/*
 * Copyright (C) 2015 Niek Linnenbank
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __ARM_MMIO_H
#define __ARM_MMIO_H

#include <Types.h>

class MMIO
{
public:

    /**
     * write to MMIO register
     */
    static inline void write(u32 reg, u32 data)
    {
	u32 *ptr = (u32 *) reg;
	asm volatile("str %[data], [%[reg]]"
		     : : [reg]"r"(ptr), [data]"r"(data));
    }

    /**
     * read from MMIO register
     */
    static inline u32 read(u32 reg)
    {
	u32 *ptr = (u32 *) reg;
	u32 data;
	asm volatile("ldr %[data], [%[reg]]"
		     : [data]"=r"(data) : [reg]"r"(ptr));
	return data;
    }
};

#endif /* __ARM_MMIO_H */
