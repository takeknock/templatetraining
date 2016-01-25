#!/bin/sh

for filename in `find . -name "*.cpp"`
do
 dirname=`dirname $filename`
 basename=`basename $filename .cpp`
 echo "$filename --> $dirname/$basename.pdf"
 echo "enscript --highlight=cpp --color --fancy-header --line-numbers --landscape --columns=1 -o $dirname/${basename}_c.ps $filename"
 enscript --highlight=cpp --color --fancy-header --line-numbers --landscape --columns=2 -o $dirname/${basename}_c.ps $filename
 echo "ps2pdf $dirname/${basename}_c.ps"
 ps2pdf $dirname/${basename}_c.ps
 rm $dirname/${basename}_c.ps
 if [ -e $dirname/pdf ] ; then
     :
 else
     mkdir pdf
 fi

 mv $dirname/${basename}_c.pdf $dirname/pdf/${basename}_c.pdf
done

for filename in `find . -name "*.h"`
do
 dirname=`dirname $filename`
 basename=`basename $filename .h`
 echo "$filename --> $dirname/$basename.ps"
 enscript --highlight=cpp --color --fancy-header --line-numbers --landscape --columns=2 -o $dirname/${basename}_h.ps $filename
 echo "ps2pdf $dirname/${basename}_h.ps"
 ps2pdf $dirname/${basename}_h.ps
 rm $dirname/${basename}_h.ps
 if [ -e $dirname/pdf ] ; then
     :
 else
     mkdir pdf
 fi
 mv $dirname/${basename}_h.pdf $dirname/pdf/${basename}_h.pdf
done
