#ifndef NMEA2000_PGNLIBRARY_HPP
#define NMEA2000_PGNLIBRARY_HPP

#include <map>
#include <nmea2000/PGNInfo.hpp>

namespace nmea2000 {
    /** Information about known PGNs
     */
    class PGNLibrary {
        std::vector<PGNInfo> m_pgns;

    public:
        PGNLibrary();

        PGNLibrary(std::vector<PGNInfo> const& pgns);

        /** Whether this library is empty */
        bool empty() const;

        /** Number of PGNs definitions in this library */
        size_t size() const;

        /** Return info for this PGN */
        PGNInfo const* find(uint32_t pgn) const;

        /** Return info for this PGN */
        PGNInfo const& get(uint32_t pgn) const;

        /** Tests whether we know about this PGN */
        bool isKnown(uint32_t pgn) const;

        /** Tests whether this PGN uses fast packet */
        bool isFastPacket(uint32_t pgn) const;
    };
}

#endif