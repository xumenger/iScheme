# bash make-test.sh

g++ testUtils.cpp -o testUtils.out
g++ testTokenize.cpp -o testTokenize.out
./testUtils.out
rm testUtils.out
./testTokenize.out
rm testTokenize.out
