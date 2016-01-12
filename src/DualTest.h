#include <cppunit/extensions/HelperMacros.h>
#include "Dual.h"

#ifndef DUAL_TEST_INCLUDED
#define DUAL_TEST_INCLUDED

namespace dual {
    class DualTest : public CPPUNIT_NS::TestFixture {
    public:
        CPPUNIT_TEST_SUITE(DualTest);
        CPPUNIT_TEST(testConstructor);
        CPPUNIT_TEST(testOperatorPlus);
        CPPUNIT_TEST_SUITE_END();
        
    public:
        void setUp();
        void testConstructor();
        void testOperatorPlus();
        void tearDown();
    };


} // namespace dual {




#endif

