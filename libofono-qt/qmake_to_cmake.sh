#!/bin/sh
for file in `find . -name '*.pr?'`; do
   dos2unix $file
   filetype=`echo $file |sed -e 's/.*\.\(pr.\)/\1/'`
   path=`dirname $file`
   base=`basename $file`
   if [ -e "$path/CMakeLists.txt" -a "$filetype" = "pro" ]; then
      qmake2cmake.ruby $file $path/CMakeLists-$base.txt
   else
      qmake2cmake.ruby $file
   fi
done
