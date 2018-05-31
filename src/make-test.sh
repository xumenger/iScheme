# bash make-test.sh

g++ testUtils.cpp Utils.cpp -o testUtils.out
g++ testTokenize.cpp Utils.cpp Tokenize.cpp -o testTokenize.out
./testUtils.out
rm testUtils.out
./testTokenize.out
rm testTokenize.out
