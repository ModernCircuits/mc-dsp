// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

#include <mc/dsp/spacial/stereo_frame.hpp>

namespace mc {
namespace dsp {
template<typename T>
struct StereoWidth
{
    using SampleType = T;

    constexpr StereoWidth() noexcept = default;
    explicit constexpr StereoWidth(T initialWidth) noexcept;

    constexpr auto width(T newWidth) noexcept -> void;
    MC_NODISCARD constexpr auto width() const noexcept -> T;

    MC_NODISCARD constexpr auto operator()(StereoFrame<T> in) -> StereoFrame<T>;

private:
    T _width{1.0};
    T _coeff{_width * T(0.5)};
};
}  // namespace dsp
}  // namespace mc

#include "stereo_width.cpp"  // NOLINT
