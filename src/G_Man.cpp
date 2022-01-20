// ---------------------------------------------------------------------
// CFXS Framework CNC Module <https://github.com/CFXS/CFXS-CNC>
// Copyright (C) 2022 | CFXS / Rihards Veips
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>
// ---------------------------------------------------------------------
// [CFXS] //
#include <CFXS/CNC/G_Man.hpp>
#include <CFXS/Base/Debug.hpp>

namespace CFXS::CNC {

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    G_Man::G_Man() {
        CFXS_printf("Initialize G-Code processor [0x%p]\n", this);
    }

    /// Get line number of the current data stream
    __always_inline int G_Man::GetCurrentLineNumber() const {
        return m_CurrentLineNumber;
    }

    ///////////////////////////////////////////////////////////////////////
    // Parser

    /// Process terminated or non-terminated block off G-Code data.
    /// Push fully decoded commands to execution queue.
    /// \param charBlock block of chars to parse.
    /// \param len length of charBlock.
    /// \returns Status of parser after taking this data block
    G_Man::ParseStatus G_Man::ProcessCommandDataBlock(const char* charBlock, size_t len) {
        size_t readPos = len;
        while (readPos < len) {
            auto c = charBlock[readPos];

            switch (m_ParserState) {
                case ParserState::
            }
        }

        return ParseStatus::OK;
    }

} // namespace CFXS::CNC