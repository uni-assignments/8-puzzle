EXEC=$1
ALG=$2

for i in {1..32..1}; do
  testname=$(printf "%01d" $i)
  TMP_OUT=$($EXEC $ALG $(cat casos_teste/$testname.in) DONTPRINT RECORD) 
  
  if [[ "$(cat casos_teste/$testname.out)" != "$TMP_OUT" ]]; then
    echo "Test $testname failed, Expected $(cat casos_teste/$testname.out), got $TMP_OUT"
  else
    echo "Test $testname passed"
  fi
done