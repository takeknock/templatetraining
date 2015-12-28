#include <cppunit/extensions/HelperMacros.h>
#include "DualTest.h"

namespace dual {
    CPPUNIT_TEST_REGISTRATION(DualTest);
    void DualTest::setUp()
    {
        return;
    }

    void DualTest::testConstructor()
    {
        CPPUNIT_ASSERT(true);
        return;
    }

    void DualTest::tearDown()
    {
         return;
    }

} // namespace dual

