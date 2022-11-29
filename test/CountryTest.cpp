
#include "gtest/gtest.h"
#include "../src/Country.h"

TEST(CountryTest, addHolidays){
    time_t now = time(0);
    tm *day = localtime(&now);

    tm holiday = *day;

    Country myCountry;
    myCountry.addHolidays(holiday);

EXPECT_TRUE(myCountry.existHoliday(holiday));
}