// SPDX-License-Identifier: BSL-1.0

#pragma once

namespace mc {
namespace dsp {

template<typename T>
constexpr Decibel<T>::Decibel(T v) noexcept : _count{v}
{}

template<typename T>
constexpr auto Decibel<T>::count() const noexcept -> T
{
    return _count;
}

template<typename T>
constexpr auto toDecibel(T gain) noexcept -> Decibel<T>
{
    return Decibel<T>{log10(gain) * T(20)};
}

template<typename T>
constexpr auto toGain(Decibel<T> dB) noexcept -> T
{
    return pow(T(10), dB.count() * T(0.05));
}

}  // namespace dsp
}  // namespace mc
