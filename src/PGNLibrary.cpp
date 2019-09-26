#include <vector>
#include <algorithm>

#include <nmea2000/PGNLibrary.hpp>

using namespace std;
using namespace nmea2000;

static bool comparePGN(PGNInfo const& a, PGNInfo const& b) {
    return a.pgn < b.pgn;
}

PGNLibrary::PGNLibrary(vector<PGNInfo> const& pgns) {
    vector<PGNInfo> sorted_pgns(pgns);
    sort(sorted_pgns.begin(), sorted_pgns.end(), comparePGN);
    m_pgns = move(sorted_pgns);
}

PGNInfo const* PGNLibrary::find(uint32_t pgn) const {
    PGNInfo info;
    info.pgn = pgn;

    auto it = lower_bound(m_pgns.begin(), m_pgns.end(), info, comparePGN);
    if (it == m_pgns.end() || it->pgn != pgn) {
        return nullptr;
    }

    return &(*it);
}

PGNInfo const& PGNLibrary::get(uint32_t pgn) const {
    auto info = find(pgn);
    if (info) {
        return *info;
    }
    else {
        throw invalid_argument("unknown PGN");
    }
}

bool PGNLibrary::isKnown(uint32_t pgn) const {
    return find(pgn);
}

bool PGNLibrary::isFastPacket(uint32_t pgn) const {
    return get(pgn).size > 8;
}
