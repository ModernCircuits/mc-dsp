// SPDX-License-Identifier: BSL-1.0

#include <mc/dsp/units.hpp>

#include <catch2/catch_approx.hpp>
#include <catch2/catch_template_test_macros.hpp>

namespace dsp = mc::dsp;

TEMPLATE_TEST_CASE("dsp/units: toDecibel", "[dsp][units]", float, double)
{
    using T = TestType;
    REQUIRE(dsp::toDecibel(T(1.0)).count() == Catch::Approx(T(0)));
    REQUIRE(dsp::toDecibel(T(0.5)).count() == Catch::Approx(T(-6.02059)));
    REQUIRE(dsp::toDecibel(T(0.25)).count() == Catch::Approx(T(-12.04119)));
}

TEMPLATE_TEST_CASE("dsp/units: toGain", "[dsp][units]", float, double)
{
    using T = TestType;
    REQUIRE(dsp::toGain(dsp::Decibel{T(0)}) == Catch::Approx(T(1.0)));
    REQUIRE(dsp::toGain(dsp::Decibel{T(-6.02059)}) == Catch::Approx(T(0.5)));
    REQUIRE(dsp::toGain(dsp::Decibel{T(-12.04119)}) == Catch::Approx(T(0.25)));
}
