target=$1


echo "=== compile ==="
g++ -std=c++11 -o $target $target.cpp

echo "=== execute ==="
./${target} < ${target}.txt 1> stdout.txt 2>stderr.txt

echo ""
echo "=== stderr === "
cat stderr.txt
echo ""
echo ""
echo "=== stdout === "
cat stdout.txt

rm ${target}
