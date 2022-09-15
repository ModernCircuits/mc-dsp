// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/config.hpp>

#include <mc/core/cstdint.hpp>
#include <mc/core/format.hpp>

namespace mc {
namespace dsp {

/// \class Note "mc/dsp/music/note.hpp" <mc/dsp/music/note.hpp>
/// \brief A music note.
/// \example note.cpp
/// \ingroup mc-dsp-music
struct Note
{
    constexpr Note() = default;
    explicit constexpr Note(uint8_t note) noexcept;

    [[nodiscard]] explicit constexpr operator uint8_t() const noexcept;

    [[nodiscard]] constexpr auto operator++() noexcept -> Note&;
    [[nodiscard]] constexpr auto operator++(int) noexcept -> Note;

    [[nodiscard]] constexpr auto operator--() noexcept -> Note&;
    [[nodiscard]] constexpr auto operator--(int) noexcept -> Note;

private:
    uint8_t _note{0};
};

[[nodiscard]] constexpr auto operator==(Note lhs, Note rhs) noexcept -> bool;
[[nodiscard]] constexpr auto operator!=(Note lhs, Note rhs) noexcept -> bool;

}  // namespace dsp
}  // namespace mc

template<>
struct fmt::formatter<mc::dsp::Note>
{
    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin());

    template<typename FormatContext>
    auto format(mc::dsp::Note const& note, FormatContext& ctx) const -> decltype(ctx.out());

    // Presentation format: 'n' - number, 'h' - human.
    char presentation = 'n';
};

#include "note.cpp"  // NOLINT
