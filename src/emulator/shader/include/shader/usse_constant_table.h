// Vita3K emulator project
// Copyright (C) 2018 Vita3K team
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#pragma once

#include <cstdint>

namespace shader::usse {
// Thanks motoharu for original reversing work.
static const std::uint32_t NaN_raw = 0x7FFF7FFF;
static const std::uint32_t neg_NaN_raw = 0xFFFFFFFF;

static const float NaN = *reinterpret_cast<const float *>(&NaN_raw);
static const float neg_NaN = *reinterpret_cast<const float *>(&neg_NaN_raw);

constexpr std::uint32_t f32_constant_table_bank_0_raw[] = {
    0x00000000,
    0x00000000,
    0x3F800000,
    0x3F800000,
    0x40000000,
    0x41000000,
    0x42000000,
    0x43000000,
    0x44000000,
    0x45000000,
    0x46000000,
    0x47000000,
    0x3F000000,
    0x3E000000,
    0x3D000000,
    0x3C000000,
    0x3B000000,
    0x3A000000,
    0x39000000,
    0x38000000,
    0x402DF854,
    0x3FB504F3,
    0x40490FDB,
    0x3F490FDB,
    0x40C90FDB,
    0x41C90FDB,
    0x37800000,
    0x37800080,
    0x35D00D01, // sin(0.5) - taylor 4th term
    0x39888889, // sin(0.5) - taylor 3rd term
    0x3CAAAAAB, // sin(0.5) - taylor 2nd term
    0x3F000000, // sin(0.5) - taylor 1st term
    0x00000000,
    0x00000000,
    0x3C003C00,
    0x44004000,
    0x54005000,
    0x64006000,
    0x74007000,
    0x34003800,
    0x24002800,
    0x14001800,
    0x04000800,
    0x35E2416F,
    0x39A83DA8,
    0x3E484248,
    0x4A484648,
    0x00000000,
    0x00000000,
    0x30002555,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0x7FFF7FFF,
    0x7FFF7FFF,
    0x7FFF7FFF,
    0x7FFF7FFF
};

constexpr std::uint32_t f32_constant_table_bank_1_raw[] = {
    0x00000000,
    0x3F800000,
    0x00000000,
    0x3F800000,
    0x40800000,
    0x41800000,
    0x42800000,
    0x43800000,
    0x44800000,
    0x45800000,
    0x46800000,
    0x47800000,
    0x3E800000,
    0x3D800000,
    0x3C800000,
    0x3B800000,
    0x3A800000,
    0x39800000,
    0x38800000,
    0x37800000,
    0x3EBC5AB2,
    0x3F3504F3,
    0x3FC90FDB,
    0x3EC90FDB,
    0x41490FDB,
    0x00000000,
    0x38000000,
    0x38000100,
    0x37B60B61,
    0x3B2AAAAB,
    0x3E000000,
    0x3F800000,
    0x3C000000,
    0x00000000,
    0x3C003C00,
    0x4C004800,
    0x5C005800,
    0x6C006800,
    0x00007800,
    0x2C003000,
    0x1C002000,
    0x0C001000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x36483A48,
    0x00004E48,
    0x00000000,
    0x19550C44,
    0x3C003800,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000
};

static const float f16_constant_table_bank0[] = {
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    -35456.0f,
    7.5519e-05f,
    0.00047946f,
    0.00047946f,
    0.00047946f,
    0.00047946f,
    0.0f,
    7.6294e-06f,
    0.00030541f,
    -0.0001384f,
    -0.052094f,
    0.0f,
    0.0f,
    0.0f,
    1.0f,
    2.0f,
    32.0f,
    512.0f,
    8192.0f,
    0.5f,
    0.03125f,
    0.0019531f,
    0.00012207f,
    2.7168f,
    1.4141f,
    3.1406f,
    6.2813f,
    0.0f,
    0.0f,
    0.020828f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    neg_NaN,
    neg_NaN,
    neg_NaN,
    neg_NaN,
    NaN,
    NaN,
    NaN,
    NaN
};

static const float f16_constant_table_bank1[] = {
    0.0f,
    0.0f,
    1.875f,
    1.875f,
    2.0f,
    2.5f,
    3.0f,
    3.5f,
    4.0f,
    5.0f,
    6.0f,
    7.0f,
    1.75f,
    1.5f,
    1.25f,
    1.0f,
    0.875f,
    0.75f,
    0.625f,
    0.5f,
    2.0879f,
    1.9268f,
    2.1426f,
    1.8213f,
    2.3926f,
    2.8926f,
    0.46875f,
    0.46875f,
    0.36328f,
    0.69141f,
    1.166f,
    1.75f,
    0.0f,
    0.0f,
    1.0f,
    4.0f,
    64.0f,
    1024.0f,
    16384.0f,
    0.25f,
    0.015625f,
    0.00097656f,
    6.1035e-05f,
    0.36768f,
    0.70703f,
    1.5703f,
    12.563f,
    0.0f,
    0.0f,
    0.125f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    neg_NaN,
    neg_NaN,
    neg_NaN,
    neg_NaN,
    NaN,
    NaN,
    NaN,
    NaN
};

static const float f16_constant_table_bank2[] = {
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    214.25f,
    7.5519e-05f,
    0.00047946f,
    0.00047946f,
    0.00047946f,
    0.0f,
    0.0f,
    1.5259e-05f,
    0.00022519f,
    -0.052094f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    1.0f,
    8.0f,
    128.0f,
    2048.0f,
    32768.0f,
    0.125f,
    0.0078125f,
    0.00048828f,
    0.0f,
    0.0f,
    0.0f,
    0.78516f,
    25.125f,
    0.0f,
    0.00026035f,
    0.5f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f
};

static const float f16_constant_table_bank3[] = {
    0.0f,
    1.875f,
    0.0f,
    1.875f,
    2.25f,
    2.75f,
    3.25f,
    3.75f,
    4.5f,
    5.5f,
    6.5f,
    7.5f,
    1.625f,
    1.375f,
    1.125f,
    0.9375f,
    0.8125f,
    0.6875f,
    0.5625f,
    0.46875f,
    1.6836f,
    1.8018f,
    1.9463f,
    1.6963f,
    2.6426f,
    0.0f,
    0.5f,
    0.5f,
    0.48193f,
    0.89551f,
    1.5f,
    1.875f,
    1.0f,
    0.0f,
    1.0f,
    16.0f,
    256.0f,
    4096.0f,
    0.0f,
    0.0625f,
    0.0039063f,
    0.00024414f,
    0.0f,
    0.0f,
    0.0f,
    0.39258f,
    0.0f,
    0.0f,
    0.0026035f,
    1.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f
};
}; // namespace shader::usse
