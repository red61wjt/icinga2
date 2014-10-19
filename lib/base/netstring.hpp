/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012-2014 Icinga Development Team (http://www.icinga.org)    *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software Foundation     *
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.             *
 ******************************************************************************/

#ifndef NETSTRING_H
#define NETSTRING_H

#include "base/i2-base.hpp"
#include "base/string.hpp"
#include "base/stream.hpp"

namespace icinga
{

struct NetStringContext
{
	NetStringContext(void)
		: HeaderLength(0), Data(NULL), DataLength(0)
	{ }

	~NetStringContext(void)
	{
		delete [] Data;
	}

	char Header[16];
	size_t HeaderLength;

	char *Data;
	size_t DataLength;
};

/**
 * Helper functions for reading/writing messages in the netstring format.
 *
 * @see http://cr.yp.to/proto/netstrings.txt
 *
 * @ingroup base
 */
class I2_BASE_API NetString
{
public:
	static bool ReadStringFromStream(const Stream::Ptr& stream, String *message, NetStringContext& context);
	static void WriteStringToStream(const Stream::Ptr& stream, const String& message);

private:
	NetString(void);
};

}

#endif /* NETSTRING_H */
