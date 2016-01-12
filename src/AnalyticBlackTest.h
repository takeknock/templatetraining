#pragma once

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/CompilerOutputter.h>

class AnalyticBlackTest : public CPPUNIT_NS::TestFixture {
public:
    CPPUNIT_TEST_SUITE(AnalyticBlackTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testCalculatePrice);
    CPPUNIT_TEST(testCalculateD1);
    CPPUNIT_TEST(testCalculateD2);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void testConstructor();
    void testCalculatePrice();
    void testCalculateD1();
    void testCalculateD2();
    void tearDown();

};
    
