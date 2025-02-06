mydir=$(dirname $0)
echo $mydir

rm -r $mydir/out/*

cd $mydir/test

for i in $(find . -type f -name '*cpp') ; do 
	bn=$(basename $i .cpp)
	g++ -g -rdynamic -I ../include/ $i ../src/libstat.cpp  -o ../out/$bn
done
