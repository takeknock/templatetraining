cat templateTest.h | sed -e 's/TimeGrid/'$1'/g' > $1"Test.h"
cat templateTest.cpp | sed -e 's/TimeGrid/'$1'/g' > $1"Test.cpp"

#mv $1"Test.h" "../MonteCarloTest/"
#mv $1"Test.cpp" "../MonteCarloTest/"



