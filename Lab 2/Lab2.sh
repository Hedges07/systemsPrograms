#!/bin/bash
targetDir="."
argv=($*)
cd $targetDir
for var in $@
do
list=$(find -name "*$var")
echo  $list
done
tar -cf archive.tar *
