DUMMYFILE="sql/dummyuser.sql"

cat > $DUMMYFILE << EOF
/*
 * dummyuser.sql
 *
 * SQL for maintaining the duckrun database
 * 
 * Author: Zex
 */

use duckrun;

EOF

total=0
#for i in {0..100}; do
while [ 100 -gt $total ] ;do

a=`tr -cd '[:digit:]' < /dev/urandom | fold -w13|head -c1`
#b=`expr substr $a 3 1`
#c=`</dev/urandom tr -dc '12345#$%qwertQWERTasdfgASDFGzxcvbZXCVB' | head -c$a`
c=`</dev/urandom tr -dc '12345_qwertQWE_RTasdfgASDFGzxcvbZXCVB' | head -c$a`

a=`tr -cd '[:digit:]' < /dev/urandom | fold -w13|head -c1`
d=`</dev/urandom tr -cd '[:alnum:]' | head -c$a`

y=`tr -cd '[:digit:]' < /dev/urandom | fold -w13|head -c8`

[ -z $a ] && continue;
if [ -z $c ] || [ `expr length $c` -lt 5 ] ;then continue; fi
if [ -z $d ] || [ `expr length $d` -lt 5 ] ;then continue; fi
[ -z $y ] && continue;

if [ ! -z $total ] && [ 0 -eq  $(($total%7)) ] ;then addr=$c@$d.com;
elif [ ! -z $total ] && [ 0 -eq $(($total%3)) ] ;then addr=$c@$d.net;
elif [ ! -z $total ] && [ 0 -eq $(($total%5)) ] ;then addr=$c@$d.info;
else addr=$c@$d.org; fi
#([ 0 -eq $(($total%2)) ] && addr=$c@$d.org)

echo "[$total] $addr"

cat >> $DUMMYFILE << EOF
insert into duckinfo value ("$addr", $y, $a);
EOF

total=$(($total+1))

done

