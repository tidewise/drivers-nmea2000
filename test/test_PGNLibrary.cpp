#include <gtest/gtest.h>
#include <nmea2000/PGNLibrary.hpp>

using namespace nmea2000;

struct PGNLibraryTest : public ::testing::Test {
    void assertEqual(std::vector<PGNInfo> const& expected, PGNLibrary const& lib) const
    {
        ASSERT_EQ(expected.size(), lib.size());

        for (auto const& e : expected) {
            auto& pgn = lib.get(e.pgn);
            EXPECT_EQ(e.size, pgn.size);
        }
    }
};

TEST_F(PGNLibraryTest, it_augments_with_empty_library)
{
    PGNLibrary lib{{{12345, 8}}};
    lib.augment({});
    assertEqual({{12345, 8}}, lib);
}

TEST_F(PGNLibraryTest, it_stays_sorted_when_augmented_with_sorted_vector)
{
    PGNLibrary lib{
        {{12345, 8}, {12347, 12}}
    };
    lib.augment({
        {12348, 8},
        {12346, 6},
        {12344, 4}
    });

    assertEqual({{12344, 4}, {12345, 8}, {12346, 6}, {12347, 12}, {12348, 8}}, lib);
}

TEST_F(PGNLibraryTest, it_does_not_augment_with_duplicates)
{
    PGNLibrary lib{
        {{12345, 8}, {12346, 7}}
    };
    lib.augment({
        {12345, 8},
        {12346, 7}
    });
    assertEqual({{12345, 8}, {12346, 7}}, lib);
}