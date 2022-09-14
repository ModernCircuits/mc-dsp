// SPDX-License-Identifier: BSL-1.0

#include <mc/dsp/units/frequency.hpp>

#include <catch2/catch_approx.hpp>
#include <catch2/catch_template_test_macros.hpp>

namespace dsp = mc::dsp;

TEMPLATE_TEST_CASE("dsp/units: Frequency", "[dsp][units]", float, double)  // NOLINT
{
    using T = TestType;

    static constexpr auto const zero = dsp::Hertz<T>{0};
    REQUIRE(zero.count() == T(0));
    REQUIRE(dsp::Kilohertz<T>{zero}.count() == T(0));

    static constexpr auto const kilo = dsp::Hertz<T>{1'000};
    REQUIRE(kilo.count() == T(1'000));
    REQUIRE(dsp::frequencyCast<dsp::Kilohertz<T>>(kilo).count() == T(1));
}
