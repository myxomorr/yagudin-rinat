touch test.txt
echo "Тестовая строка, для проверки работоспособности программы." > test.txt
touch result.txt
./bin/main.p
cat result.txt
rm test.txt
rm result.txt