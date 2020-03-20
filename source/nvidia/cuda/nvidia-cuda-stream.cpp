/*
 * Modern effects for a modern Streamer
 * Copyright (C) 2020 Michael Fabian Dirks
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#include "nvidia-cuda-stream.hpp"
#include <stdexcept>

nvidia::cuda::stream::stream(std::shared_ptr<::nvidia::cuda::cuda> cuda) : _cuda(cuda)
{
	nvidia::cuda::cu_result res = _cuda->cuStreamCreate(&_stream, 0);
	switch (res) {
	case nvidia::cuda::cu_result::SUCCESS:
		break;
	default:
		throw std::runtime_error("Failed to create CUstream object.");
	}
}

nvidia::cuda::stream::~stream()
{
	_cuda->cuStreamDestroy(_stream);
}

::nvidia::cuda::cu_stream_t nvidia::cuda::stream::get()
{
	return _stream;
}
