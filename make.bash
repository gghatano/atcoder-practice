target=$1

echo ""
echo "=== compile ==="
g++ -std=c++11 -o $target $target.cpp 2>/tmp/cmperr.txt
echo ""
echo ""
echo "=== cmperr === "
cat /tmp/cmperr.txt
echo ""
echo ""
echo "=== execute ==="
./${target} < ${target}.txt 1> /tmp/stdout.txt 2>/tmp/stderr.txt
echo ""
echo ""
echo "=== stderr === "
cat /tmp/stderr.txt
echo ""
echo ""
echo "=== stdout === "
cat /tmp/stdout.txt

rm ${target}
