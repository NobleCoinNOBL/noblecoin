Copyright (c) 2014 NobleCoin Developers (Packaged for Version 1.1 2014)
Distributed under the MIT/X11 software license, see the accompanying file COPYING or http://www.opensource.org/licenses/mit-license.php.

Compiling/running noblecoind unit tests
------------------------------------

noblecoind unit tests are in the `src/test/` directory; they
use the Boost::Test unit-testing framework.

To compile and run the tests:

	cd src
	make -f makefile.unix test_noblecoin  # Replace makefile.unix if you're not on unix
	./test_noblecoin   # Runs the unit tests

If all tests succeed the last line of output will be:
`*** No errors detected`

To add more tests, add `BOOST_AUTO_TEST_CASE` functions to the existing
.cpp files in the test/ directory or add new .cpp files that
implement new BOOST_AUTO_TEST_SUITE sections (the makefiles are
set up to add test/*.cpp to test_noblecoin automatically).


Compiling/running Noblecoin-Qt unit tests
---------------------------------------

Noblecoin-Qt unit tests are in the src/qt/test/ directory; they
use the Qt unit-testing framework.

To compile and run the tests:

	qmake noblecoin-qt.pro NOBLECOIN_QT_TEST=1
	make
	./noblecoin-qt_test

To add more tests, add them to the `src/qt/test/` directory,
the `src/qt/test/test_main.cpp` file, and Noblecoin-qt.pro.
